class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";
        unordered_map<char,int>target,window;
        for(char c:t) target[c]++;
        int left=0,right=0,startIdx=0;
        int required=target.size();
        int formed=0;
        int minLen=INT_MAX;
        while(right<s.length()){
            char c = s[right];
            window[c]++;
            if(target.count(c) && window[c]==target[c])
                formed++;
            while(left<=right && formed==required){
                char c = s[left];
                if(right-left+1<minLen){
                    minLen=right-left+1;
                    startIdx=left;
                }
                window[c]--;
                if(target.count(c) && window[c]<target[c])
                    formed--;
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(startIdx,minLen);
    }
};
