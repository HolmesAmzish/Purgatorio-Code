#include "Tools.cpp"
#include "Solution.cpp"

vector<int> deal(string in_data) {
    replaceByFind(in_data, " \r\n\t");
    if (in_data[0] != '[' || in_data[in_data.size() - 1] != ']') {
        cout << "Your data is [" << in_data << "]." << endl;
        cout << "The square brackets at both ends of the input data are abnormal." << endl;
        return {-11414};
    }
    in_data = in_data.substr(1, in_data.size() - 2);
    vector<int> res;
    for (string n : splitByFind(in_data, ',')) {
        if (n == "") continue;
        try {
            res.push_back(stoi(n));
        } catch (std::invalid_argument msg) {
            cout << "data [" << n << "] error" << endl;
            return {-11414};
        }
    }
    return res;
}

int main() {
    string in_data;
    in_data = ""; getline(cin, in_data); vector<int> in_order = deal(in_data); if (in_order.size() && in_order[0] == -11414) return 0;
    queue<int> q; for (int a : in_order) q.push(a);
    cout << getQueue3(q) << endl;
END:
    return 0;
}