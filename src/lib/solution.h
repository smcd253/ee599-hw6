#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <iostream>
#include <vector>       // std::vector<int>
#include <stack>        // std::order_stack<int>
#include <set>          // std::set<int>
#include <map>          // std::map<int std::set<int>>
#include <iterator>     // std::set::iterator

#ifdef __linux__ 
    #include <climits>      // INT_MAX (linux)

#elif __APPLE__
    #include <limits>       // INT_MAX (darwin)
#endif

#include <queue>        // std::queue<TreeNode*>

/****** Problem 3 ******/
class Graph {
    public:
        std::map<int, std::set<int>> v_;
        Graph(std::map<int, std::set<int>> &vertices) : v_(vertices) {}

        // member functions
        std::vector<int> dfs(int vertex);
};
#endif

