class Solution {
public:
    vector<vector<string>> cache;
    string palindrome(string s)
    {
        int l,r,i,j,reslen=0,resIdx=0,n= s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        for(i=0;i<n;i++)
        {
            l=i;
            r=i;
            while(s[l]==s[r] && l>=0 && r<n)
            {
                if(reslen<(r-l+1))
                {
                    reslen= r-l+1;
                    resIdx = l;
                }
                l--;
                r++;
            }

            l=i;
            r=i+1;
            while(s[l]==s[r] && l>=0 && r<n)
            {
                if(reslen<(r-l+1))
                {
                    reslen= r-l+1;
                    resIdx = l;
                }
                l--;
                r++;
            }
        }
        
        return s.substr(resIdx,reslen);
    }
    string longestPalindrome(string s) {
        return palindrome(s);
    }
};
