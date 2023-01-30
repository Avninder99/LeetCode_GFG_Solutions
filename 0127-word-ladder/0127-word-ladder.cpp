class Solution {
public:
    int ladderLength(string b, string e, vector<string>& w) {
         if(b == e) return 0;
        
        bool bExist = false, eExist = false;
        for(auto itr: w){
            if(itr == b){
                bExist = true;
            }else if(itr == e){
                eExist = true;
            }
        }
        if(!eExist) return 0;
        if(!bExist) w.push_back(b);
        
        int change = 1, ws = w.size(), l = b.length();
        vector<int>vis(ws, 0);
        
        // BFS approach
        queue<string>q1;
        q1.push(e);
        q1.push("1");
        
        while(q1.size() > 1 && change <= w.size()){
            string holder = q1.front();
            q1.pop();
            if(holder == b) return change;
            if(holder == "1"){
                change++;
                q1.push("1");
                continue;
            }
            
            for(int i=0;i<ws;i++){
                if(vis[i] == 1) continue;
                
                int diff = 0;
                string itr = w[i];
                
                for(int j=0;j<l;j++){
                    if(holder[j] != itr[j]){
                        diff++;
                    }
                }
                
                if(diff == 1){
                    vis[i] = 1;
                    q1.push(itr);
                }
            }
        }
        return 0;
    }
};