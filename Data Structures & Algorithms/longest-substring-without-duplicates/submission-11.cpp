class Solution {
public:
    // Helper function to check if a substring has all unique characters
    bool allUnique(string& s, int start, int end) {
        unordered_set<char> ust;
        for (int i = start; i <= end; i++) {
            if (ust.count(s[i])) return false;
            ust.insert(s[i]);
        }
        return true;
    }

    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxc = 0;

        // 1. Loop for the starting point of the substring
        for (int i = 0; i < n; i++) {
            // 2. Loop for the ending point of the substring
            for (int j = i; j < n; j++) {
                // 3. Check if the substring from i to j is unique
                if (allUnique(s, i, j)) {
                    maxc = max(maxc, j - i + 1);
                }
            }
        }
        return maxc;
    }
};