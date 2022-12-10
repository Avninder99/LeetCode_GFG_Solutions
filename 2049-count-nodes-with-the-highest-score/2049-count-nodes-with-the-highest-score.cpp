class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        unordered_map<int, pair<int, int>>childrenRecord;
        
        for(int i=0;i<parents.size();i++){
            if(childrenRecord.find(parents[i]) != childrenRecord.end()){
                childrenRecord[parents[i]].second = i;
            }else{
                childrenRecord[parents[i]].first = i;
            }
        }
        
        long long totalNodes = parents.size(), prod = 0, res = 0;
        calc(0, totalNodes, prod, childrenRecord, res);
        return res;
    }
private:
    long long calc(int node, long long &totalNodes, long long &maxProduct, unordered_map<int, pair<int, int>>&childrenRecord, long long &res){
        
        int leftNodesNum = 0, rightNodesNum = 0;
        
        if(childrenRecord[node].first){
            leftNodesNum = calc(childrenRecord[node].first, totalNodes, maxProduct, childrenRecord, res);
        }
        if(childrenRecord[node].second){
            rightNodesNum = calc(childrenRecord[node].second, totalNodes, maxProduct, childrenRecord, res);
        }
        
        long long parentsNodesNum = totalNodes - leftNodesNum - rightNodesNum - 1, prod;
        prod = ( parentsNodesNum > 0 ? parentsNodesNum : 1 ) * ( leftNodesNum > 0 ? leftNodesNum : 1 ) * ( rightNodesNum > 0 ? rightNodesNum : 1 );
        
        if(prod > maxProduct){
            maxProduct = prod;
            res = 1;
        }else if(prod == maxProduct){
            res++;
        }
        
        return leftNodesNum + rightNodesNum + 1;
    }
};