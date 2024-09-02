class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int i = 0; i < chalk.size(); i++) {
            sum += chalk[i];
        }
        k %= sum; 
        int i = 0;
        while(k >= chalk[i]) {
            k -= chalk[i];
            i++;
        }
        return i;
    }
};
