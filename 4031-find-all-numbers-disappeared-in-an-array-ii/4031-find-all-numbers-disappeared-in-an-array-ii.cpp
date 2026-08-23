#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<int> resu = nums;
        sort(begin(resu), end(resu));
        vector<vector<int>> ans;
        long long curr = lower;
        for(int x: resu){
            if(x<curr){
                continue;
            }
            if(x>upper) break;
            if(x>curr){
                ans.push_back({(int)curr, x-1});
                    
            }
            curr = (long long)x+1;
        }
        if(curr<=upper){
            ans.push_back({(int)curr, upper});
            
        }
        return ans;
    }
};