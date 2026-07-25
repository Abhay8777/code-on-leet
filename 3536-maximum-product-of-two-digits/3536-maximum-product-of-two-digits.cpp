class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
        while(n > 0){
            digits.push_back(n % 10);
            n /= 10;
        }
        int m = digits.size()-1;
        sort(digits.begin(),digits.end());
        int ans = digits[m]*digits[m-1];
        return ans;
    }
};