// twoStack Method
class MinStack {
public:
    stack<int> S1;
    stack<int> S2;
    
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        S1.push(x);
        if (S2.empty() || x <= S2.top())
            S2.push(x);
    }
    
    void pop() {
        if (S1.top() == S2.top())
            S2.pop();
        S1.pop();
    }
    
    int top() {
        return S1.top();
    }
    
    int getMin() {
        return S2.top();
    }
};


// RBtree Method
class MinStack_multiSet {
public:
    stack<int> S;
    int minVal;
    multiset<int> MS;
    
    /** initialize your data structure here. */
    MinStack_multiSet() {
    }
    
    void push(int x) {
        S.push(x);
        MS.insert(x);
    }
    
    void pop() {
        MS.erase(MS.find(S.top()));
        S.pop();
    }
    
    int top() {
        return S.top();
    }
    
    int getMin() {
        return *MS.begin();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
