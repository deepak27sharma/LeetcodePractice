class Solution {
    //find next larger in a reverse sorted array
    int findLarger(string& s, int l, int h, int value) {
        while(l < h) {
            if (h - l == 1) {
                if (s[h] > value) return h;
                return l;
            }
            int m = l + (h - l)/2;
            if (s[m] > value) l = m;
            else {
                h = m - 1;
            }
        }
        return l;
    }
    void nextPermutation(string& s, int size) {
        //find breakPoint
        int i = size - 2;
        while(i >= 0 && s[i] > s[i + 1]) {
            i--;
        }
      //  i -= 1;
        if (i < 0) {
            reverse(s.begin(), s.end());
        } else {
            int j = findLarger(s, i + 1, size - 1, s[i]);
            swap(s[i], s[j]);
            reverse(s.begin() + i + 1, s.end());
        }
    }
public:
    string getPermutation(int n, int k) {
        int value = 0;
        for (int i = 1, j = 10; i <= n; ++i) {
            value *= j;
            value += i;
        }
        string result = to_string(value);
        if (k == 1) return result;
        else {
            for (int i = 2; i <= k; ++i) {
                nextPermutation(result, n);
            }
            return result;
        }
    }
};