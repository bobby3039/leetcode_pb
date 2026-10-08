class Solution {
public:
    int numRescueBoats(vector<int>& people, int lim) {
        int n = people.size();
        sort(people.begin(), people.end(), greater<int>());
        int i = 0, j = n-1;
        int cnt = 0;
        while(i <= j){

          int limit = lim;
          // take 2 people
          if(people[i] + people[j] <= limit){
                limit -= (people[i] + people[j]);
                i++;
                j--;
          }
         //take 1 people
          else{
            i++;
          }
          
          cnt++;
        }

        return cnt;
    }
};