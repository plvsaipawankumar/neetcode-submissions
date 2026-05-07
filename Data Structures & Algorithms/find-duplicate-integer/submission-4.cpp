class Solution {
public:
    void swap(int &a, int &b)
    {
        int temp = a;
        a=b;
        b=temp;
    }
    int findDuplicate(vector<int>& nums) {
        int i,j,n=nums.size();
        for(i=0;i<n;i++)
        {
            nums[(nums[i]-1)%(n)]+=n;

        }
        for(i=0;i<n;i++)
        {
            cout<<"num[i] : "<<nums[i]<<endl;
            if(((nums[i])/(n))>1)
                return i+1;
        }
        return 0;
    }
};
