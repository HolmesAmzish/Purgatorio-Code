#include <string>
#include "Tools.cpp"
#include "Solution.cpp"

using namespace std;

int main() {
    char s1[1009], s2[1009];
    int i;
    string in_data = ""; getline(cin, in_data);
    for (i = 0; i < in_data.size(); i += 1) s1[i] = in_data[i]; s1[i] = 0;
    in_data = ""; getline(cin, in_data);
    for (i = 0; i < in_data.size(); i += 1) s2[i] = in_data[i]; s2[i] = 0;
    cout << compare(s1, s2) << endl;
    return 0;
}