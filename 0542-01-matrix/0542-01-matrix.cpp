#define le cout<<endl
#define yes cout<<"YES"
#define no cout<<"NO"
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define fl(i,n) for(int i=0;i<(n);++i)
#define fli(i,j,n) for(int i=(j);i<=(n);++i)
#define fld(i,j,n) for(int i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
const int MOD = 1e9+7;

class Solution {
public:
   bool safe(int i, int j, int m, int n){
    return i >= 0 && j >= 0 && i < m && j < n;
}


    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int m = mat.size();
      int n = mat[0].size();

      vvi vis(m ,vi(n,1e5));
      vector<pii>v;

      fli(i,0,m-1){
        fli(j,0,n-1){
            if(mat[i][j]==0){v.push_back({i,j}); vis[i][j]=0;}
        }
      }

      fli(i,0,v.size()-1){
        int x = v[i].first;
        int y = v[i].second;
        if(safe(x-1,y,m,n) && vis[x-1][y] == 1e5 ){vis[x-1][y] = vis[x][y]+1; v.push_back({x-1,y}); }
        if(safe(x,y-1,m,n) && vis[x][y-1] == 1e5  ){vis[x][y-1] = vis[x][y]+1; v.push_back({x,y-1}); }
        if(safe(x+1,y,m,n) && vis[x+1][y] == 1e5  ){vis[x+1][y] = vis[x][y]+1; v.push_back({x+1,y}); }
        if(safe(x,y+1,m,n) && vis[x][y+1] == 1e5  ){vis[x][y+1] = vis[x][y]+1; v.push_back({x,y+1}); }
      }
      return vis;
    }
};