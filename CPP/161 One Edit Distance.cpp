class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m==n-1) {
            return add(s, t);
        }
        else if (m==n+1) {
            return add(t, s);
        }
        else if (m==n) {
            return edit(s, t);
        }
        else
            return 0;
    }
    
    bool add(string s, string t) {
        int judge = 0;
        for (int i=0;i<s.size();i++) {
            if (judge==0) {
                if (s[i]!=t[i])
                {
                    judge = 1;
                    i--;
                }
            }
            else {
                if (s[i]!=t[i+1])
                    return 0;
            }
        }
        return 1;
    }
    
    bool edit(string s, string t) {
        int num = 0;
        for (int i=0;i<s.size();i++)
            if (s[i]!=t[i])
                num++;
        return num == 1;
    }
};