class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        // Not mine
        
        vector<pair<int,int>> arr;
        vector<int> ans ((int)scores.size(), 0);
        
        for(int i=0;i<scores.size();i++) {
            arr.push_back({ages[i], scores[i]});
        }
        sort(arr.begin(), arr.end());
        
        int best = 0;
        for(int i=0; i<arr.size();i++) {
            ans[i]=arr[i].second; 
            for(int j=0;j<i;j++) {
                if(arr[i].second >= arr[j].second) {
                    ans[i] = max(ans[i], ans[j] + arr[i].second);
                }
            }
            best = max(best, ans[i]);
        }
        
        return best;
    }
};