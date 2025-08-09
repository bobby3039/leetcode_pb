class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int a = -1e5, b = -1e5;
        int cnt = 0;
        for(int i = 0 ; i < intervals.size(); i++){
               int st = intervals[i][0];
               int en = intervals[i][1];
               if(st >= b){
                a = st; b = en;
                continue;
               }
               else{
                cnt++;
               }


        }
        return cnt;
    }
};