class KthLargest {
public:
    int pos ,size=0;
    vector<int> ans;
    int sort(int element)
    {
        int i,j;
        ans.push_back(element);
        size++;
        for(i=0;i<size-1;i++)
            if(ans[i]>element)
                break;

        for(j=size-1;j>i;j--)
            ans[j]=ans[j-1];
        ans[i]=element;

        return (size<pos)?-1:ans[size-pos];
    }
    KthLargest(int k, vector<int>& nums) {
        pos=k;
        int i,n=nums.size();
        for(i=0;i<n;i++)
            int ans = sort(nums[i]);
        for(i=0;i<size;i++)
            cout<<ans[i]<<",";
        cout<<endl;
        
    }
    
    int add(int val) {
        return sort(val);
    }
};
