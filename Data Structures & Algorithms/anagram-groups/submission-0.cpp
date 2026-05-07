#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> cegregate;
        int i,n=strs.size();
        string sample;
        for(i=0;i<n;i++)
        {
            sample=strs[i];
            sort(sample.begin(),sample.end());
            cegregate[sample].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto i:cegregate)
            ans.push_back(i.second);
        return ans;
    }
};
