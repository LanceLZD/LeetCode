class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<bool>> dict(26, vector<bool>(26,0));
        vector<bool> use(26,0);
        for (int i=0;i<words.size();i++)
            for (int j=0;j<words[i].size();j++)
                use[words[i][j]-'a'] = 1;
        for (int i=0;i<words.size()-1;i++) {
            int j = 0;
            while (j<words[i].size() && j<words[i+1].size() && words[i][j]==words[i+1][j])
                j++;
            if (j==words[i+1].size() && j<words[i].size())
                return "";
            if (j==words[i].size() || j==words[i+1].size())
                continue;
            dict[words[i][j]-'a'][words[i+1][j]-'a'] = 1;
        }
        string res;
        while (1) {
            bool find = 0;
            char start = '0';
            for (int i=0;i<26;i++) {
                if (use[i])
                    find = 1;
                else
                    continue;
                bool pre = 0;
                for (int j=0;j<26;j++) {
                    if (use[j] && dict[j][i])
                        pre = 1;
                }
                if (!pre) {
                    start = 'a' + i;
                    use[i] = 0;
                    break;
                }
            }
            if (!find)
                break;
            if (start=='0')
                return "";
            res += start;
        }
        return res;
    }
};