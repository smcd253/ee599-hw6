#include <iostream>
#include "src/lib/solution.h"

int main() {
    std::map<int, std::set<int>> vertices = {
    {0, {1}},
    {1, {2, 3}},
    {2, {0}},
    {3, {2, 4, 6}},
    {5, {6}}
    };
    Graph g(vertices);
    std::vector<int> dfs_all_v = g.dfs_all();
    printf("dfs_all_v = ");
    for(auto n : dfs_all_v)
    {
        printf("%d ", n);
    }
    printf("\n");
}