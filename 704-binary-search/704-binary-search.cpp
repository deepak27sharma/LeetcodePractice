class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int m = -1;
        while(low <= high) {
            m = low + (high - low) / 2;
            if (nums[m] == target) return m;
            else if (nums[m] > target) high = m - 1;
            else low = m + 1;
        }
        return -1;
    }
};