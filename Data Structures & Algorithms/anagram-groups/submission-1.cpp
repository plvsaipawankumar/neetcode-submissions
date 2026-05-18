class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int i,n = strs.size();
        string sample;
        map<string,vector<string>> store;
        vector<vector<string>> ans;
        for(i=0;i<n;i++)
        {   
            sample = strs[i];
            sort(sample.begin(),sample.end());
            store[sample].push_back(strs[i]);
        }
        for(auto itr:store){
            ans.push_back(itr.second);
        }
        return ans;
    }
};
