class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int> dict;
        for (auto val:s)
            dict[val]++;
        for (int i=0;i<s.size();i++)
            if (dict[s[i]]==1)
                return i;
        return -1;
    }
};