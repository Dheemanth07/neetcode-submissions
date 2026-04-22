class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()) return "";
        auto &p=mp[key];
        for(int i=p.size()-1;i>=0;i--)
            if(p[i].first<=timestamp)
                return p[i].second;
        return "";
    }
};
