class Solution {
public:
    bool isAlphanumeric (char c)
    {
        return (c>47 && c<58) || (c>64 && c<91) || (c>96 && c<123);
    }
    bool isPalindrome(string s) {
        string temp="";
        int i,n=s.size();
        for(i=0;i<n;i++)
            if(isAlphanumeric(s[i]))
                temp+=s[i];

        n=temp.size();

        for(i=0;i<(n/2);i++)
            if(temp[i]!=temp[n-1-i])
            {
                if(temp[i]>64 && temp[i]<91)
                    temp[i]+=32;
                else 
                    temp[n-1-i]+=32;
                    
                if(temp[i]!=temp[n-1-i])return false;
            }

        return true;
    }
};
