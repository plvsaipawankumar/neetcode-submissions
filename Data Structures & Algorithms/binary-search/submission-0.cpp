class Solution {
public:
    int binarySearch(vector<int> nums,int low,int high,int target)
    {
        if(low>high || high<low)
            return -1;
        int mid= (low+high)/2;
        if(nums[mid]==target)
            return mid;
        return (nums[mid]<target)?binarySearch(nums,mid+1,high,target):binarySearch(nums,low,mid-1,target);
    }
    int search(vector<int>& nums, int target) {
        int i,n=nums.size();
        return binarySearch(nums,0,n-1,target);
    }
};
