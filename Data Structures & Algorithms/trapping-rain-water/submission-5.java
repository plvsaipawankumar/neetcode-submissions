class Solution {
    public int trap(int[] height) {
        int i,n = height.length;
        if(n==0){
            return 0;
        }

        int [] left = new int[n];
        int [] right = new int[n];
        int ans=0;
        left[0] = height[0];
        right[n-1] = height[n-1];

        for(i=1;i<n;i++){
            left[i]=Math.max(left[i-1],height[i]);
        }
        for(i=n-2;i>=0;i--){
            right[i]=Math.max(right[i+1],height[i]);
        }
        for(i=0;i<n;i++){
            ans+=Math.min(right[i],left[i])-height[i];
        }
        return ans;
    }
}
