class Solution {
public:
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int i,n=prerequisites.size();
        queue<int> que;
        vector<int> indegree(numCourses,0);
        unordered_set<int> unique_vertex;
        vector<vector<int>> graph(numCourses);
        vector<int> ans(numCourses);
        for(i=0;i<n;i++)
        {
            indegree[prerequisites[i][1]]++;
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                que.push(i);
            }
        }
        int total_nodes=0;

        while(!que.empty())
        {
            int top = que.front();que.pop();
            ans[numCourses-1-total_nodes]=top;
            total_nodes++;
            for(i=0;i<graph[top].size();i++)
            {
                indegree[graph[top][i]]--;
                if(indegree[graph[top][i]]==0)
                    que.push(graph[top][i]);
            }
        }
        if(total_nodes!=numCourses)
            return{};
        return ans;
    }
};

