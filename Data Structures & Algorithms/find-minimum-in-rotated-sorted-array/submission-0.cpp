class Solution {
public:
    int minimumNums(vector<int> &nums ,int low,int high,int &ans)
    {
        if(low>high)
            return INT_MAX;
        if(nums[low]<nums[high])
            return nums[low];
        int mid = (low+high)/2;
        ans=min(nums[mid],ans);
        int left = minimumNums(nums,low,mid-1,ans);
        int right = minimumNums(nums,mid+1,high,ans);
        return min(left,right);
    }
    int findMin(vector<int> &nums) {
        int i,n=nums.size(),ans=nums[0];
        ans = min(ans,minimumNums(nums,0,n-1,ans));
        return ans;
    }
};
