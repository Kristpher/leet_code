class Solution {
public:
    int mod = 1e9 + 7;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> out;

        for (int i = 0; i < nums.size(); i++) {
            long long sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                out.push_back(sum % mod); 
            }
        }


        sort(out.begin(), out.end());

       
        long long total = 0;
        for (int i = left - 1; i < right; i++) {
            total = (total + out[i]) % mod;
        }

        return total;
    }
};
