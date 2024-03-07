void DelNode(sqList *L, ElemType item) {
    int k = 0;
    while (int i < L->len) {
        if (L->data[i] == item) {
            k++
        } else {
            L->data[i-k] = L->data[i];
            i++;
        }
        L->len = len->len-k;
    }
}