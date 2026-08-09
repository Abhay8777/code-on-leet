#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        pair<vector<int>, vector<int>> paring = {parent, nums};
        vector<vector<int>> child(n);
        for(int i =1;i<n;i++) child[parent[i]].push_back(i);
        vector<int> down(n,0);
        down[0] =1;
        queue<int>q;
        q.push(0);
        int hight =1;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for(int c: child[frontNode]){
                down[c] = down[frontNode]+1;
                hight = max(hight, down[c]);
                q.push(c);
            }
        }
        long long res = 0;
        for(int i = 0;i<n;i++) res+= 1LL * nums[i] * (hight-down[i]+1);
        return res;
    }
};