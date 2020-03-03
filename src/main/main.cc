#include <iostream>
#include "src/lib/solution.h"

int main() {
    std::map<int, std::set<int>> vertices = {
    {1, {2, 3}},
    {2, {1, 3, 4, 5}},
    {3, {1, 2, 4}},
    {4, {2, 3, 4}}
    };
    Graph g(vertices);
    std::vector<int> dfs_v = g.dfs(1);
    printf("dfs_v = ");
    for(auto n : dfs_v)
    {
        printf("%d ", n);
    }
    printf("\n");
}