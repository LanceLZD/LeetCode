class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int l = beginWord.size();
        vector<int> length(n,0);
        unordered_set<string> m;
        for (int i=wordList.size()-1;i>=0;i--) {
            m.insert(wordList[i]);
            wordList.pop_back();
        }
        m.erase(beginWord);
        if (m.find(endWord)==m.end())
            return 0;
        queue<pair<string,int>> q;
        q.push(make_pair(beginWord,0));
        while (!q.empty()) {
            for (int i=0;i<l;i++) {
                for (int j=0;j<26;j++) {
                    string tmp = q.front().first;
                    tmp[i] = 'a' + j;
                    if (tmp==endWord)
                        return q.front().second+2;
                    if (m.find(tmp)!=m.end()) {
                        q.push(make_pair(tmp,q.front().second+1));
                        m.erase(tmp);
                    }
                }
            }
            q.pop();
        }
        return 0;
    }
};