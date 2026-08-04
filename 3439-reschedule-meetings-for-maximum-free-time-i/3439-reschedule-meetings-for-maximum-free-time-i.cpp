class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gap(n + 1);
        gap[0] = startTime[0];
        int i = 1;
        while(i < n){
            gap[i] = startTime[i] - endTime[i - 1];
            i++;
        }
        gap[n] = eventTime - endTime[n - 1];
        int window = k + 1;
        long long sum = 0;
        i = 0;
        while(i < window){
            sum += gap[i];
            i++;
        }
        long long ans = sum;
        int left = 0;
        int right = window;
        while(right < gap.size()){
            sum += gap[right];
            sum -= gap[left];
            if(sum > ans)
                ans = sum;
            left++;
            right++;
        }
        return ans;
    }
};