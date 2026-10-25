class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int i,n=heights.size(),start=0,ans=0;
        stack<pair<int,int>> increasing_stack;
        for(i=0;i<n;i++){
            start = i;
            while(!increasing_stack.empty() && increasing_stack.top().first>heights[i]){
                ans=max(ans,increasing_stack.top().first*(i-increasing_stack.top().second));
                start=increasing_stack.top().second;
                increasing_stack.pop();
            }
            increasing_stack.push({heights[i],start});
        }
        while(!increasing_stack.empty()){
            ans = max(ans,increasing_stack.top().first*(n-increasing_stack.top().second));
            increasing_stack.pop();
        }
        return ans;
    }
};
