class Solution {
public:
    string freqAlphabets(string s) {
        string out="";
       for(int i=0;i<s.length();i++){
        string temp="";
        if(i<s.length()-2 && s[i+2]=='#'){
            
            {temp=s.substr(i,2);
            ///cout<<temp;
             int st=stoi(temp);
             out+=st+'a'-1;
             
             i=i+2;
            }
               }
               else {
               char t=s[i];
                int str=t-'0'-1;
                //cout<<t<<" "<<str<<endl;
                out+=str+'a';
               }
       }
       return out;
    }
};