#include <algorithm>
#include <climits>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freqMap;
        for (int num : arr) {
            freqMap[num]++;
        }
        set<int> freqSet;
        for (const auto& entry : freqMap) {
            if (freqSet.find(entry.second) != freqSet.end()) {
                return false;
            }
            freqSet.insert(entry.second);
        }
        return true;
    }
};
