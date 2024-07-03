class Solution {
public:
    int bs(vector<int>&nums,int target,bool val)
    {
        int ind=-1;
        int i=0;
        int j=nums.size()-1;
           while(i<=j)
        {
            int mid=i+(j-i)/2;
            if(nums[mid]==target)
            {
                
                ind=mid;
                if(val)
                j=mid-1;
                else
                i=mid+1;
            }
            else if(nums[mid]>target)
           j=mid-1;
            else
            i=mid+1;
            
        }
        return ind;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        int flag=0;
        int ind=0;
        vector<int>v(2,-1);
        v[0]=bs(nums,target,true);
        v[1]=bs(nums,target,false);
        return v;
        
    }
};