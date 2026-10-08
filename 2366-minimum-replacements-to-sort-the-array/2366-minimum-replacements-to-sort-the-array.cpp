class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[n-1];
        long long ans = 0;
        for(int i = n-2; i>=0; i--){
            int val = (nums[i] + prev - 1)/prev;
            ans += 1LL*(val-1);
            prev = nums[i]/val;

        }

        return ans;
    }
};