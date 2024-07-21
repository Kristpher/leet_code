class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0,sum=0;
        unordered_map<int,int>map1;
         map1[0]=1;
         if(k==0)
         return 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int r=sum%k;
           if (map1.count(r)) {
                count++;
                map1[r]=i;
            }
            else{
             map1[r]=i;   
             //cout<<i<<" ";
            }
        }
        return count;
    }
};