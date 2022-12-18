class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        // similar to next greater integer element in an array question so use monotonic stack
        vector<int>res(t.size(), 0);
        stack<int>st;
        for(int i=0;i<t.size();i++){
            while(!st.empty() && t[i] > t[st.top()]){
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};