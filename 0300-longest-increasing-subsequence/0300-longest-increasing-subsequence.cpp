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
    int lengthOfLIS(vector<int>& a) {
      vi temp;
      temp.push_back(a[0]);
      fli(i,1,a.size()-1){
        if(a[i]>temp.back())temp.push_back(a[i]);
        else{
            int id = lower_bound(all(temp), a[i])-temp.begin();
            temp[id] = a[i];
        }
      }
      return temp.size();
    }
};