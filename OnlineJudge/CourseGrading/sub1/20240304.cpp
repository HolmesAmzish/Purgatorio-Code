#include <iostream>
#include <cstdlib>

using namespace std;

void Output(int array[], int n) {
	int i;
	for (i = 0; i < n ; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;
}

void Found(int array[], int n, int x) {
	int i;
	bool found = false;
	for (i = 0; i < n; i++) {
		if (array[i] == x) {
			found = true;
			break;
		}
	}
	if (found) cout << "found" << endl;
	else cout << "not found" << endl;
}

void Union(int arrayA[], int m, int arrayB[], int n) {
	int i, j, k;
	for (i = 0; i < m; i++) {
		cout << arrayA[i] << ' ';
	}
	// Output all elements of arrayA
	for (j = 0; j < n; j++) {
		bool found = false;
		for (k = 0; k < m; k++) {
			if (arrayB[j] == arrayA[k]) {
				found = true;
				break;
			}
		}
		if (!found) {
			cout << arrayB[j] << ' ';
		}
	}
	cout << endl;
}

void Inter(int arrayA[], int m, int arrayB[], int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (arrayA[i] == arrayB[j]) {
				cout << arrayA[i] << ' ';
			}
		}
	}
	cout << endl;
}

void Diff(int arrayA[], int m, int arrayB[], int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		bool found = false;
		for (j = 0; j < n; j++) {
			if (arrayA[i] == arrayB[j]) {
				found = true;
				break;
			}
		}
		if (!found) {
			cout << arrayA[i] << ' ';
		}
	}
	cout << endl;
}

int main() {
	int arrayA[64], arrayB[64], x;
	int m, n;
	cin >> m;
	int input;
	int i = 0, j = 0;
	while (i < m) {
		cin >> input;
		if (input > 0) {
			arrayA[i] = input;
			i++;
		}
	}
	cin >> n;
	while (j < n) {
	cin >> input;
	if (input > 0) {
		arrayB[j] = input;
		j++;
		}
	}
	cin >> x;

	Output(arrayA, m);
	Output(arrayB, n);
	Found(arrayA, m, x);
	Union(arrayA, m, arrayB, n);
	Inter(arrayA, m, arrayB, n);
	Diff(arrayA, m, arrayB, n);
	
	system("pause");
	return 0;
}

/* TEST SAMPLE
5
1 3 4 -1 -2 5 6
7
3 4 1 2 8 9 7
4
*/
