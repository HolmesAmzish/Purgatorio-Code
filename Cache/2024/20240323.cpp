int main() {
    Queue PascalTriangle;
    int n;
    cin >> n;
    cout << "1\n";

    // Initialize the queue with the first line
    PascalTriangle.enQueue(1);

    for (int i = 1; i < n; i++) {
        // Output the first 1 in the new row
        cout << "1 ";
        
        // Process the rest of the numbers in this row
        for (int j = 1; j < i; j++) {
            int prevNum_1 = PascalTriangle.GetFront();
            PascalTriangle.deQueue();
            int prevNum_2 = PascalTriangle.GetFront();
            PascalTriangle.deQueue();

            int num = prevNum_1 + prevNum_2;
            cout << num << ' ';

            // Re-enqueue both previous numbers for next iteration (if there's still room)
            PascalTriangle.enQueue(prevNum_1);
            PascalTriangle.enQueue(prevNum_2);
        }

        // Output the last 1 in the new row
        cout << "1\n";

        // If we're not on the last row, re-enqueue the first number from the current row
        // This assumes that you have enough space in your queue to hold all numbers in one row
        if (i != n - 1) {
            PascalTriangle.enQueue(1);
        }
    }

    return 0;
}
