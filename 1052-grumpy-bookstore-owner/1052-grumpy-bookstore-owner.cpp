class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0;
        int n=grumpy.size();
        for(int i=0;i<minutes;i++)
        {  if(grumpy[i]==1)
           sum+=customers[i];
        }
        int maxim=sum;
        for(int i=1;i<=n-minutes;i++)
        {
           
            if(grumpy[i-1]==1){
            if(grumpy[i+minutes-1]==1)    
            sum=sum+customers[i+minutes-1]-customers[i-1];
            else{
                sum=sum-customers[i-1] ;
            }
            }
            else if(grumpy[i-1]==0){

             if(grumpy[i+minutes-1]==1)    
            sum=sum+customers[i+minutes-1];

            
            }
            cout<<sum<<" ";
            maxim=max(maxim,sum);
        }
    
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0){
            sum+=customers[i];
           
            }
        }
        return sum;
    }
};