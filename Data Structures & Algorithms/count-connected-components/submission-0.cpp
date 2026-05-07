class Solution {
public:
    void dfs(vector<vector<int>> graph,set<int> &visited,int src)
    {
        if(visited.count(src))
            return ;
        visited.insert(src);
        int i,n= graph[src].size();
        for(i=0;i<n;i++)
        {
            dfs(graph,visited,graph[src][i]);
        }
        return ;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        int i,sz=edges.size(),ans=0;
        set<int> visited;
        for(i=0;i<sz;i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        for(i=0;i<n;i++)
        {
            if(!visited.count(i))    
            {
                dfs(graph,visited,i);
                ans++;
            }
        }
        return ans;
    }
};
