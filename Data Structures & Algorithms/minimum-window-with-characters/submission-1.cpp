class Solution {
public:
    bool allpresent(map<char,int> ms,map<char,int>mt)
    {
        for(auto i: ms)
        {
            if(mt[i.first]>i.second)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int i,j,n=s.size(),m=t.size(),l=0,count=0;
        bool ans_present;
        string ans="",tempans="";
        map<char,int> ms,mt;
        vector<int> poss;

        for(i=0;i<m;i++)
            mt[t[i]]++;
        m=mt.size();

        for(i=0;i<n;i++)
        {
            if(mt[s[i]])
                poss.push_back(i);
        }
            
        n=poss.size();
        for(i=0;i<n;i++)
        {
            ms[s[poss[i]]]++;
            if(ms[s[poss[i]]]==mt[s[poss[i]]])
                count++;
            if(count==m)
            {
                ans_present= true;
                break;
            }
        }
        if(!ans_present)return ans;
        
        while(1)
        {
            ms[s[poss[l]]]--;
            l++;
            if(!allpresent(ms,mt))
                break;
        }
        l--;
        ms[s[poss[l]]]++;
        //           l               i
        //"A D O B E C O D E B A  N  C"
        //"0 1 2 3 4 5 6 7 8 9 10 11 12"
        ans=s.substr(poss[l],poss[i]-poss[l]+1);
        i++;

        while(i<n)
        {
            if(ms[s[poss[l]]] == mt[s[poss[l]]])
                count--;
            
            ms[s[poss[l]]]--;
            ms[s[poss[i]]]++;
            l++;
            if(mt[s[poss[i]]]==ms[s[poss[i]]])
            {
                count++;
                tempans=s.substr(poss[l],poss[i]-poss[l]+1);
                ans = (ans.size()>tempans.size())?tempans:ans;
            }
            i++;
        }
        return ans;
    }
};
