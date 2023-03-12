// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.


class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(int i=0; i<s.size(); i++){
            if(st.size()==0){
                st.push(s[i]);
            }else{
                if(s[i]==')'){
                    if(st.top() == '(')
                        st.pop();
                    else
                        st.push(s[i]);
                }else if(s[i]=='}'){
                    if(st.top() == '{')
                        st.pop();
                    else
                        st.push(s[i]);
                }else if(s[i]==']'){
                    if(st.top() == '[')
                        st.pop();
                    else
                        st.push(s[i]);
                }else{
                    st.push(s[i]);
                }
            }
        }

        return !st.size();
    }
};
