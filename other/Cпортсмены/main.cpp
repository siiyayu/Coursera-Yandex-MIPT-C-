#include <iostream>
#include <list>
#include <algorithm>
#include <vector>



using namespace std;

//class FootballTeam {
//public:
//    void AddPlayer(int number, int pos) {
//        auto it = find(team.begin(), team.end(), pos);
//        team.insert(it, number);
//    }
//    void PrintPlayers(ostream& os) {
//        for (auto& item : team) {
//            os << item << " ";
//        }
//    }
//private:
//    list<int> team;
//};
//
//int main() {
//    int n;
//    cin >> n;
//    int pos, number;
//    FootballTeam ft;
//    for (int i = 0; i < n; i++) {
//        cin >> number >> pos;
//        ft.AddPlayer(number, pos);
//    }
//    ft.PrintPlayers(cout);
//
//    return 0;
//}

int main() {
    const int MAX_ATHLETES = 100'000;
    using Position = list<int>::iterator;
    list<int> row;
    vector<Position> athlete_pos(MAX_ATHLETES + 1, row.end());
    int n, athlete, next_athlete;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> athlete ;
        cin >> next_athlete;
        athlete_pos[athlete] = row.insert(athlete_pos[next_athlete], athlete);
    }
    for (int item : row) {
        cout << item << " ";
    }
    return 0;
}