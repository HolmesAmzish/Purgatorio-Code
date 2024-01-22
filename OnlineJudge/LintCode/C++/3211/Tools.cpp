#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>

using namespace std;

void splitByFind(string s, const string &split, vector<string> &res) {
    int pos;
    while(true) {
        pos = s.find(split);
        if (pos == -1) {
            res.push_back(s);
            break;
        }
        res.push_back(s.substr(0, pos));
        s.erase(s.begin(), s.begin() + pos + split.size());
    }
}

void splitByFind(string &s, const char split_char, vector<string> &res) {
    string split_string; split_string += split_char;
    splitByFind(s, split_string, res);
}

vector<string> splitByFind(string &s, const char split_char) {
    vector<string> res; splitByFind(s, split_char, res); return res;
}

vector<string> splitByFind(string &s, const string &split_string) {
    vector<string> res; splitByFind(s, split_string, res); return res;
}

string replaceByFind(string &s, const char rc) {
    int pos = s.find(rc);
    while (pos != -1) s.replace(pos, 1, ""), pos = s.find(rc);
    return s;
}

string replaceByFind(string &s, const string rs) {
    for (char c : rs) replaceByFind(s, c);
    return s;
}
