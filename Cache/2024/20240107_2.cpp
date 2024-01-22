//Name: Way Too Long Words
//Tags: strings

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n; cin >> n;
    char words[100][100];
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    for (int i = 0; i < n; i++) {
        int len = strlen(words[i]);
        if (len <= 10) {
            cout << words[i];
        } else {
            cout << words[i][0] << len - 2 << words[i][len - 1];
        }
        cout << endl;
    }
    return 0;
}

/*TEST SAMPLE
Input:
4
word
localization
internationalization
pneumonoultramicroscopicsilicovolcanoconiosis
*/