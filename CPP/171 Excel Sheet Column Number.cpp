class Solution {
public:
    int titleToNumber(string s) {
        if (s.size()==1)
            return s[0]-'A'+1;
        else
            return (s[s.size()-1] - 'A' + 1) + 26 * titleToNumber(s.substr(0,s.size()-1));
    }
};