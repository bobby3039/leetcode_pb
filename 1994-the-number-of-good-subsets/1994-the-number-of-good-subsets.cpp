class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        long long MOD = 1e9 + 7;
        
        // 1. Frequency Map
        vector<long long> count(31, 0);
        for (int x : nums) count[x]++;

        // 2. Primes and Masks
        // We map primes to bit indices: 2->0, 3->1, 5->2 ... 29->9
        int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector<int> num_mask(31, 0);
        
        // Precompute masks for numbers 2 to 30
        for (int i = 2; i <= 30; i++) {
            int temp = i;
            for (int j = 0; j < 10; j++) {
                int p = primes[j];
                if (temp % p == 0) {
                    if ((temp / p) % p == 0) { // Check for square factors (e.g., 4, 12)
                        num_mask[i] = -1; // Invalid
                        break;
                    }
                    num_mask[i] |= (1 << j);
                }
            }
        }

        // 3. DP Initialization
        // dp[mask] = number of subsets with prime-product mask
        vector<long long> dp(1024, 0); 
        dp[0] = 1; // Base case: one way to have an empty subset

        // 4. Iterate through each number 2..30
        for (int i = 2; i <= 30; i++) {
            if (count[i] == 0 || num_mask[i] == -1) continue;

            int current_num_mask = num_mask[i];
            long long freq = count[i];

            // We iterate backwards or use a temp array to avoid using the same number
            // multiple times for the same subset in one step.
            // Since we are processing unique numbers one by one, we can clone dp.
            vector<long long> next_dp = dp; 
            
            for (int state = 0; state < 1024; state++) {
                // If this state exists and has no common factors with current number
                if (dp[state] > 0 && (state & current_num_mask) == 0) {
                    int new_state = state | current_num_mask;
                    next_dp[new_state] = (next_dp[new_state] + dp[state] * freq) % MOD;
                }
            }
            dp = next_dp;
        }

        // 5. Sum up all valid non-empty states
        long long ans = 0;
        for (int i = 1; i < 1024; i++) {
            ans = (ans + dp[i]) % MOD;
        }

        // 6. Handle the number 1 (2^count[1])
        long long powerOfOne = 1;
        long long base = 2;
        long long exp = count[1];
        while (exp > 0) {
            if (exp % 2 == 1) powerOfOne = (powerOfOne * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }

        return (ans * powerOfOne) % MOD;
    }
};