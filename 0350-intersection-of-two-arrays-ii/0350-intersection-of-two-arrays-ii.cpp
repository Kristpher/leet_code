class Solution {
public:
    void inter(vector<int>&nums1,vector<int>&nums2,vector<int>&v)
    {
         unordered_map<int,int>map1;
        for(int i=0;i<nums1.size();i++)
         {
            map1[nums1[i]]++;
         }
         for(int i=0;i<nums2.size();i++)
         {
            if(map1[nums2[i]]>0){
            map1[nums2[i]]--;
            v.push_back(nums2[i]);
            }
         }
    } 
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       vector<int>v;
        if(nums1.size()>=nums2.size())
        {
          inter(nums1,nums2,v);
        }
        else{
             inter(nums2,nums1,v);
        }
        return v;
    }
};