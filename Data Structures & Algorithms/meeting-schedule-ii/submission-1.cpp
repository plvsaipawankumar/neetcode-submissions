/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool static compare(Interval a,Interval b){
        if(a.start == b.start)
            return a.end < b.end;
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int i=1,n=intervals.size(),ans=1;
        if(n==0)
            return 0;
        
        priority_queue<int , vector<int>,greater<int>> min_heap;
        for(i=0;i<n;i++){
            if(!min_heap.empty() && min_heap.top()<=intervals[i].start){
                min_heap.pop();
            }
            min_heap.push(intervals[i].end);
        }
        return min_heap.size();
    }
};
