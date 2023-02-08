class Solution {
public:
    int totalFruit(vector<int>& f) {
        if(f.size() < 3) return f.size();
        int e1 = 0, e2 = -1, n1 = f[0], n2 = -1, c1 = 1, c2 = 0, rec = 2;
        for(int i=1;i<f.size();i++){
            if(f[i] == n1){
                c1++;
                e1 = i;
            }else if(f[i] == n2){
                c2++;
                e2 = i;
            }else{
                if(e1 < e2){
                    c2 = e2 - e1;
                    e1 = i;
                    n1 = f[i];
                    c1 = 1;
                }else{
                    c1 = e1 - e2;
                    e2 = i;
                    n2 = f[i];
                    c2 = 1;
                }
            }
            rec = max(rec, c1 + c2);
        }
        return rec;
    }
};