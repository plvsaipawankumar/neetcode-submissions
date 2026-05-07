class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int i,n=points.size();
        double distance=0.00;
        vector<vector<int>> ans;
        priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,greater<pair<double,vector<int>>>> pq;
        for(i=0;i<n;i++)
        {
            distance = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            pq.push({distance,points[i]});
        }
        for(i=0;i<k;i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
