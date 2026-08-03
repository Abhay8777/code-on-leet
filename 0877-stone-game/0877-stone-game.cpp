class Solution {
public:
    int t[501][501];
    int solve(vector<int>& piles,int alice,int bob){
        if (alice>bob) return 0;
        if(t[alice][bob]!= -1) return t[alice][bob];
        int take_i = piles[alice]+min(solve(piles, alice+2, bob),solve(piles, alice+1, bob-1));
        int take_j = piles[bob] + min(solve(piles, alice, bob-2),solve(piles, alice+1, bob-1));
        return t[alice][bob]=max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        memset(t,-1,sizeof(t));
        int n = piles.size();
        int sum = accumulate(begin(piles),end(piles),0);
        int p1 = solve(piles, 0, n-1);
        int p2 = sum-p1;
        return p1>p2;
    }
};