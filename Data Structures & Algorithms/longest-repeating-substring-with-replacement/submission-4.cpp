class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> count;
        int ans=0,l=0,i,n=s.size(),maxcount=0;
        for(i=0;i<n;i++){
            count[s[i]]++;
            maxcount=max(maxcount,count[s[i]]);
            while((i-l+1)-maxcount >k){
                count[s[l]]--;
                l++;
            }
            cout<<i<<" "<<l<<endl;
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};
