class Solution {
    int findLarger(const vector<int>& nums, int l, int h, int value) {
        while (l < h) {
            if (h - l == 1) {
                if (nums[h] > value) return h;
                else return l;
            }
            int m = l + (h - l)/2;
            if (nums[m] > value) {
                l = m;
            } else {
                h = m - 1;
            }
        }
        return l;
    }
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int breakPoint = size - 2;
        while(breakPoint >= 0 && nums[breakPoint] >= nums[breakPoint + 1]) {
            breakPoint--;
        }
        if (breakPoint < 0) {
            sort(nums.begin(), nums.end());
        } else {
            int swapPoint = findLarger(nums, breakPoint + 1, size - 1, nums[breakPoint]);
            swap(nums[breakPoint], nums[swapPoint]);
            sort(nums.begin() + breakPoint + 1, nums.end());
        }
    }
};