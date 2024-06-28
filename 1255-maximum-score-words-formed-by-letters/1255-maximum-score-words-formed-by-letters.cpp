class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> letterCount;
        for (char c : letters) {
            letterCount[c]++;
        }

        return backtrack(words, letterCount, score, 0);
    }

private:
    int backtrack(vector<string>& words, unordered_map<char, int>& letterCount, vector<int>& score, int index) {
        if (index == words.size()) {
            return 0;
        }

        // Skip the current word
        int maxScore = backtrack(words, letterCount, score, index + 1);

        // Try to include the current word
        string& word = words[index];
        unordered_map<char, int> wordCount;
        bool canInclude = true;
        int wordScore = 0;

        for (char c : word) {
            wordCount[c]++;
            if (wordCount[c] > letterCount[c]) {
                canInclude = false;
            }
            wordScore += score[c - 'a'];
        }

        if (canInclude) {
            for (auto& [c, count] : wordCount) {
                letterCount[c] -= count;
            }
            maxScore = max(maxScore, wordScore + backtrack(words, letterCount, score, index + 1));
            for (auto& [c, count] : wordCount) {
                letterCount[c] += count;
            }
        }

        return maxScore;
    }
};