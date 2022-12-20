class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& r) {
        stack<int>st;
        st.push(0);
        int size = r.size();
        while(!st.empty()){
            int temp = st.top(), len = r[temp].size();
            st.pop();
            if(len == 0) continue;
            for(int i=0;i<len;i++){
                st.push(r[temp][i]);
            }
            r[temp].clear();
        }
        for(int i=0;i<size;i++){
            if(r[i].size() != 0) return false; 
        }
        return true;
    }
};