#define MAX_SIZE 50
#include <iostream>

using namespace std;

typedef int ElemType;

typedef struct SequenceList{
    int data[MAX_SIZE];
    int length;
};

void CreateList (SequenceList *&List, ElemType a[], int n) {
    int i = 0, k = 0;
    List = (SequenceList * )malloc(sizeof(SequenceList));
    while (i < n) {
        List->data[k] = a[i];
        k++; i++;
    }
    List->length = k;
}

void InitList (SequenceList *& List) {
    List = (SequenceList*)malloc(sizeof(SequenceList));
    List->length = 0;
}

void DestroyList(SequenceList *&List) {
    free(List);
}

bool ListEmpty(SequenceList *List) {
    return(List->length == 0);
}

int ListLength(SequenceList *List) {
    return(List->length);
}

void DisplayList(SequenceList *List) {
    for (int i = 0; i < List->length; i++) {
        cout << List->data[i] << ' ';
    }
    cout << endl;
}

bool GetElement(SequenceList *List, int position, ElemType &element) {
    if (position < 1 || position > List->length) {
        return false;
    } else {
        element = List->data[position - 1];
        return true;
    }
}

int LocateElem(SequenceList* List, ElemType element) {
    int i = 0;
    while (i < List->length && List->data[i] != element) {
        i++;
        if (i >= List->length) {
            return 0;
        } else {
            return i + 1;
        }
    }
}

bool ListInsert(SequenceList *& List, int position, ElemType element) {
    if (position < 1 || position > List->length+1 || List->length == MAX_SIZE)
        return false;
    for (int i = List->length; i > position - 1; i--)
        List->data[i] = List->data[i - 1];
    List->data[position] = element;
    return true;
}

bool ListDelet(SequenceList* &List, int position, ElemType &element) {
    if (position < 1 || position > List->length)
        return false;
    element = List->data[position];
    for (int i = position - 1; i < List->length; i++)
        List->data[i] = List->data[i + 1];
    List->length -= 1;
    return true;
}

