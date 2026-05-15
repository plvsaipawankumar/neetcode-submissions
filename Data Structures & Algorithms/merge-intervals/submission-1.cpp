class Solution {
public:
    static bool comp(vector<int> & a , vector<int> & b)
    {
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        for(int i=0;i<intervals.size();i++)
        {
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        }
        vector<vector<int> > output;
        output.push_back(intervals[0]);
        for(auto & interval : intervals)
        {
            int start = interval[0];
            int end = interval[1];
            if(start <= output.back()[1])
                output.back()[1]= max(end,output.back()[1]);
            else
                output.push_back(interval);
        }
        return output;
    }
};
