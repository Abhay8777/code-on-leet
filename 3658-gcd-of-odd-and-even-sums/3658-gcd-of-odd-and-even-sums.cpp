class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int sumEven = 0;
        for(int i = 1; i<=n;i++){
            sumEven +=i*2;
        }
        for(int i = 1; i<=n;i++){
            sumOdd += 2*i -1;
        }
        return sumEven-sumOdd;
    }
};