class Solution {
public:
    int countSeniors(vector<string>& details) {
     int count=0;
     string temp="";
     for(int i=0;i<details.size();i++){
     temp="";
     temp+=details[i][11];
     temp+=details[i][12];
     int a=stoi(temp);
     if(a>60)
     count++;

     }   
     return count;
    }
};