class Solution {
public:
    typedef long long ll;
    int minimumCost(vector<int>& nums, int k) {
        const ll MOD = 1e9+7;
        const ll inv2 = 500000004;
        vector<int> pock = nums;
        ll jaruri = k;
        ll op = 0;
        ll cost = 0;
        for(ll t:nums){
            if(jaruri<t){
                ll need = t - jaruri;
                ll ops = (need + k-1)/k;
                ll f = (op+1)%MOD;
                ll l = (op+ops)%MOD;
                ll sum = ((f+l)%MOD)*(ops%MOD)%MOD;
                sum = sum * inv2 %MOD;
                cost=(cost+sum)%MOD;
                op +=ops;
                jaruri +=ops*1LL*k;
            }
            jaruri -=t;
        }
        return cost%MOD;
    }
};