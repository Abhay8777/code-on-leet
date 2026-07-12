class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.length();
        
        vector<int> leftmost(n,0);
        vector<int> rightmost(n,0);
        unordered_map<char,int>mp;
        int i = 0;
        int j = 0;
        while(j<n){
            mp[s[j]]++;
            while(mp['0']>k&&mp['1']>k){
                mp[s[i]]--;
                i++;
            }
            leftmost[j] = i;
            j++;
        }
        mp.clear();
        i = n-1;
        j = n-1;
        while(j>=0){
            mp[s[j]]++;
            while(mp['0']>k&&mp['1']>k){
                mp[s[i]]--;
                i--;
            }
            rightmost[j] =  i;
            j--;
        }

        vector<long long> validsubstr(n,0);
        for(int j = 0;j<n;j++){
            validsubstr[j] = j - leftmost[j]+1;
        }
        vector<long long>cumSum(n,0);
        cumSum[0] = validsubstr[0];
        for(int i = 1;i<n;i++){
                cumSum[i] = cumSum[i-1]+validsubstr[i];
         }
        
        vector<long long> result;
        for(vector<int>& query : queries) {
            int low  = query[0];
            int high = query[1];

            int validRightIdx = min(high, rightmost[low]);

            long long length = validRightIdx - low + 1;

            long long tempResult = length * (length+1)/2;

            tempResult += cumSum[high] - cumSum[validRightIdx];

            result.push_back(tempResult);


        }

        return result;
      
    }
};