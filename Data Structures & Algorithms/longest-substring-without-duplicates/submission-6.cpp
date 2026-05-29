class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> store;
        int ans=0,left=0,right=0,n=s.size();
        while(right<n)
        {
            if(store.find(s[right])!=store.end()){
                left=max(store[s[right]]+1,left);
            }
            cout<<left<<" "<<right<<endl;
            store[s[right]]=right;
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};
