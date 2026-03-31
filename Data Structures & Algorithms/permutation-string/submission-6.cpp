class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if (n > m) return false;

        // 1. Target frequency for s1
        vector<int> s1Count(26, 0);
        for (char c : s1) s1Count[c - 'a']++;

        // 2. Check every possible substring of length n in s2
        for (int i = 0; i <= m - n; i++) {
            vector<int> subCount(26, 0);
            for (int j = 0; j < n; j++) {
                subCount[s2[i + j] - 'a']++;
            }

            // 3. Compare the two frequency arrays
            if (s1Count == subCount) return true;
        }

        return false;
    }
};