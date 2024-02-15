// Filename:    ArrayFunction.cpp
// File Tag:    p3_4
// Date:        2023/12/28
// Description: Sorting students' grades for a specific course in a multidimensional array using a function
//              that sorts by a particular column

#include <iostream>

using namespace std;

enum SortDirection { Ascending, Descending };
// Represent two directions of sorting

const int col = 5;
// Define the number of column

void sort(int a[][col], int n, int column, SortDirection Direction) {
    // Define a function witch sort two lines of data by particular column

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][column] < a[j][column] && Direction == Descending ||
                a[i][column] > a[j][column] && Direction == Ascending) {
                int temp[col];
                memcpy(temp, a[i], sizeof(temp));
                memcpy(a[i], a[j], sizeof(temp));
                memcpy(a[j], temp, sizeof(temp));
                // Swap two lines of data for sorting
            }
        }
    }
}

int main() {
    const int CourseN = 5;
    int score[][CourseN] = {{20140101, 1, 82, 86, 0},
                            {20120203, 2, 80, 80, 0},
                            {20140205, 2, 90, 83, 0},
                            {20140205, 2, 86, 90, 0},
                            {20140102, 1, 75, 86, 0}};
                            // Put all the data

    int length = sizeof(score) / sizeof(score[0]);
    for (int i = 0; i < length; i++) {
        for (int j = 2; j < CourseN - 1; j++) {
            score[i][CourseN - 1] = score[i][CourseN - 1] + score[i][j];
        }
    }
    // Calculate the sum of scores of each student and put it into the 5 column

    sort(score, length, 4, Descending);
    // Sort by total score by descending
    
    sort(score, length, 1, Ascending);
    // Sort by the class number by ascending

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < CourseN; j++) {
            cout << score[i][j] << '\t';
        }
        cout << endl;
    }
    // Output the all data

    return 0;
}