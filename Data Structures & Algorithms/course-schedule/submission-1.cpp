class Solution {
public:
    unordered_map<int,vector<int>> preMap;
    unordered_set<int> visiting;
    bool dfs(int src)
    {
        if(visiting.count(src))
            return false;
        if(preMap[src].size()==0)return true;
        visiting.insert(src);
        for(auto nxt : preMap[src])
        {
            if(!dfs(nxt))
                return false;
        }
        visiting.erase(src);
        preMap[src].clear();
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int i;
        for(i=0;i<numCourses;i++)
        {
            preMap[i]={};
        }
        for(i=0;i<prerequisites.size();i++)
        {
            preMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(i=0;i<numCourses;i++)
        {
            if(!dfs(i))
                return false;
        }
        return true;
    }
};

