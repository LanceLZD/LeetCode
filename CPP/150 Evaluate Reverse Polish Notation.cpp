class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto val:tokens) {
            if (val=="+" || val=="-" || val=="*" || val=="/") {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                if (val=="+")
                    s.push(a+b);
                else if (val=="-")
                    s.push(a-b);
                else if (val=="*")
                    s.push(a*b);
                else
                    s.push(a/b);
            }
            else {
                stringstream ss;
                int k;
                ss << val;
                ss >> k;
                s.push(k);
            }
        }
        return s.top();
    }
};