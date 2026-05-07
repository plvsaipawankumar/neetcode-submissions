class Solution {
public:
    int characterReplacement(string s, int k) {
        int i,j,n=s.size(),l=0,ans=0;
        char max_char;
        map<char,int> char_size;
        vector<char> total_char;
        for(i=0;i<n;i++)
        {
            if(char_size[s[i]]==0)
                total_char.push_back(s[i]);
            char_size[s[i]]++;

            max_char=total_char[0];
            for(j=1;j<total_char.size();j++)
                max_char=(char_size[total_char[j]]>char_size[max_char])?total_char[j]:max_char;
            
            if(((i-l+1)-(char_size[max_char]))>k)
            {
                char_size[s[l]]--;
                l++;
            }
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};
