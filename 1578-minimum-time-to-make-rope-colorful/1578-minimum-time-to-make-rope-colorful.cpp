class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        if(n == 1)return 0;

        char prev = colors[0];
        int mx = neededTime[0];
        int sum = neededTime[0];
        int i = 1;
        int ans = 0;

        while(i < n){
            if(colors[i] == prev){
                mx = max(mx, neededTime[i]);
                sum += neededTime[i];
                i++;
            }
            else{
               ans += (sum - mx);
               prev = colors[i];
               mx = neededTime[i];
               sum = neededTime[i];
               i++;
            }
        }

        ans += (sum-mx);
        return ans;


    }
};