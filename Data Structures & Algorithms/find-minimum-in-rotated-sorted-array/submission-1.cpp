class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0;
        int h=nums.size()-1;
        int mid;
        int m=nums[0];
        while(l<h){
            mid=(l+h)/2;
            if(nums[mid]>nums[h]) l=mid+1;
            else h=mid;
        }
        if(l==h) return nums[l];
        return nums[mid];
    }
};
