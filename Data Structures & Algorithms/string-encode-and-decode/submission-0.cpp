class Solution {
public:

    string encode(vector<string>& strs) {
        int i ,n=strs.size();
        string ans="";
        for(i=0;i<n;i++)
            ans=ans + strs[i] + "|";
        return ans;
    }

    vector<string> decode(string s) {
        int i,pos=0,n=s.size();
        vector<string> ans;
        for(i=0;i<n;i++)
        {
            if(s[i]=='|')
            {
                ans.push_back(s.substr(pos,i-pos));
                pos=i+1;
            }
        }
        return ans;
    }
};
