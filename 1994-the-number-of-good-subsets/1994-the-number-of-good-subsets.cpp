const long long MOD = 1e9+7;
class Solution {
public:
    long long hcf(long long a, long long b){
        if(b==0)return a;
        return hcf(b,a%b);
    }

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    int numberOfGoodSubsets(vector<int>& nums) {
        vector<long long>possible = {
            2,3,5,7,11,13,17,19,23,29,6,10,14,15,21,22,26,30
    };


        
        long long cnt1 = 0;
        for(auto x : nums){
            cnt1 += (x==1);
        }
        
        // map<long long,long long>freq;
        // for(auto x : nums)freq[x]++;

        map<long long,long long>mp;
        long long ans = 0;
        for(auto x : nums){
            for(auto y : possible){
                if(x==y)mp[x]++;
            }
        }

        vector<pair<long long,long long>>v;
        for(auto it :mp){
            v.push_back({it.first, it.second});
        }


        long long sz = v.size();
        long long mx = 1LL<<sz;

        // for(auto it : v){
        //     cout<<it.first<<":"<<it.second<<" ";
        // }cout<<endl;

        for(long long i=1; i<mx; i++){

            long long product = 1;
            long long pro = 1;
            //vector<int>demo;
            bool chk = 0;
            for(long long j = 0; j<sz; j++){
                if( (i&(1LL<<j)) ){
                   long long value = v[j].second;
                   long long tt = hcf(product, v[j].first);

                   if(tt != 1){chk = 1;break;}
                   product *= (v[j].first);
                   pro = (pro*value)%MOD;
                  // demo.push_back(v[j].first);
                  
                }
            }
            if(chk)continue;
            ans = (ans+pro)%MOD;
           // for(auto it : demo)cout<<it<<" ";
           // cout<<endl;
        }

        return (ans*power(2,cnt1))%MOD;

    }
};