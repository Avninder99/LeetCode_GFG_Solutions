class Solution {
    public long minimumTime(int[] time, int totalTrips) {
        Arrays.sort(time);
        long tt = totalTrips;
        long l = 1L;
        long h = (long)(time[time.length - 1] * tt);
        long m = (l + (h-l)/2); 
        long tripRec = 0L;
        long minTime = h;

        boolean verified = false;

        while(l <= h){
            m = l + (long)((h-l)/(long)2);

            verified = false;
            tripRec = 0L;

            for(int i=0;i<time.length;i++){
                if((long)time[i] > m || tripRec >= tt) break;
                tripRec += (long)m/(long)time[i];
            }
            if(tripRec >= tt){
                verified = true;
            }

            if(verified){
                minTime = (long)m;
                h = m - 1;
            }else{
                l = m + 1;
            }
        }
        return minTime;
    }
}