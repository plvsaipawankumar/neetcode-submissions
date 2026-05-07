class Solution {
public:
    int binarySearch(vector<int> nums,int low,int high,int target)
    {
        if(low>high || high<low || nums.size()<=0)
            return -1;
        int mid=(low+high)/2;
        if(nums[mid]==target)
            return nums[mid];
        return (nums[mid]<target)?binarySearch(nums,mid+1,high,target):binarySearch(nums,low,mid-1,target);
    }
    int columnMatrix(vector<vector<int>>& matrix, int target,int m)
    {
        int i,j;
        for(i=0;i<m;i++)
        {
            if(matrix[i][0]>target)
                return i;
        }
        return i;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i,n=matrix[0].size(),m=matrix.size();
        if(n>0 && m>0 && matrix[0][0]>target)
            return false;
        int col = columnMatrix(matrix,target,m)-1;
        return binarySearch(matrix[col],0,n-1,target)!=-1;
    }
};
