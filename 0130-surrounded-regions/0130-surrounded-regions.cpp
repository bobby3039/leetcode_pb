#define le cout<<endl
#define yes cout<<"YES"
#define no cout<<"NO"
#define vi vector<int>
#define vvi vector<vector<char>>
#define pii pair<int,int>
#define fl(i,n) for(int i=0;i<(n);++i)
#define fli(i,j,n) for(int i=(j);i<=(n);++i)
#define fld(i,j,n) for(int i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
const int MOD = 1e9+7;

class Solution {
public:
    bool safe(int i, int j, int n, int m, vvi &a){
    if(i>0 && j>0 && i<n-1 && j<m-1 && a[i][j]=='O') return 1;
    return 0;
     }
    void solve(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
       queue<pii>q;

    fli(i,0,n-1){
        fli(j,0,m-1){
            if(a[i][j]=='O'){
                if(i==0 || j==0 || i==n-1 || j==m-1){q.push({i,j}); a[i][j]='k';}
            }
        }
    }
    
    while(q.size()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if( safe(x-1,y,n,m,a) ){q.push({x-1,y}); a[x-1][y]='k'; }
        if( safe(x,y-1,n,m,a) ){q.push({x,y-1}); a[x][y-1]='k'; }
        if( safe(x+1,y,n,m,a) ){q.push({x+1,y}); a[x+1][y]='k'; }
        if( safe(x,y+1,n,m,a) ){q.push({x,y+1}); a[x][y+1]='k'; }

    }

     fli(i,0,n-1){
        fli(j,0,m-1){
            if(a[i][j]=='O')a[i][j]='X';
            if(a[i][j]=='k')a[i][j]='O';
        }
    }


    }
};