class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size()==0 || s.size()<t.size())
            return "";
        vector<int> nums(256,0);
        vector<int> numt(256,0);
        for (int i=0;i<t.size();i++)
            numt[t[i]]++;
        int j = 0;
        int begin = -1;
        int length = INT_MAX;
        for (int i=0;i<s.size();i++) {
            nums[s[i]]++;
            if (judge(nums, numt)) {
                while (1) {
                    if (nums[s[j]]==numt[s[j]])
                        break;
                    else
                    {
                        nums[s[j]]--;
                        j++;
                    }
                }
                if (i-j+1<length) {
                    begin = j;
                    length = i-j+1;
                }
            }
        }
        if (begin==-1)
            return "";
        else
            return s.substr(begin,length);
    }
    
    bool judge(vector<int>& nums, vector<int>& numt) {
        for (int i=0;i<256;i++)
            if (nums[i]<numt[i])
                return 0;
        return 1;
    }
};