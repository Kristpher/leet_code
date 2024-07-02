class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b=0;
        int s=0;
        int flag=0;
        int p=0;
      for(int i=0;i<prices.size()-1;i++){
         if(prices[i]<prices[i+1] && !flag)
         {  
            b=prices[i];
            s=prices[i+1];
            flag=1;
           
         }
         
         else if(prices[i]<prices[i+1] && flag)
            {
                s=prices[i+1];
                  cout<<s<<" ";
            }
          if((prices[i]>prices[i+1]||i+1==prices.size()-1)&& flag){
          p+=s-b;
          
          flag=0;
         }

      }  
      return p;
    }
};