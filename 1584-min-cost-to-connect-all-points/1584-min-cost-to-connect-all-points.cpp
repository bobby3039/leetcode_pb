class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>>dist(n, vector<int>(n,0));
        for(int i = 1; i < n; i++){
           for(int j = 0; j < i; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int d = abs(x1-x2) + abs(y1-y2);
                dist[i][j] = dist[j][i] = d;
           }
        }
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        pq.push({0,0});
        //wt,node,parent(if needed)
        vector<int>vis(n,0);
        int sum  = 0;
        while(pq.size()){
            int node  = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(vis[node])continue;
            vis[node] = 1;
            sum += wt;
            for(int i = 0; i < n; i++){
                if(i == node)continue;
                if(vis[i])continue;

                pq.push({dist[i][node], i});
            }


        }
        return sum;


    }
};