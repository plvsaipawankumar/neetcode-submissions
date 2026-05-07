class Solution {
public:
    string longestPalindrome(string s) {
        int i=0,j=0,left,right,n=s.size();
        string ans="";
        for(i=0;i<n;i++)
        {
            left=right=i;
            while((left>=0 && right<n) && (s[left]==s[right]))
            {
                left--;
                right++;
            }
            left++;right--;
            if(left<=right && ans.size()<(right-left+1))
                ans = s.substr(left,right-left+1);
            //cout<<right-left+1<<" left : "<<left<<"right : "<<right<<"ans : "<<ans<<endl;
            left=i;
            right=i+1;
            while((left>=0 && right<n) && (s[left]==s[right]))
            {
                left--;
                right++;
            }
            left++;right--;
            if(left<=right && ans.size()<(right-left+1))
                ans = s.substr(left,right-left+1);
            //cout<<right-left+1<<" left : "<<left<<"right : "<<right<<"ans : "<<ans<<endl;

        }
        return ans;
    }
};
