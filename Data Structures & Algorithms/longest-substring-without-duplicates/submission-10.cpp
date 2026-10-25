class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int> count;
        int i,n=s.size(),r=0,l=0,ans=0;
        for(i=0;i<n;i++){
            while(count[s[i]-'a']){
                count[s[l]-'a']--;
                l++;
            }
            count[s[i]-'a']++;
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
