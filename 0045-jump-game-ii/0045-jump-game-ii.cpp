class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1001, 1e5);
        dp[0] = 0;
        int maxi = 0;
        int ans = 1e5;
          if(maxi >= n-1){
                    ans = min(ans, dp[maxi]);
          }
        for(int i = 0; i < n; i++){
            if(i <= maxi){
                maxi = max(maxi, i + nums[i]);
                dp[maxi] = min(dp[maxi], dp[i] + 1);
                if(maxi >= n-1){
                    ans = min(ans, dp[maxi]);
                }
            }
        }
        return ans;

    }
};