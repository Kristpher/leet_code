class Solution {
public:
    int pivotInteger(int n) {
     int sum1=0,sum2=0;
     if(n==1)
     return 1;
     for(int i=1;i<=n;i++)
     {
        if(i<=(n/2)+1)
        sum1+=i;
        if(i>=(n/2)+1)
        sum2+=i;
     }
     int i=(n/2)+2;
     while(sum1<=sum2)
     {
       if(sum1==sum2)
       return i;
       else
       {
        sum1+=i;
        sum2-=i-1;
       }
     }
    
     
     return -1;
    }
};