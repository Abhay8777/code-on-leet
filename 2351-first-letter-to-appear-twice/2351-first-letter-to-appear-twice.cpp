class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int>freq(26,0);
        for(char ch: s){
            freq[ch-'a']++;
            if(freq[ch-'a'] == 2){ // frequency us ascaii ke positioon pe
                return ch;
                break;
            }
        }
        return -1;
    }
};