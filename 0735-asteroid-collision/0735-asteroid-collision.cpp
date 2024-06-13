#include <vector>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stack;

        for (int i = 0; i < asteroids.size(); i++) {
            int curr = asteroids[i];


            while (!stack.empty() && stack.top() > 0 && curr < 0) {
                int top = stack.top();
                if (abs(top) < abs(curr)) {
                    stack.pop();
                } else if (abs(top) == abs(curr)) {
                    stack.pop(); 
                    curr = 0;   
                    break;      
                } else {
                    curr = 0;    
                    break;       
                }
            }
            
          
            if (curr != 0) {
                stack.push(curr);
            }
        }

    
        vector<int> result(stack.size());
        for (int i = stack.size() - 1; i >= 0; i--) {
            result[i] = stack.top();
            stack.pop();
        }

        return result;
    }
};
