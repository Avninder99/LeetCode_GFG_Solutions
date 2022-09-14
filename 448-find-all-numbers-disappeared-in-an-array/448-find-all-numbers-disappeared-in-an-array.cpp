class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& n) {
        int size = n.size(), curr, temp;
        for(int i=0;i<size;i++){
            if(n[i] == -1) continue;
            curr = n[i];
            do{
                temp = n[curr-1];
                n[curr-1] = -1;
                curr = temp;
            }while(curr > 0);
        }
        vector<int>v1;
        for(int i=0;i<size;i++){
            if(n[i] != -1) v1.push_back(i+1);
        }
        return v1;
    }
};