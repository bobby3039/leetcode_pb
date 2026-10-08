class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
       int n = tokens.size();
       sort(tokens.begin(), tokens.end());

       int i = 0, j = n-1;
       int cnt = 0;
       int ans = 0;
       while(i <= j){
        if(power >= tokens[i]){
            cnt++;
            ans = max(ans, cnt);
            power -= tokens[i];
            i++;
        }
        else{
            if(cnt > 0){
            cnt--;
            power += tokens[j];
            j--;
            }
            else break;
        }
       }

       return ans;



    }
};