class Solution {
public:
    int trap(vector<int>& height) {
     
        int n=height.size()-1;
        if(n<=1)
        return 0;
           int rmax=height[n];
        int lmax=height[0];
        int l=1;
        int r=n-1;
        int water=0;
        while(l<=r)
        {
            if(lmax<=rmax)
            {
                if(lmax<=height[l])
                lmax=height[l];
                else{
                  water+=lmax-height[l];
                }
               l++;
            }
            else{
                 if(rmax<=height[r])
                rmax=height[r];
                else{
                  water+=rmax-height[r];
                }
               r--;
            }

        }
       return water;
    }
};