class Solution {
public:
    int evalRPN(vector<string>& t) {
        int size = t.size(), res, temp, n1, n2;
        stack<int>st;
        for(int i=0;i<size;i++){
            if(t[i] == "+" || t[i] == "*"){
                n1 = st.top();
                st.pop();
                n2 = st.top();
                st.pop();
                if(t[i] == "+") st.push(n1 + n2);
                else st.push(n1 * n2);
            }else if(t[i] == "-" || t[i] == "/"){
                n1 = st.top();
                st.pop();
                n2 = st.top();
                st.pop();
                if(t[i] == "-") st.push(n2 - n1);
                else st.push(n2 / n1);
            }else{
                st.push(stoi(t[i]));
            }
        }
        return st.top();
    }
};