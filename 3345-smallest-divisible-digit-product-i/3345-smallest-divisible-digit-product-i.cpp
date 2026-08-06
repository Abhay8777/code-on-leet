class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            string s = to_string(n);
             int prod = 1;
            for(char ch: s){
                int digit = ch-'0';
                prod*=digit;
            }
            if (prod % t == 0)
                return n;
            n++;
        }
    }
};