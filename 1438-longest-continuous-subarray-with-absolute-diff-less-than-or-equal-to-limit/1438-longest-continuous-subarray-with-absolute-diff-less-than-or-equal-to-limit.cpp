class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0;
        int r = 0;
        int maxim = 0;
        int maxelem = nums[0];
        int minelem = nums[0];
        
        while (r < nums.size()) {
    
            maxelem = max(maxelem, nums[r]);
            minelem = min(minelem, nums[r]);
            
          
            if (maxelem - minelem <= limit) {
                maxim = max(maxim, r - l + 1);
                r++;
            } else {
                
                l++;
                  maxelem = nums[l];
                minelem = nums[l];
                for (int i = l; i <= r; i++) {
                    maxelem = max(maxelem, nums[i]);
                    minelem = min(minelem, nums[i]);
                }
                r++;
            }
        }
        
        return maxim;
    }
};
