class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;

        for (int i = 0; i < n; ++i) {
            workers.push_back({(double)wage[i] / quality[i], quality[i]});
        }


        sort(workers.begin(), workers.end());

        priority_queue<int> maxHeap;
        int qualitySum = 0;
        double minCost = DBL_MAX;

        for (auto& worker : workers) {
            double ratio = worker.first;
            int q = worker.second;

            qualitySum += q;
            maxHeap.push(q);

            if (maxHeap.size() > k) {
                qualitySum -= maxHeap.top();
                maxHeap.pop();
            }

            if (maxHeap.size() == k) {
                minCost = min(minCost, qualitySum * ratio);
            }
        }

        return minCost;
    }
};