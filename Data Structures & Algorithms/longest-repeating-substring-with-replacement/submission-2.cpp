class Solution {
public:
    int characterReplacement(string s, int k) {
        int i,n=s.size(),left=0,right=0,ans=0,replace=0;
        int primechar=0;
        map<char,int> store;
        while(right<n)
        {
            store[s[right]]++;
            primechar = max(primechar,store[s[right]]);

            while((right-left+1) - primechar >k){
                store[s[left]]--;
                left++;
            }
            right++;
            ans=max(ans,right-left);
        }
        return ans;
    }
};
