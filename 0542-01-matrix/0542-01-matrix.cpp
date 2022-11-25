class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>&g) {
        int rs = g[0].size(), cs = g.size(), step = 1;
	    vector<vector<int>>res(cs, vector<int>(rs, -1));
	    queue<vector<int>>q1;
	    for(int i=0;i<cs;i++){
	        for(int j=0;j<rs;j++){
	            if(!g[i][j]){
	                q1.push({i,j});
	                res[i][j] = 0;
	            }
	        }
	    }
	    
	    vector<vector<int>>dir;
	    dir.push_back({0, -1});
	    dir.push_back({1, 0});
	    dir.push_back({0, 1});
	    dir.push_back({-1, 0});
	    
	    q1.push({-1,-1});
	    while(q1.size() > 1){
	        if(q1.front()[0] == -1){
	            q1.pop();
	            q1.push({-1,-1});
	            step++;
	        }else{
	            for(int i=0;i<4;i++){
    	            int tc = q1.front()[0] + dir[i][1], tr = q1.front()[1] + dir[i][0];
    	            if(tc >= 0 && tr >= 0 && tc < cs && tr < rs && res[tc][tr] == -1){
    	                q1.push({tc, tr});
    	                res[tc][tr] = step;
    	            }
	            }
	            q1.pop();
	        }
	    }
	    return res;
    }
};