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
    bool safe(int i, int j, int n, vvi &grid, vvi &dist){
        if(i>=0 && j>=0 && i<=n-1 && j<=n-1 && grid[i][j]==0 && dist[i][j]==1e9)return 1;
        return 0;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vvi dist(n+1, vi(n+1,1e9));
        if(grid[0][0]!=0)return -1;
        if(grid[n-1][n-1]!=0)return -1;
        queue<pii>q;
        q.push({0,0});
        dist[0][0]=1;
        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(safe(x-1,y,n,grid,dist)){q.push({x-1,y}); dist[x-1][y]= dist[x][y]+1;}
            if(safe(x,y-1,n,grid,dist)){q.push({x,y-1}); dist[x][y-1]= dist[x][y]+1;}
            if(safe(x+1,y,n,grid,dist)){q.push({x+1,y}); dist[x+1][y]= dist[x][y]+1;}
            if(safe(x,y+1,n,grid,dist)){q.push({x,y+1}); dist[x][y+1]= dist[x][y]+1;}
            if(safe(x-1,y-1,n,grid,dist)){q.push({x-1,y-1}); dist[x-1][y-1]= dist[x][y]+1;}
            if(safe(x-1,y+1,n,grid,dist)){q.push({x-1,y+1}); dist[x-1][y+1]= dist[x][y]+1;}
            if(safe(x+1,y-1,n,grid,dist)){q.push({x+1,y-1}); dist[x+1][y-1]= dist[x][y]+1;}
            if(safe(x+1,y+1,n,grid,dist)){q.push({x+1,y+1}); dist[x+1][y+1]= dist[x][y]+1;}
        }

        if(dist[n-1][n-1]==1e9)return -1;
        return dist[n-1][n-1];



    }
};