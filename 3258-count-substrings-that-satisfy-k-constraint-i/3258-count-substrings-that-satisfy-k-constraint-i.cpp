class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();
        int result = 0;
        for(int i =0;i<n;i++){
            int count0 =0;
            int count1 = 0;
            for(int j =i;j<n;j++){
                if(s[j]=='0') count0++;
                else count1++;
                if(count0<=k || count1<=k){
                    result+=1;
                }
                else break;
            }
        }
        return result;

    }
};