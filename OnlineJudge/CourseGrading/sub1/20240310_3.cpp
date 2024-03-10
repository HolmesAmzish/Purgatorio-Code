#include <iostream>
#define MAX 64

using namespace std;

struct SequenceType {
    int list[MAX];
    int length;    
};

void CreateList(SequenceType &sequence) {
    int input[MAX];
    int i = 0;
    while (i < MAX && cin >> input[i] && input[i] != -1) {
        ++i;
    }
    for (int j = 0; j < i; j++) {
        sequence.list[j] = input[j];
    }
    sequence.length = i;
}

void DisplayList(SequenceType sequence) {
    for (int i = 0; i < sequence.length; i++) {
        cout << sequence.list[i] << ' ';
    }
    cout << endl;
}

bool DeleteByElement(SequenceType &sequence, int element) {
    bool found = false;
    for (int i = 0; i < sequence.length; i++) {
        if (sequence.list[i] == element) {
            found = true;
            for (int j = i; j < sequence.length - 1; j++) {
                sequence.list[j] = sequence.list[j + 1];
            }
            sequence.length -= 1;
        }
    }
    return found;
}

void MergeList(SequenceType &sequence1, SequenceType &sequence2, SequenceType &sequenceMerged) {
    int i = 0, j = 0, k = 0;

    while (i < sequence1.length && j < sequence2.length) {
        if (sequence1.list[i] <= sequence2.list[j]) {
            sequenceMerged.list[k++] = sequence1.list[i++];
        } else {
            sequenceMerged.list[k++] = sequence2.list[j++];
        }
    }

    while (i < sequence1.length) {
        sequenceMerged.list[k++] = sequence1.list[i++];
    }
    while (j < sequence2.length) {
        sequenceMerged.list[k++] = sequence2.list[j++];
    }

    sequenceMerged.length = k;
}

bool DeleteByRange(SequenceType &sequence, int s, int t) {
    if (s >= t || sequence.length == 0) {
        cout << "Error: Invalid range or empty list!" << endl;
        return false;
    }

    int i = 0, j = 0;
    while (i < sequence.length) {
        if (sequence.list[i] < s || sequence.list[i] > t) {
            sequence.list[j++] = sequence.list[i];
        }
        ++i;
    }

    sequence.length = j;
    if (sequence.length == 0) return true;
    return true;
}

int main() {
    SequenceType sequence1, sequence2;
    CreateList(sequence1);
    DisplayList(sequence1);

    // Delete all elements user input
    int element;
    cin >> element;
    if (!DeleteByElement(sequence1, element)) cout << "error" << endl;

    // Merge sequence1 and sequence2
    CreateList(sequence2);
    SequenceType sequenceMerged;
    MergeList(sequence1, sequence2, sequenceMerged);
    DisplayList(sequenceMerged);

    // Delete elements by range
    int s, t;
    cin >> s >> t;
    DeleteByRange(sequenceMerged, s, t);
    DisplayList(sequenceMerged);

    return 0;
}