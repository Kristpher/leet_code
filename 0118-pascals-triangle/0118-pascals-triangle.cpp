class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>out;
        vector<int>a;
        a.push_back(1);
        vector<int>v;
        v.push_back(1);
        v.push_back(1);
       
        for(int i=0;i<numRows;i++)
        {
             vector<int>temp;
            if(i==0)
            out.push_back(a);
            if(i==1)
            out.push_back(v);
            else if(i>1)
            { 
             temp.push_back(1);
             for(int j=0;j<i-1;j++)
             {
                temp.push_back(out[i-1][j]+out[i-1][j+1]);
             }
             temp.push_back(1);
            out.push_back(temp);
         }
        }
   return out;
    }
};