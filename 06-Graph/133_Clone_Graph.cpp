/*
Given a reference of a node in a connected undirected graph, return a deep copy
(clone) of the graph. Each node in the graph contains a val (int) and a list
(List[Node]) of its neighbors.

Input:
1------2
|      |
4------3

Note:
The number of nodes will be between 1 and 100.
The undirected graph is a simple graph, which means no repeated edges and no
self-loops in the graph.
Since the graph is undirected, if node p has node q as neighbor, then node q
must have node p as neighbor too.
You must return the copy of the given node as a reference to the cloned graph.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        Node* copy = new Node(node->val, {}); // 遍历的节点都是已经分配好的
        unordered_map<Node*, Node*> mapping;
        mapping[node] = copy;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            for (auto neighbor : cur->neighbors) {
                // 每次遍历一个节点时，分配好所有邻居
                if (mapping.find(neighbor) == mapping.end()) {
                    mapping[neighbor] = new Node(neighbor->val, {});
                    q.push(neighbor);
                }
                mapping[cur]->neighbors.push_back(mapping[neighbor]);
            }
        }
        return copy;
    }
};
