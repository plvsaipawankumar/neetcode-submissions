class Solution {
public:
    int countSubstrings(string s) {
        int i,j,n=s.size(),ans=0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(i=n-1;i>=0;i--)
        {
            for(j=i;j<n;j++)
            {
                if(s[i]==s[j] && (((j-i)<=2)  || dp[i+1][j-1]))
                {
                    cout<<i<<" , "<<j<<endl;
                    dp[i][j]=true;
                    ans++;
                }
            }
        }
        return ans;
    }
};
