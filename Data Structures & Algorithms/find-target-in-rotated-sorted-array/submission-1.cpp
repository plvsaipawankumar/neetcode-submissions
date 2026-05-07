class Solution {
public:
    int binarySearch(vector<int> nums,int target,int low,int high)
    {
        if(low>high)
            return -1;
        int mid= (low+high)/2;
        if(nums[mid]==target) return mid;
        if(nums[low]<nums[mid] && nums[high]>nums[mid])
        {
            return (nums[mid]>target)?binarySearch(nums,target,low,mid-1):binarySearch(nums,target,mid+1,high);
        }
        int left = binarySearch(nums,target,low,mid-1);
        if(left>=0)return left;
        int right = binarySearch(nums,target,mid+1,high);
        return right;
    }
    int search(vector<int>& nums, int target) {
        int i,ans=INT_MIN,n=nums.size();
        return binarySearch(nums,target,0,n-1);
    }
};
