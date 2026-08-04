class Solution {
public:
    int n;
    int t[2][101][101];
    int solveforAlice(vector<int>& piles, int person, int idx, int M){
        if(idx>=n){
            return 0;
        }
        if(t[person][idx][M]!=-1) return t[person][idx][M];
        int result = (person == 1)? -1 : 1e9;
        int stones =0;
        for(int x =1;x<=min(2*M,n-idx);x++){
            stones += piles[idx+x-1];
            if(person == 1){
                result = max(result, stones+solveforAlice(piles,0,x+idx,max(M,x)));
            }
            else{
                result = min(result, solveforAlice(piles,1,x+idx,max(M,x)));
            }
        }
        return  t[person][idx][M]=result;

    }
    int stoneGameII(vector<int>& piles) {
        n  = piles.size();
        memset(t,-1,sizeof(t));
        return solveforAlice(piles, 1, 0, 1);
    }
};