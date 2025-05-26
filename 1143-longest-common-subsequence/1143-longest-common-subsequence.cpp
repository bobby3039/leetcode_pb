class Solution {
public:
    int f(int i1, int i2, string &s1, string& s2,vector< vector<int> >&dp){
      if(i1==-1 || i2==-1) return 0;
      if(dp[i1][i2]!=-1)return dp[i1][i2];

      if(s1[i1]==s2[i2])return 1+f(i1-1, i2-1, s1,s2,dp);
      return  dp[i1][i2] = max(f(i1-1, i2, s1,s2,dp), f(i1, i2-1, s1,s2,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector< vector<int> >dp(n+1, vector<int>(m+1,-1));
        return f(n-1, m-1, text1, text2,dp);
    }
};