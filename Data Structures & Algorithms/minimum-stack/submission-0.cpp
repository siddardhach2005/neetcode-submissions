class MinStack {
public:
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int> t;
        int m=st.top();
        while(st.size()){
            m=min(m,st.top());
            t.push(st.top());
            st.pop();
        }
        while(t.size()){
            st.push(t.top());
            t.pop();
        }
        return m;
    }
};
