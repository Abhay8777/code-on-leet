class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mp(26,0);
        int result = 0;
        for(char &ch: word){
            mp[ch-'a']++;
        }
        sort(begin(mp),end(mp),greater<int>()); // we first store the greater number of frequency
        for(int i = 0;i<26;i++){
            int pass  = i/8 +1;
            result+= pass*mp[i];
        }
        return result;
    }
};