#include "solution.h"

 

/******************** QUESTION 3 ********************/
// Runtime = &theta;(n + m) where n = # vertices & m = # edges --> O(n)
std::vector<int> Graph::dfs_helper(int vertex, std::vector<bool>& visited)
{
    std::vector<int> result = {};
    result.reserve(this->v_.size());
    std::stack<int> order_stack;
    int current_vertex = vertex;

    order_stack.push(current_vertex);
    while (!order_stack.empty())
    {   
        current_vertex = order_stack.top();
        order_stack.pop();

        if(!visited[current_vertex])
        {
            result.push_back(current_vertex);
            visited[current_vertex] = true;
        }

        std::set<int>::iterator it;
        for (it = this->v_[current_vertex].begin(); it != this->v_[current_vertex].end(); ++it)
        {
            if(!visited[*it])
            {
                order_stack.push(*it);
            }
        }
    }

    return result;
}

std::vector<int> Graph::dfs(int vertex)
{
    std::vector<int> result = {};
    if(vertex < (int)this->v_.size())
    {
        std::vector<bool> visited(this->v_.size(), false);
        result = dfs_helper(vertex, visited);
    }
    return result;
}

/******************** QUESTION 4 ********************/
std::vector<int> Graph::dfs_all()
{
    std::vector<int> result = {};
    std::vector<bool> visited(this->v_.size(), false);
    for(int v = 0; v < (int)this->v_.size(); v++)
    {
        std::vector<int> temp = dfs_helper(v, visited);
        result.insert(result.end(), temp.begin(), temp.end());
    }
    return result;
}
