class Solution {
private:
    vector<vector<string>> res;
    
public:
    vector<vector<string>> partition(string s) {
        helper(vector<string>{}, s);
        return res;
    }
    
    bool palindrome(string s) {
        for (int i=0,j=s.size()-1;i<j;i++,j--)
            if (s[i]!=s[j])
                return 0;
        return 1;
    }
    
    void helper(vector<string> tmp, string remains) {
        int n = remains.size();
        if (palindrome(remains)) {
            tmp.push_back(remains);
            res.push_back(tmp);
            tmp.pop_back();
        }
        for (int i=1;i<n;i++) {
            if (palindrome(remains.substr(0,i))) {
                tmp.push_back(remains.substr(0,i));
                helper(tmp, remains.substr(i,n-i));
                tmp.pop_back();
            }
        }
    }
};