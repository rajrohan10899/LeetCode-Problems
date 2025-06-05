class MinStack {
public:
    /* Stack pair based approach: TC = O(1) and S.C = O(2*N) because storing two element in st*/
    stack<pair<int, int>>st;

    MinStack() {}
    
    void push(int val) {
        int currMin = st.empty() ? val : min(val, st.top().second);
        st.push({val, currMin});
    }
    
    void pop() {
        if(!st.empty()) 
            st.pop();
    }
    
    int top() {
        if(!st.empty()) 
            return st.top().first;
        return -1;
    }
    
    int getMin() {
       return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */