/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& g) {
        int sr = 0, sc = 0, er = g[0].size() - 1, ec = g.size() - 1, sideLen = ec - sc + 1;
        Node* curr = creator(sr, sc, er, ec, g);
        return curr;
    }
private:
    Node* creator(int sr, int sc, int er, int ec, vector<vector<int>>&g){
        pair<int, int>rec = uniform(sr, sc, er, ec, g);
        
        if(rec.first){      // check for is uniform
            Node* curr = new Node(rec.second, true);
            return curr;
        }else{
            Node* curr = new Node(rec.second, false);
            int midR = er - (er - sr)/2, midC = ec - (ec - sc)/2;
            
            curr->topLeft = creator(sr, sc, midR - 1, midC - 1, g);
            curr->topRight = creator(midR, sc, er, midC - 1, g);
            curr->bottomLeft = creator(sr, midC, midR - 1, ec, g);
            curr->bottomRight = creator(midR, midC, er, ec, g);
            return curr;
        }
        return NULL;    // fallback return
    }
    pair<int, int> uniform(int sr, int sc, int er, int ec, vector<vector<int>>&g){
        // return a pair { is uniform , all nodes val}
        
        int sideLen = er - sr + 1, checkSum = 0;
        for(int i=sc;i<=ec;i++){
            for(int j=sr;j<=er;j++){
                checkSum += g[i][j];
            }
        }
        pair<int, int>res = {checkSum == 0 || checkSum == (sideLen * sideLen), checkSum > 0};
        return res;
    }
};