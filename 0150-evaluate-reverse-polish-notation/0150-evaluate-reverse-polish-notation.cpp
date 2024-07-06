class Solution {
public:
    int op(string c,int a,int b){
        if(c=="+")
        return a+b;
        else if(c=="-")
        return a-b;
        else if(c=="*")
        return a*b;
        else if(c=="/")
        return a/b;
        return -1;
    } 
    int evalRPN(vector<string>& tokens) {
       stack<int>stack;
       int num=0;
       for(int i=0;i<tokens.size();i++)
       {
           if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="/"||tokens[i]=="*")
           {
            int a=stack.top();
            stack.pop();
            int b=stack.top();
            stack.pop();
            int val=op(tokens[i],b,a);
            stack.push(val);
           }
           else
           stack.push(stoi(tokens[i]));
           
       }
       return stack.top(); 
    }
};