# EE599 HW6 - Graphs and Various Sorting Algorithms

Created - Spencer McDonough : 02/27/2020<br>
Last Modified - Spencer McDonough : 02/27/2020<br>
University of Southern California

## Q1 - Graph-Related Facts
1. A tree is a **directed** graph.
2. A tree is a **connected** graph.
3. A tree is an **acyclic** graph.
4. In a tree, there **is not** a path from each vertex to all other vertices.
5. A simple graph is a graph that **contains no self-loops**.

## Q2 - MergeSort Visualization
![A visualization of MergeSort on the string 'ilovecoding'](ee599-hw6-q2-mergesort.png)

## Q3 - Graphs - Iterative Depth First Search
**Compilation Instructions**
```bash
# to run main
bazel run src/q3:main

# to run tests
bazel run tests:tests
```

**Runtime Analysis**
```c++
std::vector<int> Graph::dfs(int vertex)
```
Runtime = &theta;(n + m) where n = # vertices & m = # edges --> O(n)

## Q4 - Graphs - Iterative Depth First Search from All Nodes
**Compilation Instructions**
```bash
# to run main
bazel run src/q4:main

# to run tests
bazel run tests:tests
```

**Runtime Analysis**
```c++
std::vector<int> Graph::dfs_all()
```
Runtime = &theta;(n*(n + m)) where n = # vertices & m = # edges --> O(n^2)

## Q5 - Graphs - Maze Solver
**Compilation Instructions**
```bash
# to run main
bazel run src/q5:main

# to run tests
bazel run tests:tests
```

**Runtime Analysis**
```c++
bool PathFinder::find_path(std::pair<int, int> start, std::pair <int, int> end)
```
Runtime = &theta;(n + m) where n = # vertices & m = # edges --> O(n)

## Q6 - Graphs - Partition for Quick Sort
**Compilation Instructions**
```bash
# to run main
bazel run src/q6:main

# to run tests
bazel run tests:tests
```

**Runtime Analysis**
```c++
int QuickSort::partition(std::vector<int>& arr, int i)
```
Runtime = &theta;(6 + 3*n + 5) --> O(n)