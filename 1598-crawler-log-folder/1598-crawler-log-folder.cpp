class Solution {
public:
    int minOperations(vector<string>& logs) {
        int op=0;
        for(int i=0;i<logs.size();i++)
        {
           if(logs[i]=="../"){
           if(op){
           op--;
           }
           }
           else if(logs[i]=="./")
           continue;
           else
           op++;
        }
        return op;
    }
};