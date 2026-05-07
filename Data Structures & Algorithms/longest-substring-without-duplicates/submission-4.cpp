class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i,j,ans=0,subans=0,n=s.size(),l=0;
        map<char,int> m;
        
        for(i=0;i<n;i++)
        {
            if(m[s[i]])
            {
                l=max(m[s[i]],l);
                m[s[i]]=i+1;
            }
            else
            {
                m[s[i]]=i+1;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};
