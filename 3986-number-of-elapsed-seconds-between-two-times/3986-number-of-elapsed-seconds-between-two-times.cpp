class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        auto everysec = [](string t){
            long long valu[3] = {0};
            int idx = 0;
            for(int i =0;i<t.size();i++){
               if(t[i] == ':'){
                idx++;
               }
               else{
                valu[idx] = valu[idx] *10 + (t[i]-'0');
               }
            }
            return valu[0]* 3600 + valu[1]*60 +valu[2];
        };
        return everysec(endTime) - everysec(startTime);
        
    }
};