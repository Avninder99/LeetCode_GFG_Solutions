class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pushPtr = 0, popPtr = 0, len = pushed.size();
        stack<int>st;
        while(pushPtr < len || popPtr < len){
            if(!st.empty() && st.top() == popped[popPtr]){
                st.pop();
                popPtr++;
            }else if(pushPtr < len){
                st.push(pushed[pushPtr++]);
            }else{
                return false;
            }
        }
        return true;
    }
};