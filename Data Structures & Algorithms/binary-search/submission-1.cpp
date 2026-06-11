class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i,n=nums.size();
        int mid,l=0,r=n-1;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(nums[mid]<target){
                l=mid+1;
            }
            else if(nums[mid]>target)
                r=mid-1;
            else
                return mid;
        }
        return -1;

    }
};
