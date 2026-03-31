class Solution {
public:
    int freqCount(string s, int start, int end, int k){
        int maxfreq=0;
        unordered_map<char,int>mp;
        for(int i=start;i<=end;i++)
            mp[s[i]]++;
        for(auto &p:mp){
            maxfreq=max(maxfreq,p.second);
        }
        if(end-start+1-maxfreq<=k)
            return end-start+1;
        return 0;
    }

    int characterReplacement(string s, int k) {
        if(s.empty()) return 0;
        int len=s.length();
        int maxc=0;
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                maxc=max(maxc,freqCount(s,i,j,k));
            }
        }
        return maxc;
    }
};
