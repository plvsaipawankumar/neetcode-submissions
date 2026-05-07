class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int i,n=stones.size();
        for(i=0;i<n;i++)
            pq.push(stones[i]);
        
        while(pq.size()>1)
        {
            int a = pq.top();pq.pop();
            int b = pq.top();pq.pop();
            if((a-b)!=0)
                pq.push(abs(a-b));
        }
        return (pq.size()==1)?pq.top():0;
    }
};
