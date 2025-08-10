class Solution {
public:
    bool chk(int n, vector<int>&mp){
       vector<int>mp2(10,0);
       int k = n;
       while(k>0){
       mp2[(k%10)]++;
       k/=10;
       }

       return (mp == mp2);
    }

    bool reorderedPowerOf2(int n) {
      
       int k = n;
       vector<int>mp(10,0);
       while(k>0){
       mp[(k%10)]++;
       k/=10;
       }

       vector<int>v;
       for(int i=1; i<=1e9; i*= 2){
          bool tt = chk(i,mp);
          if(tt)return 1;
       }

       return 0;


    }
};