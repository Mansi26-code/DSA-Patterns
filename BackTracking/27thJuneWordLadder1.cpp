class Solution{
public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string> &wordList) {
                            queue<pair<string,int>>q;
                            q.push({startWord,1});
                            set<string>st(wordList.begin(),wordList.end());
                            st.erase(startWord);
                            while(!q.empty())
                            {
                                auto top=q.front();
                                q.pop();
                                string word=top.first;
                                int steps=top.second;

                                if(word==targetWord)
                                return steps;

                                for(int i=0;i<word.size();i++)
                                {
                                    char original=word[i];
                                    for(char ch='a'; ch<='z';ch++)
                                    {
                                        word[i]=ch;

                                        if(st.find(word)!=st.end())
                                        {
                                            st.erase(word);
                                            q.push({word,steps+1});
                                        }
                                    }
                                     word[i]=original;
                                }
                               
                            }
            return 0;
    }
};


Time Complexity:O(N * M * 26), where N is the number of words in the wordList and M is the length of the startWord.
Space Complexity:O(N), where N is the number of words in the wordList, due to the queue and set.
