class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double comp=0;
        double total=0;
        for(int i=0;i<customers.size();i++)
        {
          if(customers[i][0]<=comp){  
          comp+=customers[i][1];
          total+=comp-customers[i][0];
          }
          else{
           comp=customers[i][0]+customers[i][1];
           total+=customers[i][1];
          }
        }
        return total/customers.size();
    }
};