class Solution {
public:
    bool isValid(string str) {
        // (', ')', '{', '}', '[' and ']'
        int n = str.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            char c = str[i];
            if (c == '(' or c == '{' or c == '[')
                st.push(c);
            else if (st.empty() || (c == ')' and st.top() != '(') || (c == ']' and st.top() != '[') || (c == '}') and st.top() != '{')
                return false;
            else
                st.pop();
        }

        return st.empty();
    }
};










