class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        auto cmp = [&](pair<int, int>& a, pair<int, int>& b) {
            return arr[a.first] * arr[b.second] > arr[b.first] * arr[a.second];
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);

        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            minHeap.push({i, n - 1});
        }

        pair<int, int> result;
        while (k-- > 0) {
            result = minHeap.top();
            minHeap.pop();
            if (result.second - 1 > result.first) {
                minHeap.push({result.first, result.second - 1});
            }
        }

        return {arr[result.first], arr[result.second]};
    }
};
