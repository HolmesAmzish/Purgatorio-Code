/**
 * @param s1: A char array
 * @param s2: A char array
 * @return: An integer
 */
int compareString(string& s1, string& s2) {
    // write your code here
    int ret;
    if (s1.compare(s2) > 0) ret = 1;
    else if (s1.compare(s2) == 0) ret = 0;
    else ret = -1;
    return ret;
}