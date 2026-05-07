class MinStack {
public:
    stack<pair<int,int>> stk;
    int minimum = INT_MAX;
    MinStack() {
    }
    
    void push(int val) {
        minimum = min(minimum,val);
        stk.push({val,minimum});
    }
    
    void pop() {
        if(stk.empty()) return ;
        stk.pop();
        minimum=(stk.empty())?INT_MAX:stk.top().second;
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }

};
