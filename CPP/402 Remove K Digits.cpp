class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        int need = num.size()-k;
        if (need==0)
            return "0";
        for (int i=0;i<num.size();i++) {
            while (res.size()>0 && res.back()>num[i] && num.size()-i+res.size()>need)
                res.pop_back();
            res += num[i];
        }
        int index = 0;
        while (index<res.size() && res[index]=='0')
            index++;
        if (index==res.size())
            return "0";
        else
            return res.substr(index, need);
    }
};