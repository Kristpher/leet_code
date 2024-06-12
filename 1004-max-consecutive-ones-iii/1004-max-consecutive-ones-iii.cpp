class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int start=0;
    int end=nums.size();
    int p=0;
    int mid=0,maxim=0;
    while(start<end)
    {
        if(nums[start]==0)
        p++;
        if(p>k)
        {
            if(nums[mid]==0){
            p--;
            }
            mid++;
            
        }
        maxim=max(maxim,start-mid+1);  
        start++;
      
    }
            return maxim;
        }
    };