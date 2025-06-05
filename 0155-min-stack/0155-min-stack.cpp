class MinStack {
public:
    vector<int>vec;
    MinStack() {}
    void push(int val) {
        vec.push_back(val);
    }
    
    void pop() {
        if(vec.size()==0)
            return;
        vec.pop_back();
    }
    
    int top() {
        if(vec.size()==0)
            return -1;
        return vec.back();
    }
    
    int getMin() {
        if(vec.size()==0)
            return -1;
        int mini = vec[0];
        for(int i = 0; i < vec.size(); i++) {
            if(vec[i] < mini) {
                mini = vec[i];
            }
        }
        return mini;
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