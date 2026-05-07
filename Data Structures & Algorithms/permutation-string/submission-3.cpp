class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i,m=s1.size(),n=s2.size(),ans=0,l=0,common=0;
        map<char,int> store,count;
        if(s1.size()>n)return false;
        
        for(i=0;i<m;i++)
            store[s1[i]]++;
            
        for(i=0;i<n;i++)
        {
            count[s2[i]]++;
            if(store[s2[i]]>0 && store[s2[i]]>=count[s2[i]])
                common++;
            else if(store[s2[i]]>0 && count[s2[i]]>store[s2[i]])
            {
                common++;
                while(count[s2[i]]>store[s2[i]])
                {
                    if(store[s2[l]])
                        common--;
                    count[s2[l]]--;
                    l++;
                }
            }
            else
            {
                common=0,l=i;
                count.clear();
            }
                

            if(common==m)
                return true;
        }
        return false;
    }
};
