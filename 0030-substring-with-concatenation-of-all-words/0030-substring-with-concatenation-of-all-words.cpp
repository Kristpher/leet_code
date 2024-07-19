class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLength = words[0].length();
        int totalWords = words.size();
        int totalLength = wordLength * totalWords;

        if (s.length() < totalLength) return result;

        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }

        for (int i = 0; i < wordLength; i++) {
            unordered_map<string, int> seenWords;
            int left = i;
            int count = 0;
            
            for (int right = i; right <= s.length() - wordLength; right += wordLength) {
                string word = s.substr(right, wordLength);
                
                if (wordCount.count(word)) {
                    seenWords[word]++;
                    count++;
                    
                    
                    while (seenWords[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLength);
                        seenWords[leftWord]--;
                        count--;
                        left += wordLength;
                    }
                    
                    
                    if (count == totalWords) {
                        result.push_back(left);
                    }
                } else {
                    seenWords.clear();
                    count = 0;
                    left = right + wordLength;
                }
            }
        }
        
        return result;
    }
};
