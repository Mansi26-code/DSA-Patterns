class Solution{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string> &wordList) {
        vector<vector<string>>ans;
        queue<vector<string>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        q.push({beginWord});
        st.erase(beginWord);
        unordered_set<string>toErase;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                vector<string>seq=q.front();
                string word=seq.back();
                q.pop();
                if(word==endWord)
                {
                    if(ans.empty())
                    {
                        ans.push_back(seq);
                    }
                   else if(ans.back().size()==seq.size())
                   {
                    ans.push_back(seq);
                   }
                }

                for(int pos=0;pos<word.size();pos++)
                {
                    char original=word[pos];
                    for(char ch='a';ch<='z';ch++)
                    {
                        word[pos]=ch;

                        if(st.find(word)!=st.end())
                        {
                            seq.push_back(word);
                            q.push(seq);

                            toErase.insert(word);
                            seq.pop_back();
                        }
                    }
                    word[pos]=original;

                }
            }

            for(auto it:toErase)
            st.erase(it);
            toErase.clear();

            if(!ans.empty())
            break;
        }
        return ans;
    }
};


Time Complexity:O(N * L * 26 * M), where N is the number of words in wordList, L is the length of each word, and M is the number of sequences in the worst case. The outer while loop iterates potentially through all possible sequences. The nested for loops iterate through each position in the word (L) and each possible character (26).
Space Complexity:O(N * M), where N is the number of words in wordList, and M is the maximum number of sequences stored in the queue and the answer vector. The unordered sets also contribute O(N) space.