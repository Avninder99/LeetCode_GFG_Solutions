class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> arr; // Create a array of pairs of age & scores
        vector<int> ans ((int)scores.size(), 0); // An array to hold answers of LIS ending at given index-- More formally, Longest Non decreasing Subsequence
        
        for(int i=0;i<scores.size();i++) {
            arr.push_back({ages[i], scores[i]});  // Push {age, score} pair in the array
        }
        sort(arr.begin(), arr.end()); // It is important that age is the first element AND score is the second element  in the pair. This is because in sorting vector of pairs, pair.first is given priority over pair.second
        
        // Note: From here on we dont need age at all! We only access arr[i].second to access scores! 
        int best = 0;   // Store the final answer
        
        // Logic of LIS
        for(int i=0; i<arr.size();i++) {
            ans[i]=arr[i].second; 
            for(int j=0;j<i;j++) {
                if(arr[i].second >= arr[j].second) {
                    ans[i] = max(ans[i], ans[j] + arr[i].second);
                }
            }
            best = max(best, ans[i]);
        }
        
        return best; // Time to celebrate!
    }
};