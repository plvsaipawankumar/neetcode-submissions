class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        char op;
        int i,n=tokens.size(),a,b;
        stack<int> s;
        for(i=0;i<n;i++)
        {
            if(tokens[i] == "+")
            {
                a=s.top();s.pop();
                b=s.top();s.pop();
                s.push(a+b);
            }
            else if(tokens[i] =="-")
            {
                a=s.top();s.pop();
                b=s.top();s.pop();
                s.push(-a+b);
            }
            else if(tokens[i] =="/")
            {
                a=s.top();s.pop();
                b=s.top();s.pop();
                s.push(b/a);
            }
            else if(tokens[i] =="*")
            {
                a=s.top();s.pop();
                b=s.top();s.pop();
                s.push(a*b);
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
