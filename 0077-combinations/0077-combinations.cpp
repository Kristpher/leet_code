class Solution {
public:
    void recur(vector<vector<int>>&out,vector<int>&v,int k,vector<int>&temp,int n)
    {
        if(k==temp.size())
        {
           out.push_back(temp);
           return ;
        }
       
        for(int i=n;i<v.size();i++)
        {
           temp.push_back(v[i]);
           recur(out,v,k,temp,i+1);
           temp.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
     vector<vector<int>>out;
     vector<int>v(n);
     for(int i=0;i<n;i++){
        v[i]=i+1;
     }
    vector<int>temp;

     recur(out,v,k,temp,0);
     return out;   
    }
};