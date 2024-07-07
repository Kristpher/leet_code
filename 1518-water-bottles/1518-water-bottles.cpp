class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
       int num=0;
       int empty=0;
       num+=numBottles;
       numBottles=0;
       int excess=num;
       int i=0;
       while(numExchange<=empty||i==0)
       {
        empty=excess;
        num+=numBottles;
        empty+=numBottles;
        numBottles=empty/numExchange;
        excess=empty%numExchange;
        //cout<<num<<" "<<empty<<endl;
        i++;

       }
        return num;
    }
};