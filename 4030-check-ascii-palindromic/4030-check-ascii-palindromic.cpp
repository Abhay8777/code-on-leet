class Solution {
public:
    bool isPalindromic(string s) {
        string resu = "";
        for(char ch : s){
            int x = ch;
            for(int i=7; i>=0; i--){
                resu += ((x>>i) & 1)+'0';
            }
        }
        int star = 0;
        int e = resu.size()-1;
        while(star<e)
        {
            if(resu[star] != resu[e]){
                return false;
            }
            star++;
            e--;
        }
        return true;
    }
};