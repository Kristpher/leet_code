class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
     sort(people.begin(),people.end());
     int l=0;
     int r=people.size()-1;
     int b=0;
     while(l<=r)
     {
        if(people[r]+people[l]>limit)
        {
         b++;
         r--;
        }
        else if(people[r]+people[l]<=limit){
            r--;
            b++;
            l++;
        }

     }   
     return b;
    }
};