class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
       int n = tokens.size();
       sort(tokens.begin(), tokens.end());
       
       int i = 0, j = n-1;
       int p = power;
       int cnt = 0;
       int ans = 0;
       while(i <= j){
        if(p >= tokens[i]){
            cnt++;
            ans = max(ans, cnt);
            p -= tokens[i];
            i++;
        }
        else{
            if(cnt > 0){
            cnt--;
            p += tokens[j];
            j--;
            }
            else break;
        }
       }

       return ans;



    }
};