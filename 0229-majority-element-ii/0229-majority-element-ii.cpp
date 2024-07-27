class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     vector<int>out;
     int c1=0;
     int c2=0;
     int val1=INT_MIN;
     int val2=INT_MIN;
     for(auto c:nums){
        if(!c1 && val2!=c){
            c1=1;
            val1=c;
        }
        else if (!c2 && val1!=c){
            c2=1;
            val2=c;
        }
        
        else if(c1 &&val1==c)
            c1++;
        else if (c2 &&val2==c)
            c2++;
        else{
            c1--;
            c2--;
        }    
        

     
     }
     c1=0;
     c2=0;
     for(int i=0;i<nums.size();i++)
     {
      if(val1==nums[i])
      c1++;
      else if(val2==nums[i])
      c2++;
     }
     if(c1>floor(nums.size()/3))
     out.push_back(val1);
     if(c2>floor(nums.size()/3))
     out.push_back(val2);
     return out;
    }
};