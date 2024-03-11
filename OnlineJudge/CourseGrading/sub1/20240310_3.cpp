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

void DisplayList1(SequenceType sequence) {
    for (int i = 0; i < sequence.length; i++) {
        cout << sequence.list[i] << ' ';
    }
    cout << endl;
}

void DisplayList2(SequenceType sequence) {
    for (int i = 0; i < sequence.length; i++) {
        cout << sequence.list[i] << ' ';
    }
}

bool DeleteByElement(SequenceType &sequence, int element) {
    bool found = false;
    for (int i = 0; i < sequence.length;) {
        if (sequence.list[i] == element) {
            found = true;
            for (int j = i; j < sequence.length - 1; j++) {
                sequence.list[j] = sequence.list[j + 1];
            }
            sequence.length -= 1;
        } else {
            ++i;
        }
    }
    return found;
}


int partition(SequenceType &sequence, int low, int high) {
    int pivot = sequence.list[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (sequence.list[j] <= pivot) {
            i++;
            swap(sequence.list[i], sequence.list[j]);
        }
    }
    swap(sequence.list[i + 1], sequence.list[high]);
    return (i + 1);
}

void QuickSort(SequenceType &sequence, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(sequence, low, high);
        QuickSort(sequence, low, pivotIndex - 1);
        QuickSort(sequence, pivotIndex + 1, high);
    }
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
        cout << "error" << endl;
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
    QuickSort(sequence1, 0, sequence1.length - 1);
    DisplayList1(sequence1);

    // Delete all elements user input
    int element;
    cin >> element;
    if (!DeleteByElement(sequence1, element)) cout << "error" << endl;

    // Merge sequence1 and sequence2
    SequenceType sequenceMerged;
    CreateList(sequence2);
    MergeList(sequence1, sequence2, sequenceMerged);
    QuickSort(sequenceMerged, 0, sequenceMerged.length - 1);
    DisplayList1(sequenceMerged);

    // Delete elements by range
    int s, t;
    cin >> s >> t;
    if (!DeleteByRange(sequenceMerged, s, t)) goto end;
    QuickSort(sequenceMerged, 0, sequenceMerged.length - 1);

    if (sequenceMerged.length == 0) {
        cout << "empty list";
    } else {
        DisplayList2(sequenceMerged);
    }

    end:
    return 0;
}