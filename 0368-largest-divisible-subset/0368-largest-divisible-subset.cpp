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
      
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n = a.size();
        sort(all(a));
        vi prev(n, -1);
        vi len(n, 1);
        fli(i,0,n-1){
           fli(j,0,i-1){
            if(a[i]%a[j]==0 && len[j]+1 > len[i]){
              len[i] = len[j] + 1;
               prev[i] = j;
            }
           }
        }
        
        int id =0;
        int maxi = 0;
        fli(i,0,n-1){
            if(len[i]>maxi){
                maxi = len[i];
                id = i;
            }
        }
        vector<int>ans;
        while(id!=-1){
            ans.push_back(a[id]);
            id = prev[id];
        }

        return ans;
    }
};