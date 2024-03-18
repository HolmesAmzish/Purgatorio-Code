// File:    RemoveElement2.cpp
// Date:    2024.03.17
// Author:  Nulla
// Description: Remove all duplicates from sorted array.

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0; // 如果数组为空，则直接返回0

        int index = 1; // 从数组的第二个元素开始检查
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) { // 如果当前元素不等于前一个元素，则说明找到了一个不重复的元素
                nums[index++] = nums[i]; // 将不重复的元素移到数组前面
            }
        }
        return index; // 返回不重复元素的个数
    }
};