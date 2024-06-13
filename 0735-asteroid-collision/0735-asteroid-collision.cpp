#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stack;
        if (asteroids.size() <= 1)
            return asteroids;
        stack.push(asteroids[0]);
        int maxim=0;
        for (int i = 1; i < asteroids.size(); i++) {
            if (!stack.empty()) {
                if ((stack.top() > 0 && asteroids[i] < 0) ) {
                    int val = stack.top();
                    stack.pop();
                    if (val + asteroids[i] != 0){
                       maxim=max(abs(val),abs(asteroids[i]));
                       if(maxim+val==0||maxim+val==2*val )
                       stack.push(val);
                       if(maxim+asteroids[i]==0||maxim+asteroids[i]==2*asteroids[i] )
                       stack.push(asteroids[i]);
                    }
                } else {
                    stack.push(asteroids[i]);
                }           
                
                while (stack.size() > 1 && ((stack.top() < 0 && secondElement(stack) > 0) )) {
                    int val = stack.top();
                    stack.pop();
                    int val2 = stack.top();
                    stack.pop();
                    if (val + val2 != 0)
                       {
                       maxim=max(abs(val),abs(val2));
                        if(maxim+val2==0||maxim+val2==2*val2 )
                       stack.push(val2);
                       if(maxim+val==0||maxim+val==2*val )
                       stack.push(val);
                      
                    }
                } 
                
            } else {
                stack.push(asteroids[i]);
            }            
        }
        
        vector<int> v(stack.size());
        for (int i = stack.size() - 1; i >= 0; i--) {
            v[i] = stack.top();
            stack.pop();
        }
        return v;
    }
    
private:
    int secondElement(stack<int>& s) {
        int top = s.top();
        s.pop();
        int second = s.top();
        s.push(top);
        return second;
    }
};
