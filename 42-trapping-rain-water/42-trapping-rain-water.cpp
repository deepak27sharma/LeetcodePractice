class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        /*vector<int> rightLarger(n);
        int max_till_now = -1;
        int amount = 0;
        for (int i = n - 1; i >= 0; i--) {
            rightLarger[i] = (max_till_now >= height[i]) ? max_till_now : -1;
            max_till_now = max(max_till_now, height[i]);
        }
        max_till_now = 0;
        for (int i = 0; i < n; i++) {
            if (min(max_till_now, rightLarger[i]) > height[i]) {
                amount += min(max_till_now, rightLarger[i]) - height[i];
            }
            max_till_now = max(max_till_now, height[i]);
        }
        return amount;*/
        int lmax = 0;
        int rmax = 0;
        int l = 0, h = n - 1;
        int amount = 0;
        while(l < h) {
            if (height[l] < height[h]) {
                lmax = max(lmax, height[l]);
                amount += lmax - height[l];
                l++;
            } else {
                rmax = max(rmax, height[h]);
                amount += rmax - height[h];
                h--;
            }
        }
        return amount;
    }
};