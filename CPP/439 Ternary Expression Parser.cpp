class Solution {
public:
    string parseTernary(string expression) {
        int n = expression.size();
        stack<char> s;
        s.push(expression[n-1]);
        for (int i=n-2;i>0;i-=2) {
            if (expression[i]==':') {
                s.push(expression[i-1]);
            }
            else {
                if (expression[i-1]=='F')
                    s.pop();
                else {
                    char tmp = s.top();
                    s.pop();
                    s.pop();
                    s.push(tmp);
                }
            }
        }
        string res = "";
        res += s.top();
        return res;
    }
};