class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen   = words[0].size();
        int wordCount = words.size();
        int n         = s.size();

        unordered_map<string, int> wordMap;
        for (auto& w : words) wordMap[w]++;

        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> seen;

            for (int j = i; j <= n - wordLen; j += wordLen) {
                string word = s.substr(j, wordLen);
                if (wordMap.count(word)) {
                    seen[word]++;
                    count++;
                    while (seen[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    if (count == wordCount) {
                        result.push_back(left);
                        seen[s.substr(left, wordLen)]--;
                        count--;
                        left += wordLen;
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return result;
    }
};