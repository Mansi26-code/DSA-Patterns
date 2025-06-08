class Solution {
   public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string> &wordList) {
        vector<vector<string>> res;
        queue<pair<string, vector<string>>> q;
        set<string> st(wordList.begin(), wordList.end());
        q.push({beginWord, {beginWord}});
        st.erase(beginWord);
        int level = 1;
        set<string> wordsUsedInThisLevel;

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            string word = front.first;
            vector<string> path = front.second;

            if (path.size() > level) {
                level = path.size();
                for (auto &w : wordsUsedInThisLevel) st.erase(w);
                wordsUsedInThisLevel.clear();
            }
            if (word == endWord) {
                res.push_back(path);
            }

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.find(word) != st.end()) {
                        vector<string> newPath = path;
                        newPath.push_back(word);
                        q.push({word, newPath});
                        wordsUsedInThisLevel.insert(word);
                    }
                }
                word[i] = original;
            }
        }
        return res;
    }
};


Time Complexity:O(N * M * 26)

Space Complexity:O(N) 