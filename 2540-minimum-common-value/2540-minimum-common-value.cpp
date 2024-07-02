class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
      unordered_map<int,int>map1;
      for(int i=0;i<nums1.size();i++)
      {
        map1[nums1[i]]=1;
      }
      int val=-1;
      for(int i=0;i<nums2.size();i++)
      {
        if(map1[nums2[i]]==1){
        val=nums2[i];
        break;
        }
      }   
      return val;
    }
};