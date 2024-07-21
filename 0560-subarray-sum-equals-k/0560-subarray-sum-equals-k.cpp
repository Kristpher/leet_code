#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> map1;
        map1[0] = 1; 
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            if (map1.find(sum - k) != map1.end()) {
                count += map1[sum - k];
            }
            
            map1[sum]++;
        }
        return count;
    }
};
