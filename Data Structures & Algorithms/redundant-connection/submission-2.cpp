class Solution {
public:
    bool cycle(vector<vector<int>> graph,int start,int parent,vector<bool> & visited){
        if(visited[start] )
            return true;
        visited[start]=true;
        for(int i=0;i<graph[start].size();i++){
            if(graph[start][i]!=parent && cycle(graph,graph[start][i],start,visited))
                return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int i ,n=edges.size();
        vector<vector<int>> graph(n+1);
        for(i=0;i<n;i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);

            vector<bool> visited(n+1,false);
            if(cycle(graph,edges[i][0],-1,visited)){
                return {edges[i][0],edges[i][1]};
            }
        }
        return {};
    }
};
