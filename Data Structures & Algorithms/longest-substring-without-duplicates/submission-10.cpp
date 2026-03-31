class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int l=0,r=0;
        int maxc=0;
        int n=s.length();
        while(r<n){
            if(!st.count(s[r])){
                st.insert(s[r++]);
                maxc=max(maxc,r-l);
            }
            else{
                st.erase(s[l]);
                l++;
            }
        }
        return maxc;
    }
};
