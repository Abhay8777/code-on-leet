class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        vector<int>cnt(3,0);
        for(char ch: s){
            cnt[ch-'a']++;
        }
        if(k==0) return 0;
        if(cnt[0]<k||cnt[1]<k||cnt[2]<k) return-1;
        int i =0, j=0;
        int maxim = 0;
        while(j<n){
            cnt[s[j]-'a']--;
            while(cnt[0]<k||cnt[1]<k||cnt[2]<k){
                cnt[s[i]-'a']++;
                i++;
            }
            maxim=max(maxim, j-i+1);
            j++;
        }
        return n-maxim;
    }
};