class Solution {
    void swap(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }
    void findPerms(vector<int>& nums, int index, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        } else {
            for (int i = index; i < nums.size(); ++i) {
                swap(nums[index], nums[i]);
                findPerms(nums, index + 1, result);
                swap(nums[index], nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        findPerms(nums, 0, result);
        return result;
    }
};