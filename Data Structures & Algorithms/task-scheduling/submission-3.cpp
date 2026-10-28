class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<int,int> count;
        int i,m=tasks.size(),maxfreq=0,maxfreqcount=0;
        for(i=0;i<m;i++){
            count[tasks[i]-'A']++;
        }
        for(auto itr=count.begin();itr!=count.end();itr++){
            if(itr->second>maxfreq){
                maxfreq=itr->second;
                maxfreqcount=1;
            }
            else if(itr->second==maxfreq)
                maxfreqcount++;
        }
        cout<<"maxfreq : "<<maxfreq<<" maxfreqcount : "<<maxfreqcount<<endl;
        return max((maxfreq-1)*(n+1)+maxfreqcount,m);
    }
};
