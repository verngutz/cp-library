#include "Graph Algos - Tree Center.cpp"
template <bool Index> int diameter(graph<0, edge, Index>& g) {
    auto [centers, height] = find_centers(g);
    if(g.size() == 1) {
        return 0;
    } else if(g.size() == 2) {
        return 1;
    } else if(centers.size() == 1) {
        return height[g(g[centers[0]][0]).v] + height[g(g[centers[0]][1]).v];
    } else {
        return height[g(g[centers[0]][1]).v] + height[g(g[centers[1]][1]).v] + 1;
    }
}
