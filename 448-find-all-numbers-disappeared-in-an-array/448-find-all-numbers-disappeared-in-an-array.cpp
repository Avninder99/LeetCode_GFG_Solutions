class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& n) {
        // Time Complexity = O(n), Space Complexity = O(1) 
        // Follow up solution
        int size = n.size(), curr, temp;
        for(int i=0;i<size;i++){
            if(n[i] == -1) continue;
            curr = n[i];
            do{
                temp = n[curr-1];
                n[curr-1] = -1;
                curr = temp;
            }while(curr != -1);
        }
        vector<int>v1;  // we can ignore this vectors space complexity and ssaid in follow up
        for(int i=0;i<size;i++){
            if(n[i] != -1) v1.push_back(i+1);
        }
        return v1;
    }
};