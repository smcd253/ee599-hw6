#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <iostream>     // for debugging
#include <vector>       // std::vector<int>
#include <stack>        // std::order_stack<int>
#include <set>          // std::set<int>
#include <map>          // std::map<int std::set<int>>
#include <iterator>     // std::set::iterator


/****** Problems 3 & 4 ******/
class Graph 
{
    private:
        std::vector<int> dfs_helper(int vertex, std::vector<bool>& visited);
    public:
        std::map<int, std::set<int>> v_;
        Graph(std::map<int, std::set<int>> &vertices) : v_(vertices) {}

        // member functions
        std::vector<int> dfs(int vertex);
        std::vector<int> dfs_all();
};

/****** Problem 5 ******/
class PathFinder
{
    private:
        std::vector<std::vector<int>> m;
        std::vector<std::vector<bool>> v;
    
    public:
        PathFinder(std::vector<std::vector<int>>& maze) : m(maze), 
            v(maze.size(), std::vector<bool>(maze[0].size(), false)) {}

        bool find_path(std::pair<int, int> start, std::pair <int, int> end);
};

/****** Problem 6 ******/
class QuickSort
{
    public:
        std::vector<int> partition(std::vector<int>& arr, int i);
};

#endif

