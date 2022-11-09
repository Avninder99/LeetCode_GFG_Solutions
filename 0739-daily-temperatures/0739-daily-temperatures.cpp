class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>st;
        for(int i=0;i<t.size();i++){
            while(!st.empty() && t[st.top()] < t[i]){
                t[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            t[st.top()] = 0;
            st.pop();
        }
        return t;
    }
};