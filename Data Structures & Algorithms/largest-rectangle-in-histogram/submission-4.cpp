class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        int n=heights.size();
        int maxArea=0;
        for(int i=0;i<n;i++){
            int h=heights[i];
            int left=i;
            while(left>0 && heights[left-1]>=h)
                left--;
            int right=i;
            while(right<n-1 && heights[right+1]>=h)
                right++;
            int w=right-left+1;
            maxArea=max(maxArea,h*w);
        }
        return maxArea;
    }
};
