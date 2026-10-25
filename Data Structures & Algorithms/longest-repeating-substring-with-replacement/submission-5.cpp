class Solution {
public:
    int characterReplacement(string s, int k) {
        int i,n=s.size(),l=0,repeat_char=0,ans=0;
        vector<int> cache(26,0);
        for(i=0;i<n;i++){
            cache[s[i]-'A']++;
            repeat_char = max(cache[s[i]-'A'],repeat_char);
            while((i-l+1)-repeat_char>k)
            {
                cache[s[l]-'A']--;
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};
