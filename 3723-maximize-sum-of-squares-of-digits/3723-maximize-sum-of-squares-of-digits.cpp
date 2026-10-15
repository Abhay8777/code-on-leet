class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>num*9) return ""; // if num se bada sum hai to us case ko handel karne ke liye
        //trick for maximum square sum 
        int nine = sum/9;
        int remain = sum%9;
        string result(nine, '9'); // means jitna nine ka value hai utna hamko 9 string wala add karna hai
        if(remain>0) {
            result.push_back(remain+'0');
        }
        result.append(num-result.length(),'0'); //usi tarh isko bhi jitna num bach raha hai utna 0 add karna hai 
        return result;
    }
};