class Solution {
public:
    bool containsAll(string sub, string t) {
        vector<int> count(128, 0);
        
        for (char c : sub) count[c]++;
        for (char c : t) {
            if (count[c] == 0) return false;
            count[c]--;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.length();
        int minLen = INT_MAX;
        string ans = "";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string sub = s.substr(i, j - i + 1);
                
                if (containsAll(sub, t)) {
                    if (sub.length() < minLen) {
                        minLen = sub.length();
                        ans = sub;
                    }
                }
            }
        }
        return ans;
    }
};