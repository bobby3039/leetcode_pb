class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[n-1];
        long long ans = 0;
        for(int i = n-2; i>=0; i--){
            int parts = (nums[i] + prev - 1)/prev;
            int operations = parts - 1;
            ans += 1LL*(operations);
            prev = nums[i]/parts;

        }
        return ans;
    }
};