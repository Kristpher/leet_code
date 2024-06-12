class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxim=0,sum=0;
        for(int i=0;i<gain.size();i++)
        {
            sum+=gain[i];
            maxim=max(sum,maxim);
        }
        return maxim;
    }
};