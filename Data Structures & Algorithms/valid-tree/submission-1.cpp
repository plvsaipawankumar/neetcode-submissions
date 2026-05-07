class Solution {
public:
    bool dfs(int node , int parent,unordered_set<int> & visited,vector<vector<int>> graph)
    {
        cout<<"node : "<<node<<" parent : "<<parent<<endl; 
        if(visited.count(node))
            return false;
        
        visited.insert(node);
        for(int i=0;i<graph[node].size();i++)
        {
            cout<<"graph[node][i] : "<<graph[node][i]<<endl;
            if(graph[node][i]==parent)continue;
            if(!dfs(graph[node][i],node,visited,graph))
                return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        int i;
        for(i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_set<int> visited;
        if(!dfs(0,-1,visited,graph))
            return false;
        return visited.size()==n;
    }
};
