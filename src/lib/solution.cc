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

        std::set<int>::reverse_iterator it;
        for (it = this->v_[current_vertex].rbegin(); it != this->v_[current_vertex].rend(); ++it)
        {
            if(!visited[*it])
            {
                order_stack.push(*it);
            }
        }
    }

    return result;
}

// Runtime = &theta;(n + m) where n = # vertices & m = # edges --> O(n)
std::vector<int> Graph::dfs(int vertex)
{
    std::vector<int> result = {};
    if(vertex < (int)this->v_.size() && vertex >= 0)
    {
        std::vector<bool> visited(this->v_.size(), false);
        result = dfs_helper(vertex, visited);
    }
    return result;
}

/******************** QUESTION 4 ********************/
// Runtime = &theta;(n*(n + m)) where n = # vertices & m = # edges --> O(n^2)
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

/******************** QUESTION 5 ********************/
// recursive depth first search of a maze
bool find_path_helper(std::vector<std::vector<int>>& m, 
        std::vector<std::vector<bool>>& v, 
        std::pair<int, int> start, std::pair <int, int> end)
{
    bool result = false;

    // update visited matrix
    v[start.first][start.second] = true;

    // return true if we've foudn the end
    if(start == end)
    {
        return true;
    }

    // search neighbors
    std::pair<int, int> next_step;

    // down 
    if(!result && start.first < (int)m.size())
    {
        if(!v[start.first + 1][start.second] && 
            m[start.first + 1][start.second])
        {
            next_step = start;
            next_step.first++;
            result = find_path_helper(m, v, next_step, end);
        }
    }

    // right
    if(!result && start.second < (int)m.size())
    {
        if(!v[start.first][start.second + 1] && 
            m[start.first][start.second + 1])
        {
            next_step = start;
            next_step.second++;
            result = find_path_helper(m, v, next_step, end);
        }
    }

    // up
    if(!result && start.first > 0)
    {
        if(!v[start.first - 1][start.second] && 
            m[start.first - 1][start.second])
        {
            next_step = start;
            next_step.first--;
            result = find_path_helper(m, v, next_step, end);
        }
    }

    // left
    if(!result && start.second > 0)
    {
        if(!v[start.first][start.second - 1] && 
            m[start.first][start.second - 1])
        {
            next_step = start;
            next_step.second--;
            result = find_path_helper(m, v, next_step, end);
        }
    }
    return result;
}

// Runtime = &theta;(n + m) where n = height of maze & m = width of maze --> O(n)
bool PathFinder::find_path(std::pair<int, int> start, std::pair <int, int> end)
{
    bool result = false;
    if(start.first >= 0 && start.first < (int)this->m.size() &&
        start.second >= 0 && start.second < (int)this->m[0].size() &&
        end.first >= 0 && end.first < (int)this->m.size() &&
        end.second >= 0 && end.second < (int)this->m[0].size())
    {
        result = find_path_helper(this->m, this->v, start, end);
    }
    return result;
}

/******************** QUESTION 6 ********************/
void swap(int& a, int& b)
{
  int temp = a;
  a = b;
  b = temp;
}

// Runtime = &theta;(6 + 3*n + 5) --> O(n)
std::vector<int> QuickSort::partition(std::vector<int>& arr, int i)
{
    if(i < (int)arr.size() && i >= 0)
    {
        int pivot = arr[i];
        swap(arr[i], arr[(int)arr.size() - 1]);
        int k = 0;

        for (int j = 0; j < (int)arr.size() - 1; j++)
        {
            if(arr[j] < pivot)
            {
            swap(arr[k], arr[j]);
            k++;
            }
        }
        swap(arr[k], arr[(int)arr.size() - 1]);
        return arr;
    }   
    else
    {
        return {};
    }
    
}