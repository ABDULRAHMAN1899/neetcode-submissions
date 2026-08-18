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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),
        [](const Interval &a,const Interval &b){
            return a.end<b.end;
        });
        int n=intervals.size();
        if(n==0 || n==1){
            return true;
        }
        int cnt=1;
        int freetime=intervals[0].end;
        for(int i=1;i<n;i++){
            if(intervals[i].start>=freetime){
                cnt+=1;
                freetime=intervals[i].end;
            }
        }
        if(cnt!=n){
            return false;
        }
        return true;

    }
};
