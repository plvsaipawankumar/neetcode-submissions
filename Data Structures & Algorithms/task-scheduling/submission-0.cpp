class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        vector<int> count(26,0);
        map<int,int> cache;
        pair<char,int> max_space;
        int i,n=tasks.size(),ans=0,empty=0,r,o;
        for(i=0;i<n;i++)
            count[tasks[i]-'A']++;
        
        for(i=0;i<26;i++)
        {
            if(count[i]!=0)
            {
                cache[count[i]]++;
                r=count[i];
                o=cache[count[i]];
                if(ans<((r-1)*k+r+(o-1)))
                {
                    ans= (r-1)*k+r+(o-1);
                    empty = ans-(r*o);
                }
                
            }
        }

        n=n-(ans-empty);
        return (empty>n)?ans:(n-empty)+ans;
    }
};
