class Solution {
public:
    string maxValue(string n, int x) {
        
        int len = n.size();
        string result;
        result.resize(len + 1);
        if (n[0] == '-') {
            result[0] = n[0];
            int j = 1;
            int i = 1;
            while (i < len && (n[i] - '0') <= x) {
                result[j++] = n[i];
                ++i;
            }
            result[j++] = '0' + x;
            while (i < len) {
                result[j++] = n[i];
                ++i;
            }
        } else {
            int i = 0;
            int j = 0;
            while (i < len && (n[i] - '0') >= x) {
                result[j++] = n[i];
                ++i;
            }
            result[j++] = '0' + x;
            while (i < len) {
                result[j++] = n[i];
                ++i;
            }
        }
        return result;
    }
};