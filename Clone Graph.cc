/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
        return DFS(hash, node);
    }
    
    UndirectedGraphNode *DFS(unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &hash, 
            UndirectedGraphNode* node) {
        if (node == NULL) return NULL;
        if (hash.find(node) != hash.end()) return hash[node];
        UndirectedGraphNode *clone = new UndirectedGraphNode(node->label);
        hash[node] = clone;
        for (auto next: node->neighbors)
            clone->neighbors.push_back(DFS(hash, next));
        return clone;
    }
};
