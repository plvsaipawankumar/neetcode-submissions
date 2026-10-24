class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string>> anagrams;
        string sorted ;
        int i,n=strs.size();
        for(i=0;i<n;i++){
            sorted = strs[i];
            sort(sorted.begin(),sorted.end());
            anagrams[sorted].push_back(strs[i]);
        }
        for(auto anagram:anagrams){
            ans.push_back(anagram.second);
        }
        return ans;
    }
};
