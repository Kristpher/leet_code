class Solution {
public:
    void recur(   set<vector<int>> &out,vector<int>&v,vector<int>&candidates,int target,int n,int sum){
        if(sum>target)
        return;
        if(sum==target)

        { cout<<sum<<" ";

              sort(v.begin(),v.end());
            out.insert(v);
            return;
        }

        for(int i=n;i<candidates.size();i++)
        {
            sum=sum+candidates[i];
            v.push_back(candidates[i]);
            recur(out,v,candidates,target,i,sum);
            sum=sum-candidates[i];
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
       set<vector<int>>out;
       vector<int>v;
       int sum=0;
       recur(out,v,candidates,target,0,sum);
       vector<vector<int>>all(out.begin(),out.end());
       return all; 
       
    }
};