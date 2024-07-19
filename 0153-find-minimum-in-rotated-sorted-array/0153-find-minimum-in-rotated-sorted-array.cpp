class Solution {
public:
    int findMin(vector<int>& nums) {
        int u = 0;
        int v = nums.size() - 1;
        int k = nums[0];
        

        if (nums[u] < nums[v]) return nums[u];
        
        while (u < v) {
            int mid = (u + v) / 2;
            
   
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }

            if (mid > u && nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }

            if (nums[mid] > k) {
                u = mid + 1;
            } else {
                v = mid - 1;
            }
        }
        
        return nums[u]; 
    }
};
