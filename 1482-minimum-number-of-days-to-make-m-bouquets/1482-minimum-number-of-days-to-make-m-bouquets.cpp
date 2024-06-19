class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < m * k) return -1;

        int maxim = *max_element(bloomDay.begin(), bloomDay.end());
        int minim = *min_element(bloomDay.begin(), bloomDay.end());

        int u = minim;
        int v = maxim;
        int result = -1;

        while (u <= v) {
            int mid = u + (v - u) / 2;
            int count = 0;
            int bouquets = 0;

            for (int j = 0; j < bloomDay.size(); j++) {
                if (bloomDay[j] <= mid) {
                    count++;
                    if (count == k) {
                        bouquets++;
                        count = 0;
                    }
                } else {
                    count = 0;
                }

                if (bouquets >= m) break;
            }

            if (bouquets >= m) {
                result = mid;
                v = mid - 1;
            } else {
                u = mid + 1;
            }
        }

        return result;
    }
};
