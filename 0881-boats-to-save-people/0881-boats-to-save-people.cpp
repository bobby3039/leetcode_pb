class Solution {
public:
    int numRescueBoats(vector<int>& people, int lim) {
        int n = people.size();
        sort(people.begin(), people.end(), greater<int>());
        int i = 0, j = n-1;
        int cnt = 0;
        while(i <= j){

          int limit = lim;
          if(people[i] == limit){
            cnt++;
            i++;
            continue;
          }

          if(people[i] + people[j] <= limit){
                limit -= people[i] + people[j];
                i++;
                j--;
                cnt++;
                continue;
          }

          if(people[i] < limit){
             cnt++;
             i++;
          }

        }
        return cnt;
    }
};