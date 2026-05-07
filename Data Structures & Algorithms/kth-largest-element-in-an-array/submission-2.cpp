class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k= nums.size()-k;
        return quickSelect(nums,0,nums.size()-1,k);
    }
    int quickSelect(vector<int> &nums,int left,int right ,int k)
    {
        cout<<"left : "<<left<<"right : "<<right<<endl;
        int pivot = nums[right];
        int i,j,n=nums.size(),index=left-1;

        for(i=left;i<right;i++)
        {
            if(nums[i]<=pivot)
            {
                index++;
                swap(nums[i],nums[index]);
            }
        }
        index++;
        swap(nums[index],nums[right]);
        cout<<index <<" : "<<k<<endl;
        for(i=0;i<nums.size();i++)
            cout<<nums[i]<<",";
        if(index>k)
            return quickSelect(nums,left,index-1,k);
        else if(index<k)
            return quickSelect(nums,index+1,right,k);
        else
            return nums[index];
    }
};
