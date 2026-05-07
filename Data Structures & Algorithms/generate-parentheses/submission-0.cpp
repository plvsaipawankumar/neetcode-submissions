class Solution {
public:
    vector<string> ans;
    void parentheses(int total,int brackets,int open,int closed, string parenth)
    {
        if(total>brackets || total<0 || open>brackets || closed>brackets)
            return ;
        if((total==0) && (open== closed) && (open == (brackets)))
        {
            cout<<parenth<<endl;
            ans.push_back(parenth);
            return ;
        }
        parentheses(total+1,brackets,open+1,closed,parenth+"(");
        parentheses(total-1,brackets,open,closed+1,parenth+")");
        return ;
    }
    vector<string> generateParenthesis(int n) {
        parentheses(0,n,0,0,"");
        return ans;
    }
};
