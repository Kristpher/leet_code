class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      int maxim=0;
      int sum=0;
      unordered_map<int,int>map1;
      map1[0]=-1;
       for(int i=0;i<nums.size();i++)
       {
        if(nums[i])
        sum++;
        else
        sum--;
        
        if(map1.find(sum)!=map1.end())
        {
            maxim=max(maxim,i-map1[sum]);
        }
        else
        map1[sum]=i;
       }
     
        return maxim;
    }
};