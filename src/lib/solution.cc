#include "solution.h"

 

/******************** QUESTION 3 ********************/

// Runtime = &theta;(n + m) where n = # vertices & m = # edges --> O(n)
std::vector<int> Graph::dfs(int vertex)
{
    std::vector<int> result = {};
    result.reserve(v_.size());
    std::stack<int> order_stack;
    std::vector<bool> visited(this->v_.size(), false);
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

