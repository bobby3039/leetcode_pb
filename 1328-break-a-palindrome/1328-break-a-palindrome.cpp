class Solution {
public:
    string breakPalindrome(string s) {
        string ans;
        int n = s.size();
        if(n==1)return ans;

        int i = 0;
        // case1 :- first char not a
        if(s[0] != 'a'){
            s[0] = 'a';
            return s;
        }

        // case 2 ;- starting elements a

        while(s[i] == 'a' )i++;
        if(i >= n/2 ){
            s[n-1] = 'b';
            return s;
        }

        s[i] = 'a';
        return s;   

    }
};