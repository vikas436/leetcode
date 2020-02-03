// https://leetcode.com/problems/redundant-connection/
class Solution {
public:
    int find(int node, vector<int>vec) {
        if(vec[node]<0) return node;
        return find(vec[node], vec);
    }
    bool union_find(vector<int>edge, vector<int>&vec) {
        int find_x = find(edge[0], vec);
        int find_y = find(edge[1], vec);
        if(find_x<find_y) {
            vec[find_x] = find_y;
        } else {
            vec[find_y] = find_x;
        }
        return find_x==find_y;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>vec(edges.size()+2, -1);
        for(vector<int>edge : edges) {
            bool cycle = union_find(edge, vec); 
            if(cycle) return edge;
        }
        return {};
    }
};
