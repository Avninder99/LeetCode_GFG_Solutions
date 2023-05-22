class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>numToFreq;
        unordered_map<int, vector<int>>freqToNum;
        for(auto itr: nums){
            numToFreq[itr]++;
        }
        
        for(auto itr: numToFreq){
            freqToNum[itr.second].push_back(itr.first); 
        }
        vector<int>freqRec, res;
        for(auto itr: freqToNum){
            freqRec.push_back(itr.first);
        }
        sort(freqRec.begin(), freqRec.end(), greater<int>());
        int ptr = 0;
        
        while(res.size() < k){
            vector<int>h = freqToNum[freqRec[ptr]];
            for(int i=0;i<h.size();i++){
                res.push_back(h[i]);
            }
            ptr++;
        }
        return res;
    }
};