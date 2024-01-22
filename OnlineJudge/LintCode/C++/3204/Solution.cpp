/**
 * @param s1: A char arryy
 * @param s2: A char arryy
 * @return: An integer
 */
int compare(char s1[], char s2[]) {
    // write your code here
    int cmp = strcmp(s1,s2);
    if (cmp > 0) return 1;
    else if (cmp < 0) return -1;
    else return 0;
}