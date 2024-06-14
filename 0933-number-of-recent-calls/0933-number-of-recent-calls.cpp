#include <queue>

class RecentCounter {
public:
    std::queue<int> q;

    RecentCounter() {
        // Initialization if needed
    }
    
    int ping(int t) {
        int low = t - 3000;
        while (!q.empty() && q.front() < low) {
            q.pop();
        }
        q.push(t);
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
