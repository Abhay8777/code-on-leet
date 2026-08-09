class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices. rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());
        int n = prices.size();
        int m = discounts.size();
        double ans = 0;
        int resu = min(n,m);
        for(int i = 0;i<resu;i++) ans+=(double)prices[i] * (100-discounts[i])/100.0;
        for(int i =resu;i<n;i++){
             ans+=prices[i];
        }
        return ans;
    }
};