class Solution {
    char toLowerCase(char c) {
        if (c >= 'A' && c <= 'Z') {
            return 'a' + (c - 'A');
        } else {
            return c;
        }
    }
    bool isAlphaNumeric(char c) {
        if ((c >= 'a' && c <= 'z') 
            || (c >= '0' && c <= '9')
            || (c >= 'A' && c <= 'Z')) {
            return true;
        }
        return false;
    }
public:
    bool isPalindrome(string s) {
        int l = 0, h = s.size() - 1;
        while (l < h) {
            if (toLowerCase(s[l]) == toLowerCase(s[h])) {
                l++;
                h--;
            } else if (!isAlphaNumeric(s[l])) {
                l++;
            } else if (!isAlphaNumeric(s[h])) {
                h--;
            } else {
                return false;
            }
        }
        if (l < h) return false;
        return true;
    }
};