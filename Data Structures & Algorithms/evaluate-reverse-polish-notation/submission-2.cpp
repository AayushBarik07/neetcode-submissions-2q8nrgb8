class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st; // Use long long to prevent overflow during intermediate steps
        
        for (const string& s : tokens) {
            // Check if the token is an operator
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                long long y = st.top(); st.pop(); // Second operand
                long long x = st.top(); st.pop(); // First operand
                
                if (s == "+") st.push(x + y);
                else if (s == "-") st.push(x - y);
                else if (s == "*") st.push(x * y);
                else if (s == "/") st.push(x / y); // C++ division truncates toward zero by default
            } 
            else {
                // It's a number (positive or negative)
                st.push(stoll(s)); 
            }
        }
        return (int)st.top();
    }
};
