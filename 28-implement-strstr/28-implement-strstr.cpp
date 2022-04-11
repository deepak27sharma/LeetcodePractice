class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (haystack.size() < needle.size()) return -1;
//        if (haystack.size() == needle.size()) return haystack == needle ? 0 : -1;
        for (int i = 0; i < haystack.size() - needle.size() + 1; ++i) {
            int counter = i;
            int j = 0;
            for (; j < needle.size(); ++j) {
                if (haystack[counter++] != needle[j]) {
                    break;
                }
            }
            if (j == needle.size()) return i;
        }
        return -1;
    }
};