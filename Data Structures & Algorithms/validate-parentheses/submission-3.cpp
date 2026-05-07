class Solution {
public:
    bool isValid(string s) {
        int ans =0,i,n=s.size();
        map<char,char> m;
        m[')'] = '(';
        m[']'] = '[';
        m['}'] = '{';
        stack<char> ts;
        ts.push(s[0]);
        for(i=1;i<n;i++)
        {
            if(ts.size()>0 && m[s[i]]==ts.top())
            {
                ts.pop();
            }
            else
            {
                ts.push(s[i]);
            }
        }
        return ts.empty();
    }
};
