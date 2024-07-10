class Solution {
public:
    int bulbSwitch(int n) {
        int count=0;
        for(int i=1;i<=n;i++){
            int k=sqrt(i);
            if(k*k==i)
            count++;
        }
        return count;
    }
};