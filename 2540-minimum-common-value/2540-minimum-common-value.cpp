class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
     int i=0;
     int j=0;
     int flag=0;
     while(i<nums1.size()&&j<nums2.size())
     {
        if(nums1[i]==nums2[j]){
        flag=1;
        break;
        }
        else if(nums1[i]>nums2[j])
        j++;
        else
        i++;
     }
     if(flag)
     return nums1[i];
     return -1;
    }
};