class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> out;
        for (int i = 0; i < nums.size(); i++) {   
            int temp = abs(nums[i]) - 1; 
            if (nums[temp] < 0) {
                out.push_back(temp + 1); 
            } else {
                nums[temp] *= -1; 
            }
        }
        return out;
    }
};
