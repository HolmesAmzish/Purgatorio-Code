class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (!(n & (n - 1)) && n > 0)
            return true;
        else 
            return false;
    }
};