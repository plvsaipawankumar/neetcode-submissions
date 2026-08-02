class Solution {
public:
    int trap(vector<int>& height) {
        int i,n=height.size(),ans=0;
        vector<int> left(n,0), right(n,0);
        left[0]=height[0];
        for(i=1;i<n;i++){
            left[i] = max(left[i-1],height[i]);
        }
        right[n-1]=height[n-1];
        for(i=n-2;i>=0;i--){
            right[i] = max(right[i+1],height[i]);
        }
        for(i=0;i<n;i++)
        {
            cout<<left[i]<<" "<<right[i]<<endl;
            ans = ans + min(left[i],right[i])-height[i];
        }
        return ans;
    }
};
