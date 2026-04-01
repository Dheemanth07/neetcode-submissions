class Solution {
public:
    int maxVal(vector<int> temp){
        int maxi=INT_MIN;
        for(int num:temp)
            maxi=max(maxi,num);
        return maxi;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty()) return {};
        int n = nums.size();
        vector<int>res;
        for(int i = 0; i <= n-k; i++){
            vector<int>temp;
            for(int j = i; j < k+i; j++){
                temp.push_back(nums[j]);
            }
            res.push_back(maxVal(temp));
        }
        return res;
    }
};
