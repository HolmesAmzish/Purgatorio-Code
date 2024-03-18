// File:    RemoveElement.cpp
// Date:    2024.03.17
// Author:  Nulla

#include <vector>

class Solution {
    public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};