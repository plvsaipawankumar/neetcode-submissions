class Solution {
public:
    int trap(vector<int>& height) {
        int i,n=height.size(),ans=0;
        vector<int> leftmax(n,0),rightmax(n,0);
        leftmax[0]= height[0];
        for(i=1;i<n;i++){        
            leftmax[i]=max(leftmax[i-1],height[i]);
        }
        rightmax[n-1]=height[n-1];
        for(i=n-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],height[i]);
        }
        for(i=0;i<n;i++){
            ans+=min(leftmax[i],rightmax[i]) - height[i];
        }

        return ans;
    }
};
