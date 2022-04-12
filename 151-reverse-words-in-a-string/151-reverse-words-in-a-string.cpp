class Solution {
public:
    string reverseWords(string s) {
        int N = s.size();
        vector<string> words;
        int i = 0;
        string temp = "";
        while(i < N) {
            if (s[i] == ' ') {
                i++;
                if (temp.size() > 0) {
                    words.push_back(temp);
                    temp = "";
                }
            } else {
                temp += s[i++];
            }
        }
        if (temp.size() > 0) {
            words.push_back(temp);
        }
        string result = "";
        for (vector<string>::reverse_iterator ri = words.rbegin(); ri != words.rend(); ri++) {
            result += *ri;
            result += ' ';
        }
        if (result.size() > 0) {
            result.pop_back();
        }
        return result;
    }
};