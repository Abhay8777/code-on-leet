class Solution {
public:
    int t[501][501];
    int solve(vector<int>& piles,int alice,int bob){
        if (alice>bob) return 0;
        if(t[alice][bob]!= -1) return t[alice][bob];
        int take_i = piles[alice]-solve(piles, alice+1, bob);
        int take_j = piles[bob] - solve(piles, alice, bob-1);
        return t[alice][bob]=max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        memset(t,-1,sizeof(t));
        int n = piles.size();
        return solve(piles, 0, n-1)>0;
    }
};