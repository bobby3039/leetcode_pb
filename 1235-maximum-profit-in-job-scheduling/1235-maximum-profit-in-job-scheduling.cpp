class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector< pair<pair<int,int>,int>>v(n);
        for(int i = 0; i < n; i++){
            v[i].first.first = endTime[i];
            v[i].first.second = startTime[i];
            v[i].second = profit[i];
        }
        sort(v.begin(), v.end());
        endTime.push_back(-1);
        sort(endTime.begin(), endTime.end());
        endTime.erase(unique(endTime.begin(), endTime.end()), endTime.end());

        vector<int>dp(n+1,0);
        int mx = 0;
        for(int i = 0; i < n; i++){
            int st = v[i].first.second;
            int en = v[i].first.first;
            int p = v[i].second;
            int id = upper_bound(endTime.begin(), endTime.end(), st) - endTime.begin();
            int cur_id = lower_bound(endTime.begin(), endTime.end(), en) - endTime.begin();
            id -= 1;
            dp[cur_id] = max({dp[cur_id-1], dp[cur_id], dp[id] + p});
            mx = max(mx, dp[cur_id]);
        }
        return mx;
    }
};