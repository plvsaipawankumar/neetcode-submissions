class Solution {
public:
    int totalHours(vector<int> &nums,int h)
    {
        int i,count=0,n=nums.size();
        for(i=0;i<n;i++)
        {
            count+=(nums[i]/h);
            count = ((nums[i]%h)>0) ? count+1:count;
        }
        return count;
    }

    void binarySearch(vector<int> &nums,int h,int &ans,int low,int high)
    {
        if(low>high || high <low)
            return ;
        int mid = (low+high)/2;
        int hrs= totalHours(nums,mid);
        if(hrs<=h)
        {
            ans=min(ans,mid);
            binarySearch(nums,h,ans,low,mid-1);
        }
        else
        {
            binarySearch(nums,h,ans,mid+1,high);
        }
        return ;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int i,maxi=INT_MIN,n=piles.size(),mini=INT_MAX,ans=INT_MAX,sum=0;
        for(i=0;i<n;i++)
        {
            maxi=max(maxi,piles[i]);
            mini = min(mini,piles[i]);
            sum+=piles[i];
        }
        binarySearch(piles,h,ans,1,maxi);
        return ans; 
    }
};
