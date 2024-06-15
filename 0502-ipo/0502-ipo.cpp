class Solution {
public:
    int findMaximizedCapital(int numProjects, int initialCapital, vector<int>& profits, vector<int>& capital) {
        int numCandidates = profits.size();
        vector<pair<int, int>> projects;

        for (int i = 0; i < numCandidates; ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> availableProjects;
        int currentIndex = 0;

        for (int projectCount = 0; projectCount < numProjects; ++projectCount) {
            while (currentIndex < numCandidates && projects[currentIndex].first <= initialCapital) {
                availableProjects.push(projects[currentIndex].second);
                ++currentIndex;
            }

            if (availableProjects.empty()) {
                break;
            }

            initialCapital += availableProjects.top();
            availableProjects.pop();
        }

        return initialCapital;
    }
};
