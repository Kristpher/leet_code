class Solution {
public:
     static bool sor(const pair<int, int>& a, const pair<int, int>& b) {
     
        return a.second < b.second;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++)
        {
          int a=nums[i];
          string temp=to_string(a);
          int k=0;
          while(k<temp.length()){
            int b;
            string temp2="";
            temp2+=temp[k];
            b=stoi(temp2);
            b=mapping[b];
            temp[k]=b+'0';
            k++;
          }
          v.push_back(make_pair(nums[i],stoi(temp)));
        }
        sort(v.begin(),v.end(),sor);
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=v[i].first;
            //cout<<v[i].second<<" ";
        }
        return nums;
    }
};