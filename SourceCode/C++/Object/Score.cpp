// File name:   Score.cpp
// Date:        2024.2.13
// Author:      Nulla

#include <iostream>

using namespace std;

const float RATE = 0.6;

class Score {
private:
    long id;
    string name;
    int usual;
    int final;
    int total;
public:
    Score(long = 0, string = "", int = 0, int = 0, int = 0);
    void Count();
    void ShowScore();
};

Score::Score(long ID, string Name, int Usual, int Final, int Total) {
    id = ID;
    name = Name;
    usual = Usual;
    final = Final;
    total = Total;
}

void Score::Count() {
    total = usual * RATE + final * (1 - RATE) + 0.5;
}

void Score::ShowScore() {
    cout << id << "\t" << name << "\t" << usual << "\t" << final << "\t" << total << endl;
}

int main() {
    Score ClassScore[3] = {Score(20230701, "Lu Kexin", 88, 79),
                            Score(20230612, "Wu Weixue", 70, 80),
                            Score(20230611, "Da Shabi", 90, 85)};
    for (int i = 0; i < 3; i++) {
        ClassScore[i].Count();
    }
    for (int i = 0; i < 3; i++) {
        ClassScore[i].ShowScore();
    }
    return 0;
}