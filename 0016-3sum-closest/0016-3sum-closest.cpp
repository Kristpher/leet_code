class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum=nums[0]+nums[1]+nums[2];
        int minsum=0;
        int first=0;
        int last=0;
        for(int i=0;i<nums.size();i++)
        {
           first=i+1;
           last=nums.size()-1;
          
           while(first<last)
           {
             minsum=nums[first]+nums[i]+nums[last];
            if(abs(minsum-target)<abs(sum-target)){
            sum=minsum;
            }
            if(minsum>target)
            last--;
            else if(minsum<target)
            first++;
            else
            return minsum;
           }
        }
        return sum;
    }
};