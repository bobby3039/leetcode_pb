class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int s1 = accumulate(gas.begin(), gas.end(), 0);
        int s2 = accumulate(cost.begin(), cost.end(), 0);
        if(s2 > s1)return -1;
        int id = 0;
        int curr = 0;
        for(int i = 0; i < n; i++){
            if(curr + gas[i] - cost[i] < 0){
                id = (i+1)%n;
                curr = 0;
            }
            else{
                curr += gas[i] - cost[i];
            }
        }
        return id;
    }
};