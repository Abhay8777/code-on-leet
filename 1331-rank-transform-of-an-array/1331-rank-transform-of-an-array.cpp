class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>vec = arr;
        sort(begin(vec), end(vec));
        unordered_map<int,int> rank;
        int r =1;
        for(int &x : vec){
            if(rank.count(x) == 0){
                rank[x] = r;
                r++;
            }
        }
        for(int &v:arr){
            v = rank[v];
        }
        return arr;
    }
};