class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_map<char, int> prevIndex;
        int i = 0, j = 0;
        while (j < s.size()) {
            if (prevIndex.find(s[j]) == prevIndex.end()
                || prevIndex[s[j]] < i ) {
                maxLen = max(maxLen, j - i + 1);
            } else {
                i = prevIndex[s[j]] + 1;
            }
            prevIndex[s[j]] = j;
            j++;
        }
        return maxLen;
    }
};