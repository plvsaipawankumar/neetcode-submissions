class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>> > pq;
        vector<vector<pair<int,int>>> graph(n);
        int i,m=flights.size();
        pair<int,int> ans={INT_MAX,INT_MAX};
        for(i=0;i<m;i++)
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        set<int> visited;
        pq.push({0,src,0});
        while(!pq.empty())
        {
            auto [dist,node,stops] = pq.top();pq.pop();
            cout<<"node : "<<dist<<","<<node<<","<<stops<<endl;
            if(node==dst && ans.second>dist && (stops-1)<=k)
            {
                cout<<"ans"<<endl;
                if(ans.first>=stops)
                {
                    ans={stops,dist};
                }
            }
            if((stops-1)>k)
                continue;
            for(i=0;i<graph[node].size();i++)
            {
                pq.push({dist+graph[node][i].second,graph[node][i].first,stops+1});
            }

        }
        return (ans.second==INT_MAX)?-1:ans.second;
    }
};
