class Solution {
public:
    int totalhours(vector<int> piles,int k){
        int i,n=piles.size(),cnt=0;
        for(i=0;i<n;i++){
            cnt+=piles[i]/k;
            if((piles[i]/k)*k != piles[i])
                cnt++;
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int i,n=piles.size();
        int mid,l=piles[0],r=piles[n-1];
        for(i=0;i<n;i++){
            l=min(l,piles[i]);
            r=max(r,piles[i]);
        }
        l=1;
        int ans=r;
        while(l<=r){
            mid=(l+r)/2;
            int hrs = totalhours(piles,mid);
            cout<<"hrs : "<<hrs<<"mid : "<<mid<<endl;
            if(hrs>h)
                l=mid+1;
            else if(hrs<=h){
                ans =min(ans,mid);
                r=mid-1;
            }
        }
        return ans;
    }
};
