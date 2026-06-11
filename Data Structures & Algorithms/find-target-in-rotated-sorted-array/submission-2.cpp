class Solution {
public:
    int binarysearch(vector<int> nums,int target,int l,int r){
        if(l>r)return -1;
        int mid = (l+r)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]>nums[l] && nums[mid]<nums[r]){
            return (nums[mid]>target)?binarysearch(nums,target,l,mid-1):binarysearch(nums,target,mid+1,r);
        }
        int left = binarysearch(nums,target,l,mid-1);
        if(left!=-1)return left;
        int right = binarysearch(nums,target,mid+1,r);
        return right;
    }   
    int search(vector<int>& nums, int target) {
        int i,n=nums.size();
        int mid,l=0,r=n-1;
        return binarysearch(nums,target,0,n-1);
    }
};
