#include "stats.h"
#include <string>
#include <sstream>

void Stats::AddMethod(string_view method) {
    if (Check(methods, method)) {
        method_stats[method]++;
    } else {
        method_stats["UNKNOWN"]++;
    }
}
void Stats::AddUri(string_view uri) {
    if (Check(uries, uri)) {
        uri_stats[uri]++;
    } else {
        uri_stats["unknown"]++;
    }
}
const map<string_view, int>& Stats::GetMethodStats() const {
    return method_stats;
}
const map<string_view, int>& Stats::GetUriStats() const {
    return uri_stats;
}
bool Stats::Check(set<string_view> check_list, string_view to_check) {
    if (check_list.count(to_check) == 0) {
        return false;
    } else {
        return true;
    }
}

HttpRequest ParseRequest(string_view line) {
//    auto pos = line.find_first_of(" ", 0);
//    string_view method = line.substr(0, pos - 1);
//    line.remove_prefix(pos + 1);
//    pos = line.find_first_of(" ", 0);
//    string_view ori = line.substr(0, pos - 1);
//    //line.remove_prefix(pos + 2);
//    string_view protocol = "HTTP/1.1";
    string s(line);
    stringstream ss(s);
    while (ss.peek() == ' ') {
        ss.ignore(1);
    }
    static string method, ori, protocol;
    getline(ss, method, ' ');
    getline(ss, ori, ' ');
    getline(ss, protocol);
    HttpRequest result = {method, ori, protocol};
    return result;
}




//
//#include "stats.h"
//
//void Stats::AddMethod(string_view method) {
//    methods.Add(method);
//}
//
//void Stats::AddUri(string_view uri) {
//    uris.Add(uri);
//}
//
//const map<string_view, int>& Stats::GetMethodStats() const {
//    return methods.GetValues();
//}
//
//const map<string_view, int>& Stats::GetUriStats() const {
//    return uris.GetValues();
//}
//
//void LeftStrip(string_view& sv) {
//    while (!sv.empty() && isspace(sv[0])) {
//        sv.remove_prefix(1);
//    }
//}
//
//string_view ReadToken(string_view& sv) {
//    LeftStrip(sv);
//
//    auto pos = sv.find(' ');
//    auto result = sv.substr(0, pos);
//    sv.remove_prefix(pos != sv.npos ? pos : sv.size());
//    return result;
//}
//
//HttpRequest ParseRequest(string_view line) {
//    auto method = ReadToken(line);
//    auto uri = ReadToken(line);
//    return {method, uri, ReadToken(line)};
//}
//
//void StatPiece::Add(string_view value) {
//    if (auto it = counts.find(value); it != counts.end()) {
//        ++it->second;
//    } else {
//        ++counts[default_key];
//    }
//}
