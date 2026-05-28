class Solution {
public:
    struct TrieNode {
        int children[26];
        int best;
        TrieNode(int b) : best(b) { fill(children, children+26, -1); }
    };

    vector<TrieNode> trie;

    void insert(const string& w, int idx, vector<string>& wc) {
        int node = 0;
        if (wc[idx].size() < wc[trie[0].best].size())
            trie[0].best = idx;

        for (int i = w.size()-1; i >= 0; i--) {
            int c = w[i] - 'a';
            if (trie[node].children[c] == -1) {
                trie[node].children[c] = trie.size();
                trie.emplace_back(idx);
            }
            node = trie[node].children[c];
            if (wc[idx].size() < wc[trie[node].best].size())
                trie[node].best = idx;
        }
    }

    int query(const string& w) {
        int node = 0;
        for (int i = w.size()-1; i >= 0; i--) {
            int c = w[i] - 'a';
            if (trie[node].children[c] == -1) break;
            node = trie[node].children[c];
        }
        return trie[node].best;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int best0 = 0;
        for (int i = 1; i < (int)wordsContainer.size(); i++)
            if (wordsContainer[i].size() < wordsContainer[best0].size())
                best0 = i;

        trie.emplace_back(best0);

        for (int i = 0; i < (int)wordsContainer.size(); i++)
            insert(wordsContainer[i], i, wordsContainer);

        vector<int> ans;
        for (auto& q : wordsQuery)
            ans.push_back(query(q));
        return ans;
    }
};