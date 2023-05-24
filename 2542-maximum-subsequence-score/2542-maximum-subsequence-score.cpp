class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>rec;
        int size = nums2.size();
        
        for(int i=0;i<size;i++){
            rec.push_back({nums2[i], nums1[i]});
        }
        
        sort(rec.begin(), rec.end());
        
        priority_queue<int, vector<int>, greater<int>>pq;
        
        long long int sum = 0, maxi = 0, prod;
        
        for(int i=size-1; i>size-k; i--){
            pq.push(rec[i][1]);
            sum += rec[i][1];
        }
        
        for(int i=size - k; i>=0; i--){
            
            sum += rec[i][1];
            prod = sum * rec[i][0];
            maxi = max(maxi, prod);
            
            pq.push(rec[i][1]);
            sum -= pq.top();
            pq.pop();
            
        }
        return maxi;
    }
};