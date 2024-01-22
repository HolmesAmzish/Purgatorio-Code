#include <iostream>

using namespace std;

struct students {
    string name;
    string id;
    float score;
};

int main() {
    int number;
    cin >> number;
    students stu[128];
    cin >> stu[0].name >> stu[0].id >> stu[0].score;
    students max = stu[0], min = stu[0];
    // Initialize the data

    for (int i = 1; i < number; i++) {
        cin >> stu[i].name >> stu[i].id >> stu[i].score;
        if (max.score < stu[i].score) max = stu[i];
        if (min.score > stu[i].score) min = stu[i];
    }
    // Compare and find the lowest and highest student

    cout << max.name << ' ' << max.id << endl;
    cout << min.name << ' ' << min.id << endl;
    cin.get();
    return 0;
}