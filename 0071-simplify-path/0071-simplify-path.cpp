class Solution {
public:
    string simplifyPath(string path) {
        string temp = "";
        int flag = 0;
        int val=1;
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == '/' && !flag) {
                flag = 1;
                temp += path[i];
                val=1;
               
            } else if (path[i] == '/' && flag){
                val=1;
                continue;
            }
            else if (path[i] == '.'&&val) {
                int c = 0;
                while (i < path.length() && path[i] == '.') {
                    temp += '.';
                    c++;
                    i++;
                }
                i--;

                if (c <= 2 &&(path[i+1]=='/'||i==path.length()-1)) {
                    int p = c;
                    while (c) {
                        if (!temp.empty()) {
                            temp.pop_back();
                        }
                        c--;
                    }

                    int count = 0;
                    if (p == 2) {
                        while (count < 2 && !temp.empty()) {
                            if (temp.back() == '/')
                                count++;
                            temp.pop_back();
                        }
                    } else if (p == 1) {
                        while (count < 1 && !temp.empty()) {
                            if (temp.back() == '/')
                                count++;
                            temp.pop_back();
                        }
                    }
                }
                flag = 0;
            } else {
                temp += path[i];
                flag = 0;
                val=0;
            }
        }

        if (!temp.empty() && temp.back() == '/' && temp.length() > 1)
            temp.pop_back();
        return temp.empty() ? "/" : temp;
    }
};
