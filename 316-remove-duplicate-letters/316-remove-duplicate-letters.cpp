class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result = "";
        int count[26] =  {0};
        bool used[26] = {false};
        for (auto c : s) {
            count[c-'a']++;
        }
        for(auto c : s) {
            count[c-'a']--;
            if (used[c-'a']) continue;
            while(!result.empty() && result.back() > c && count[result.back() - 'a'] > 0) {
                used[result.back() - 'a'] = false;
                result.pop_back();
            }
            used[c-'a'] = true;
            result.push_back(c);
        }
        return result;
    }
};