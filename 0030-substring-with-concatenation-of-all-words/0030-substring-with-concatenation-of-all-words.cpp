class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wordCount;
        vector<int> result;
        int wordLength = words[0].length();
        int totalWords = words.size();
        int totalLength = wordLength * totalWords;
        
        if (s.length() < totalLength) return result;


        for (const string& word : words) {
            wordCount[word]++;
        }

        for (int i = 0; i <= s.length() - totalLength; i++) {
            unordered_map<string, int> seenWords;
            int j = 0;
           
            while (j < totalWords) {
                string word = s.substr(i + j * wordLength, wordLength);
                if (wordCount.count(word)) {
                    seenWords[word]++;
                 
                    if (seenWords[word] > wordCount[word]) {
                        break;
                    }
                } else {
                    break;
                }
                j++;
            }
          
            if (j == totalWords) {
                result.push_back(i);
            }
        }

        return result;
    }
};
