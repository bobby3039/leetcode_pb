class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(a[j] > a[i]){
                    if(dp[i] + 1 > dp[j]){
                        dp[j] = dp[i] + 1;
                        cnt[j] = cnt[i];
                    }
                    else if(dp[i] + 1 == dp[j]){
                        cnt[j] += cnt[i];
                    }
                }
            }
        }
        for(auto x : dp)cout<<x<<" ";
        int mx = 0;
        for(auto x : dp){
            mx = max(mx,x);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == mx){
                ans += cnt[i];
            }
        }
        return ans;
    }
};