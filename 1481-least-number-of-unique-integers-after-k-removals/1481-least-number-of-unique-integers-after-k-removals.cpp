#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> frequency;
        

        for (int num : arr) {
            frequency[num]++;
        }

        vector<pair<int, int>> freqList;
        for (auto& entry : frequency) {
            freqList.push_back({entry.first, entry.second});
        }
        
        sort(freqList.begin(), freqList.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        
        int uniqueCount = freqList.size();
        
        for (const auto& freq : freqList) {
            if (k >= freq.second) {
                k -= freq.second;
                uniqueCount--;
            } else {
                break;
            }
        }
        
        return uniqueCount;
    }
};
