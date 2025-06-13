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
    bool safe(int i, int j, int m, int n, vvi &a){
        if(i>0 && j>0 && i<m-1 && j<n-1 && a[i][j]==1)return 1;
        return 0;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vvi a;
        a = grid;
        queue<pii>v;
        fli(i,0,m-1){
            fli(j,0,n-1){
                if(i==0 || j==0 || i == m-1 || j==n-1 ){
                   if(a[i][j]==1){v.push({i,j}); a[i][j]=2;}
                }
            }
        }
        while(v.size()){
            int x = v.front().first;
            int y = v.front().second;
            v.pop();
            if(safe(x-1,y,m,n,a)){v.push({x-1,y}); a[x-1][y]=2;}
            if(safe(x,y-1,m,n,a)){v.push({x,y-1}); a[x][y-1]=2;}
            if(safe(x+1,y,m,n,a)){v.push({x+1,y}); a[x+1][y]=2;}
            if(safe(x,y+1,m,n,a)){v.push({x,y+1}); a[x][y+1]=2;}
        }
        int cnt = 0;
        fli(i,0,m-1){
            fli(j,0,n-1){
                if(a[i][j]==1)cnt++;
            }
        }
        return cnt;
    }
};