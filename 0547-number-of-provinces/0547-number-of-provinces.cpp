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
    void dfs(int i, vector<vector<int>>& adj , vi & vis){
        vis[i]=1;
        for(int x = 0; x<adj[i].size() ; x++){
            if(adj[i][x] == 0)continue;
            if(vis[x])continue;
            dfs(x,adj,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vi vis(n+1,0);
        int cnt = 0;
        fli(i,0,n-1){
          if(vis[i]==0){
            dfs(i,adj,vis);
            cnt++;
          }
        }
        return cnt;
    }
};