class Solution {
public:
    int brokenCalc(int s, int target) {
        
        int ans  = 0;
        while(target != s){

            if(target%2 == 0){
                if(target > s){
                    target/=2;
                    ans++;
                }
                else{
                    target++;
                    ans++;
                }
            }

            else{
                target++;
                ans++;
            }
       
        }

        return ans;

}
};