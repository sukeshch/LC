class MinStack {
private: 
    stack<int> st;
    map<int, int> mp;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        mp[val]++;
    }
    
    void pop() {
        auto v = st.top();
        mp[v]--;
        if(mp[v] == 0)
            mp.erase(v);
        st.pop();
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mp.begin()->first;
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