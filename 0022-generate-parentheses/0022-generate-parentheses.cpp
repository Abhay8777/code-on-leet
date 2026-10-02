class Solution {
public:
    vector<string> result;
    int n;
    
    bool isValid(string &temp) {
        int open = 0;
        
        for(const char &ch : temp) {
            if(ch == '(')
                open++;
            else
                open--;
            if(open < 0)
                return false;
        }
        return open==0;
    }
    
    void generate(string temp, int idx) {
        if(idx == 2*n) {
            if(isValid(temp)) {
                result.push_back(temp);
            }
            return;
        }
        
        temp[idx] = '(';
        generate(temp, idx+1);
        temp[idx] = ')';
        generate(temp, idx+1);
        
    }
    
    vector<string> generateParenthesis(int N) {
        result.clear();
        n = N;
        string temp(2*n,' ');
        
        generate(temp, 0);
        return result;
    }
};