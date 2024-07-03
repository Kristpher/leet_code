class Solution {
public:
    bool bs(vector<int>& nums,int u,int v, int target){
        while(u<=v)
        {
            int mid=(u+v)/2;
            //cout<<" "<<mid;
            if(nums[mid]==target)
            {
                return true;
            }
            else if(target>nums[mid])
            u=mid+1;
            else
            v=mid-1;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
      if(nums.size()==1)
      {
        if(target==nums[0])
        return true;
        else
        return false;
      }  
      int piv=0;
      bool check;
      for(int i=1;i<nums.size();i++){
      if(nums[i]<nums[i-1])
      piv=i;
      }
      //cout<<piv;
      int u=0;
      int v=nums.size()-1;
      if(piv==0)
      {
        return bs(nums,u,v,target);
      }
      if(nums[0]>target)
      {
        u=piv;
        check=bs(nums,u,v,target);
      }
      else{
        v=piv-1;
     check=bs(nums,u,v,target);
      }
      
    return check;
    }
};