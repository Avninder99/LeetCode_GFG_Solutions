class Solution {
public:
    bool isValid(string s) {
        stack<char>st1;
        for(int i = 0;i<s.length();i++){
            if(s[i] == '('){
                st1.push(')');
            }
            else if(s[i] == '['){
                st1.push(']');
            }
            else if(s[i] == '{'){
                st1.push('}');
            }
            else{
                if(!st1.empty() && st1.top() == s[i]){
                    st1.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st1.empty();
    }
};