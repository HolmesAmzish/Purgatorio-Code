#include <iostream>
#include <iomanip>

using namespace std;

void avg(int information[][6], int n, string course[5]) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += information[i][1];
    }
    cout << "The average of first course is: " << course[0] << " " << fixed << setprecision(2) << sum / 4 << endl;
}

void fail(int information[][6], int n, string course[5]) {
    cout << "The student(s) who failed in two or more courses:" << endl;
    cout << setw(12) << "NO.";
    for (int i = 0; i < 5; i++) {
        cout << setw(12) << course[i];
    }
    cout << endl;
    // Output the title.
    
    for (int i = 0; i < 4; i++) {
        int failCount = 0;
        for (int j = 1; j < 6; j++)
        {
            if (information[i][j] < 60) {
                failCount++;
            }
        }

        if (failCount >= 2) {
            for (int j = 0; j < 6; j++) {
                cout << setw(12) << information[i][j];
            }
            cout << endl;
        }
    }
}

void good(int information[][6], int n, string course[5]) {
    cout << "The student(s) whose average score is above 90 or every score is above 85:" << endl;
    cout << setw(12) << "NO.";
    for (int i = 0; i < 5; i++) {
        cout << setw(12) << course[i];
    }
    cout << endl;
    // Output the title.

    for (int i = 0; i < 4; i++) {
        float sum = 0;
        int scoreCount = 0;
        bool good = false;
        for (int j = 1; j < 6; j++) {
            sum += information[i][j];
            if (information[i][j] > 85) {
                scoreCount++;
            }
        }

        if (sum > 450) good = true;
        else if (scoreCount == 5) good = true;

        if (good) {
            for (int j = 0; j < 6; j++) {
                cout << setw(12) << information[i][j];
            }
            cout << endl;
        }
    }
}

int main() {
    string course[5];
    for (int i = 0; i < 5; i++) {
        cin >> course[i];
    }

    // Enter 5 subjects.
    int information[4][6];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> information[i][j];
        }
    }

    avg(information, 4, course);

    fail(information, 4, course);

    good(information, 4, course);

    return 0;
}

/* TEST SAMPLE
English
Physics
Mathmatics
History
Computer
101 95 95 95 95 95
102 35 35 35 35 35
103 60 90 90 100 100
104 80 80 80 80 80
*/