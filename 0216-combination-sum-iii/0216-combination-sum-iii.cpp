class Solution {
public:
   vector<int>temp;
   int sum(vector<int>&temp){
    int add=0;
    for(int i=0;i<temp.size();i++)
    add+=temp[i];
    return add;
   }
   void recur(vector<int>&v,int k,int i,int n,vector<vector<int>>&mainv)
   {
   
     if(temp.size()>k)
    return;
    if(sum(temp)==n && temp.size()==k) 
    {
        mainv.push_back(temp);
    
     return;
    }
       if (i == v.size() || sum(temp) > n) 
            return;
   
    temp.push_back(v[i]);
    recur(v,k,i+1,n,mainv);
    temp.pop_back();
      recur(v,k,i+1,n,mainv);

   }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>mainv;
        recur(v,k,0,n,mainv);
        return mainv;
    }
};