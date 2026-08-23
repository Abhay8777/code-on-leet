#include<stdio.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int MAXV = 100000;
        vector<int> sp(MAXV+1);
        int i = 0;
        while(i<=MAXV){
            sp[i] = i;
            i++;
        }
        i =2;
        while(i*i<=MAXV){
            if(sp[i]==i){
                int j = i*i;
                while(j<=MAXV){
                    if(sp[j]==j){
                        sp[j] = i;
                    
                    }
                    j+=i;
                }
                
            }
            i++;
        }
        vector<int> resu = nums;
        vector<vector<int>> fac(n);
        i=0;
        while(i<n){
            int x = resu[i];
            while(x>1){
                int p = sp[x];
                fac[i].push_back(p);
                while(x%p==0) x/=p;
            }
            i++;
        }
        vector<int>freq(MAXV +1,0);
        int l = 0;
        int r = 0;
        int dist = 0;
        int ans =0;
        while(r<n){
            int j =0;
            while(j<fac[r].size()){
                int p = fac[r][j];
                if(freq[p] == 0) dist++;
                freq[p]++;
                j++;
            }
            while(dist>k){
                j =0 ;
                while(j<fac[l].size()){
                    int p = fac[l][j];
                    freq[p]--;
                    if(freq[p]==0) dist--;
                    j++;
                }
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};