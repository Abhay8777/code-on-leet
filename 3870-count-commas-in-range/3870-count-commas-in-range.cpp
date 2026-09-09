class Solution {
public:
    typedef long long ll;
    int countCommas(int n) {
        ll result = 0;
        ll lower = 1000;
        ll comma = 1;
        while(lower<=n){
            ll upper = lower*1000-1;
            if(upper>n) upper = n;
            ll countNo = upper-lower+1;
            result = (countNo*comma);
            lower =  (lower*1000);
            comma+=1;
        }
        return result;
    }
};