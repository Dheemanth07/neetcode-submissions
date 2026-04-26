class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int n1=nums1.size(),n2=nums2.size();
        int l=0,r=n1;
        while(l<=r){
            int partitionX = l + (r-l)/2;
            int partitionY = (n1+n2+1)/2 - partitionX;

            int maxLeftX = (partitionX==0)?INT_MIN:nums1[partitionX-1];
            int minRightX = (partitionX==n1)?INT_MAX:nums1[partitionX];
            int maxLeftY = (partitionY==0)?INT_MIN:nums2[partitionY-1];
            int minRightY = (partitionY==n2)?INT_MAX:nums2[partitionY];

            if(maxLeftX<=minRightY && maxLeftY<=minRightX){
                if((n1+n2)%2==0)
                    return (max(maxLeftX,maxLeftY) + min(minRightX,minRightY))/2.0;
                else
                    return max(maxLeftX,maxLeftY);
            }
            else if(maxLeftX>minRightY)
                r=partitionX-1;
            else 
                l=partitionX+1;
        }
        return 0.0;
    }
};
