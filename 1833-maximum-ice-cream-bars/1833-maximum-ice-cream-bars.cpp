class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        for(auto x : costs){
            if(coins >=x ){
                coins -= x;
                ans++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};