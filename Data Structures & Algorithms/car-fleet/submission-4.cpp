class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int i,n=pos.size();
        vector<pair<int,int>> pr;
        for(i=0;i<n;i++)
        {
            pr.push_back({pos[i],speed[i]});
        }
        sort(pr.rbegin(),pr.rend());
        vector<double> stk;
        for(auto &p : pr)
        {
            stk.push_back((double)(target-p.first)/p.second);
            if(stk.size()>=2 && stk.back()<=stk[stk.size()-2])
                stk.pop_back();
        }
        return stk.size();
    }
};
