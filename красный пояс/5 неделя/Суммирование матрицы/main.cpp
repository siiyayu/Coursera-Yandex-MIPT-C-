#include "test_runner.h"
#include "profile.h"

#include <vector>
#include <future>

using namespace std;


template <typename Iterator>
struct IteratorRange{
    Iterator first, last;

    Iterator begin() const {
        return first;
    }
    Iterator end() const {
        return last;
    }
    size_t size() const{
        return last - first;
    }
};

template <typename Iterator>
class Paginator {
public:
    Paginator(Iterator begin, Iterator end, size_t page_size){
        for (auto it = begin; it != end; it += page_size) {
            if (end - it >= page_size) {
                pages.push_back({it, it + page_size});
            }
            else {
                pages.push_back({it, end});
                break;
            }
        }
//        for (size_t left = distance(begin, end); left > 0; ) {
//            size_t current_page_size = min(page_size, left);
//            Iterator current_page_end = next(begin, current_page_size);
//            pages.push_back({begin, current_page_end});
//
//            left -= current_page_size;
//            begin = current_page_end;
//        }
    }

    auto begin() {
        return pages.begin();
    }
    auto end() {
        return pages.end();
    }

    const size_t size() const {
        return pages.size(); ////
    }
private:
    vector<IteratorRange<Iterator>> pages;
};

template <typename C>
auto Paginate(C& c, size_t page_size) {
    return Paginator(c.begin(), c.end(), page_size);
}

template <typename ContainerOfVectors >
void GenerateSingleThread (
        ContainerOfVectors& result,
        size_t first_row,
        size_t column_size
) {
    for (auto& row : result) {
        row.reserve(column_size);
        for (size_t column = 0; column < column_size; ++column) {
        row.push_back(first_row^column);
    }
    ++first_row ;
    }
}

vector <vector <int>> GenerateSingleThread (size_t size) {
    vector<vector<int>> result(size);
    GenerateSingleThread(result , 0, size);
    return result;
}

vector <vector <int>> GenerateMultiThread (
        size_t size , size_t page_size
) {
    vector<vector<int>> result(size);
    vector<future<void>> futures;
    size_t first_row = 0;
    for (auto page : Paginate(result, page_size)) {
        futures.push_back(
                async([page, first_row, size] {
                    GenerateSingleThread(page, first_row, size);
                })
        );
        first_row += page_size;
    }
    return result;
}

template <typename ContainerOfVectors>
int64_t SumSingleThread(const ContainerOfVectors& matrix) {
    int64_t sum = 0;
    for (const auto& row : matrix) {
        for (auto item : row) {
                sum += item;
        }
    }
    return sum;
}

int64_t CalculateMatrixSum(
        const vector<vector<int>>& matrix
) {
    vector<future<int64_t>> futures;
    int64_t sum = 0;
    for (auto page : Paginate(matrix, 2000)) {
        futures.push_back(async([page] { return SumSingleThread(page); }));
    }
    for (auto& item : futures) {
        sum += item.get();
    }
    return sum;
}

int main () {
    LOG_DURATION ("Total");
    const size_t matrix_size = 7000;
    vector <vector <int>> matrix;
//    {
//        LOG_DURATION ("Single thread generation");
//        matrix = GenerateSingleThread(matrix_size);
//    }
    {
        LOG_DURATION ("Multi thread generation");
        matrix = GenerateMultiThread(matrix_size, 2000);
    }
//    {
//        LOG_DURATION ("Single thread sum");
//        cout << SumSingleThread (matrix) << endl;
//    }
    {
        LOG_DURATION ("Multi thread sum");
        cout << CalculateMatrixSum (matrix) << endl;
    }
}