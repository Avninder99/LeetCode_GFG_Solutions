class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        
        long long 
            l = 1, 
            h = (long long)time[time.size() - 1] * (long long)totalTrips, 
            m = l + (h-l)/2, 
            tripRec = 0, 
            minTime = h;
        
        bool verified = false;
        while(l <= h){
            m = l + (h-l)/2;
            
            verified = false;
            tripRec = 0;
            for(int i=0;i<time.size();i++){
                if(time[i] > m || tripRec >= totalTrips) break;
                tripRec += (long long)m / (long long)time[i];
            }
            if(tripRec >= totalTrips){
                verified = true;
            }
            
            if(verified){
                minTime = m;
                h = m - 1;
            }else{
                l = m + 1;
            }
        }
        return minTime;
    }
};