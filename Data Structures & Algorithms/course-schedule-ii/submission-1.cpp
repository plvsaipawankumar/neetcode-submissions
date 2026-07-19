class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int i,n = prerequisites.size(),total=0;
        vector<int> indegree(numCourses,0);
        vector<vector<int>> graph(numCourses);
        vector<int> ans;
        queue<int> que;
        for(i=0;i<n;i++)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        for(i=0;i<numCourses;i++){
            if(indegree[i]==0)
                que.push(i);
        }
        while(!que.empty()){
            int top = que.front();
            ans.push_back(top);
            total++;
            que.pop();
            for(i=0;i<graph[top].size();i++){
                indegree[graph[top][i]]--;
                if(indegree[graph[top][i]]==0)
                    que.push(graph[top][i]);
            }
        }
        if(total!=numCourses)
            ans.clear();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
