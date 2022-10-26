class Solution {
public:
    vector<string>v1;
    void func1(int n, string str, int o_num, int e_num){
        if(o_num == n && e_num == n){
            v1.push_back(str);
            return;
        }
        if(o_num < n){
            str.push_back('(');
            o_num++;
            func1(n, str, o_num, e_num);
            o_num--;
            str.pop_back();    
        }
        
        if(e_num < o_num){
            str.push_back(')');
            e_num++;
            func1(n, str, o_num, e_num);
            e_num--;
            str.pop_back();    
        }
        
        
    }
    vector<string> generateParenthesis(int n) {
        func1(n, "", 0, 0);
        return  v1;
    }
};