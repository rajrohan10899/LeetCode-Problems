class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(char ch : s) {
            if(ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            else {
                if(st.empty()) 
                    return false;
                if((st.top() == '(' && ch == ')') ||
                    (st.top() == '['&& ch == ']') ||
                    (st.top() == '{'&& ch == '}')) {
                        st.pop(); // means balanced.
                    }
                    else {
                        return false;
                    }
            }
        }
        return st.empty();
    }
};