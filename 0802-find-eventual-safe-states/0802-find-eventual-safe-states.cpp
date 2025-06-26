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
    bool dfs(int i, vi & vis, vi & path_vis, vvi & adj){
        vis[i] = 1;
        path_vis[i] = 1;

        for(auto u : adj[i]){
            if(vis[u]){
                if(path_vis[u]){ return true; }
            }
            else{
             bool tt = dfs(u,vis,path_vis,adj);
             if(tt){ return true;}
            }
        }

        path_vis[i] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vi vis(n,0);
        vi path_vis(n,0);
        vi ans;
        fli(i,0,n-1){
            if(vis[i])continue;
            dfs(i, vis, path_vis, adj);
        }
        fli(i,0,n-1){
            if(vis[i] && path_vis[i])continue;
            ans.push_back(i);
        }
        sort(all(ans));
        return ans;
    }
};