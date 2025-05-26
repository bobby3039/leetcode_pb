#define le cout<<endl
#define yes cout<<"YES"
#define no cout<<"NO"
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define fl(i,n)   for(int i=0;i<(n);++i)
#define fli(i,j,n)   for(int i=(j);i<=(n);++i)
#define fld(i,j,n)   for(int i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
const int MOD = 1e9+7;
class Solution {
public:
    bool chk(string &a , string& b){
         if(a.size()+1 != b.size()) return 0;
        int i = 0;
        int j = 0;
        while(j<b.size()){
         if(a[i]==b[j]){
            i++;j++;
         }
         else{
            j++;
         }
        }
        return (i==a.size());
    }

    int longestStrChain(vector<string>& s) {
        sort(all(s),
        [](string &s1, string &s2){
            return s1.length()<=s2.length();
        }
        );
        
         int n = s.size();
         
         vi dp(n,1);
         fli(i,0,n-1){
            fli(j,0,i-1){
                bool tt = chk(s[j], s[i]);
                if(tt && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    
                }
            }
         }
         
         int maxi = 0;
         fli(i,0,n-1){
            if(dp[i]>maxi){maxi = dp[i];}
         }
         return maxi;
    }
};