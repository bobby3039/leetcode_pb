class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

         priority_queue<long long, vector<long long>, greater<long long>>available;
         //room_no
         priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>>inUse;
         //{end,room_no}
         vector<long long>rooms(n,0);

         for(long long i = 0; i < n; i++)available.push(i);

         available.pop();
         rooms[0] = 1;
         inUse.push({meetings[0][1], 0});

         for(long long i = 1; i < meetings.size(); i++){
            long long st = meetings[i][0];
            while(inUse.size() && inUse.top().first <= st){
                available.push(inUse.top().second);
                inUse.pop();
            }
            if(!available.empty()){
                inUse.push({meetings[i][1],available.top()});
                rooms[available.top()]++;
                available.pop();
            }
            else{
                 long long n_end = inUse.top().first+meetings[i][1]-meetings[i][0];
                 long long room = inUse.top().second;
                 rooms[room]++;
                 inUse.pop();
                 inUse.push({n_end,room});
            }
            
         }

         long long ans = 0;
         long long mx = 0;
         for(long long i = 0; i < n; i++){
            if(mx < rooms[i]){
                mx = rooms[i];
                ans = i;
            }
         }
         return ans;

         

    }
};