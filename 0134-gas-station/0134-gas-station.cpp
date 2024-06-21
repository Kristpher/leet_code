class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int index = 0;
        int maxim = 0;
        int total=0;
        for(int i=0;i<gas.size();i++)
        {
            total+=gas[i]-cost[i];
            maxim+=gas[i]-cost[i];
            if(maxim<0){
            maxim=0;
            index=i+1;
            }
        }
   if(total>=0)
   return index;
   return -1;
    
    }
};