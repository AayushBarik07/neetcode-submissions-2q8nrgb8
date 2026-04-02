class MinStack {
public:
    vector<int> minSt;
    vector<int> st;
    MinStack() {}
    
    void push(int val) {
        st.push_back(val);
        val = (minSt.empty()) ? val : min(val, minSt.back());
        minSt.push_back(val);
    }
    
    void pop() {
        st.pop_back();
        minSt.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minSt.back();
    }
};
