class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<pair<int,int>>all;
        for(int i=0;i<profit.size();i++)
        {
            all.push_back({difficulty[i],profit[i]});
        }
        sort(all.begin(),all.end());
            sort(worker.begin(),worker.end());

        int k = 0;
        int i = 0;
        long sum = 0;
        int maxim=0;
        for(int i=0;i<worker.size();i++)
        {
            while(k<all.size() && worker[i]>=all[k].first){
            maxim=max(all[k].second,maxim);
            k++;
            }
            sum+=maxim;

        }
   
        return sum;
    }
};
