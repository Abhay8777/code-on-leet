class Solution {
public:
    int solve(int start, int end, string &word, int k){
        int result = 0;
        for(int unique_char =1; unique_char<=26 && unique_char*k<=end-start+1; unique_char++){
            vector<int>count(26,0);
            int goodboy = 0;
            int i =start;
            int window_length = unique_char*k;
            for(int j =start; j<=end; j++){
                char ch = word[j];
                count[ch - 'a']++;
                if(count[ch-'a']==k) goodboy++;
                else if(count[ch-'a'] == k+1) goodboy--;
                
                if(j-i+1 > window_length){
                    if(count[word[i] - 'a'] == k){
                        goodboy--;
                    }
                    else if(count[word[i]-'a'] == k+1) goodboy++;
                    count[word[i]-'a']--;
                    i++;
                }
                if(goodboy == unique_char) result+=1;
            }
        }
        return result;
    }
    int countCompleteSubstrings(string word, int k) {
        int n = word.length();
        int last = 0;
        int result= 0;
        for(int i = 1;i<=n;i++){
            if(i==n || abs(word[i]-word[i-1])>2){
                result+=solve(last,i-1, word, k);
                last = i;
            }
        }
        return result;
    }
};