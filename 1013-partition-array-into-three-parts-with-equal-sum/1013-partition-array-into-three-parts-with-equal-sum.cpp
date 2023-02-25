class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        unordered_map<int, vector<int>>rec;
        int n = arr.size();
        rec[arr[0]].push_back(0);
        for(int i=1;i<n;i++){
            arr[i] += arr[i - 1];
        }
        
        for(int j=2;j<n;j++){
            int sVal = arr[n - 1] - arr[j - 1];
            auto it = rec.find(sVal);
            
            if(it == rec.end()){
                rec[arr[j - 1]].push_back(j - 1);
                continue;
            }
            
            for(auto itr: it->second){
                if(arr[j - 1] - arr[itr] == sVal){
                    return true;
                }
            }
            
            rec[arr[j - 1]].push_back(j - 1);
        }
        return false;
    }
};