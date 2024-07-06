class Solution {
public:
    int passThePillow(int n, int time) {
    int ans=0;
    int k=time/(n-1);
    if(k%2==1 &&time%(n-1)==0)
    return n;
    else if(k%2==0 &&time%(n-1)==0)
    return 1;
    else if(time<n-1)
    return time+1;
    if(k%2==0)
    ans=1+(time%(n-1));
    else
    ans=n-(time%(n-1));
       
       
    return ans;
    }
};