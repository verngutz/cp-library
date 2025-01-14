#include "Graph Algos - SCCs.cpp"
struct sat2 {
    int num_vars;
    vector<pair<int, int>> clauses;
    int VAR(int node) { return node >> 1; }
    int T(int var) { return (var << 1) | 1; }
    int F(int var) { return (var << 1) | 0; }
    int NOT(int node) { return node ^ 1; }
    int IS_T(int node) { return (node ^ 0) & 1; }
    int IS_F(int node) { return (node ^ 1) & 1; }
    void at_most_one(const vector<int>& amo_clause) {
        if (amo_clause.size() > 1) {
            clauses.push_back({F(amo_clause[0]), T(num_vars)});
            for (int i = 1; i < int(amo_clause.size()) - 1; i++) {
                clauses.push_back({F(amo_clause[i]), T(num_vars + i)});
                clauses.push_back({F(amo_clause[i]), F(num_vars + i - 1)});
                clauses.push_back({F(num_vars + i - 1), T(num_vars + i)});
            }
            clauses.push_back({F(amo_clause.back()), F(num_vars + amo_clause.size() - 2)});
            num_vars += amo_clause.size() - 1;
        }
    }
    pair<bool, vector<int>> solve(bool construct) {
        graph<1, edge, 0> g(2 * num_vars);
        for (auto& [x, y] : clauses) {
            g.add_edge({NOT(x), y});
            g.add_edge({NOT(y), x});
        }
        vector<vector<int>> sccs = find_sccs(g);
        vector<int> scc_of(2 * num_vars);
        for (int i = 0; i < sccs.size(); i++) {
            for (int v : sccs[i]) {
                scc_of[v] = i;
            }
        }
        bool can = true;
        for (int var = 0; var < num_vars; var++) {
            can &= scc_of[T(var)] != scc_of[F(var)];
        }
        vector<int> assignment;
        if (can and construct) {
            assignment.resize(2 * num_vars, true);
            for (vector<int>& scc : sccs) {
                if (ranges::any_of(scc, [&](int u) {
                        return ranges::any_of(g[u], [&](int e) {
                            return not assignment[g(e).v];
                        });
                    })) {
                    for (int v : scc) {
                        assignment[v] = false;
                    }
                }
                for (int v : scc) {
                    assignment[NOT(v)] = not assignment[v];
                }
            }
        }
        return {can, assignment};
    }
};
