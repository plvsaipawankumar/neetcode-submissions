class Solution {
public:
    string longestPalindrome(string s) {
        int i,j,n=s.size(),reslen=0,resIdx=0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(i=n-1;i>=0;i--)
        {
            for(j=i;j<n;j++)
            {
                if(s[i]==s[j] && (((j-i)<=2) || dp[i+1][j-1] ) )
                {
                    dp[i][j]=true;
                    if((j-i+1)>reslen)
                    {
                        reslen=j-i+1;
                        resIdx=i;
                    }
                }
            }
        }
        return s.substr(resIdx,reslen);
    }
};
