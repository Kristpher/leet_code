class Solution {
public:
int squaresum(int n)
        {
            
            int num=0;
            while(n>0)
            {
                int a=n%10;
                num+=pow(a,2);
                n=n/10;
              }
            return num;
        }
    bool isHappy(int n) {
        unordered_map<int,int>map1;
        while(n>1)
        {
         n=squaresum(n);
         if(map1[n]==1)
         return false;
         else
         map1[n]=1;
        }
        return true;
    }
};