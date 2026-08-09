#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        vector<vector<int>> box = mat;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>prefixSum(n+1,vector<int>(m+1, 0) );
        for(int i = 0; i<n;i++){
            for(int j = 0; j<m;j++){
                prefixSum[i+1][j+1]=mat[i][j]+prefixSum[i][j+1]+prefixSum[i+1][j]-prefixSum[i][j];
                
            }
        }
        auto check = [&](int a, int b, int h){
            int  sum = prefixSum[a+h][b+h]-prefixSum[a][b+h]-prefixSum[a+h][b]+prefixSum[a][b];
            return sum == h*h;
        };
        auto possible = [&](int k){
            int minRow = INT_MAX;
            int maxRow = INT_MIN;
            int minCol = INT_MAX;
            int maxCol = INT_MIN;
            int count = 0;
            for(int i =0; i+k<=n;i++){
                for(int j = 0;j+k<=m;j++){
                    if(check(i,j,k)){
                        count++;
                        minRow = min(minRow, i);
                        maxRow = max(maxRow, i);
                        minCol = min(minCol, j);
                        maxCol = max(maxCol,j);
                        if(count>=2 && (maxRow - minRow>=k || maxCol - minCol>=k)){
                            return true;
                        }
                    }
                }
            }
            return false;
        };
        int down = 1;
        int high = min(n,m);
        int res = 0;
        while(down<=high){
            int mid = down+(high-down) /2;
            if(possible(mid)){
                res =  mid;
                down = mid+1;
                
            }
            else{
                high = mid-1;
            }
        }
        return res*res;
    }
};