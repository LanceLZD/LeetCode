class MinStack {
private:
    stack<int> allnum;
    stack<int> allmin;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        allnum.push(x);
        if (allmin.empty() || allmin.top()>=x)
            allmin.push(x);
    }
    
    void pop() {
        if (allnum.top()==allmin.top())
            allmin.pop();
        allnum.pop();
    }
    
    int top() {
        return allnum.top();
    }
    
    int getMin() {
        return allmin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */