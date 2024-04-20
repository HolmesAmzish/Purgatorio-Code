void BubbleSort(int a[], int n) {
    int change;
    for (int i = change = 1; change && i < n; i++) {
        for (int j = 1, change = 0; j <= n - 1; j++) {
            if (a[j] > a[j+1]) {
                a[0] = a[j];
                a[j] = a[j+1];
                a[j+1] = a[0];
                change = 1;
            }
        }
    }
}