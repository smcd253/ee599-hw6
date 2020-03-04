#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <string>       // std::string
#include <iostream>     // CaptureStdout


/******************** std::vector<int> Graph::dfs ********************/
TEST(GRAPH_DFS, STANDARD)
{
    std::map<int, std::set<int>> vertices = {
    {0, {1, 2, 5}},
    {1, {0, 2, 3}},
    {2, {0, 1, 3}},
    {3, {1, 2, 6, 4}},
    {4, {3}},
    {5, {0}},
    {6, {3}}
    };
    Graph g(vertices);
    std::vector<int> actual = g.dfs(0);
    std::vector<int> expected = {0, 1, 2, 3, 4, 6, 5};
    EXPECT_EQ(expected, actual);
}

TEST(GRAPH_DFS, VERTEX_OUT_OF_RANGE)
{
    std::map<int, std::set<int>> vertices = {
    {0, {1, 2, 5}},
    {1, {0, 2, 3}},
    {2, {0, 1, 3}},
    {3, {1, 2, 6, 4}},
    {4, {3}},
    {5, {0}},
    {6, {3}}
    };
    Graph g(vertices);
    std::vector<int> actual = g.dfs(7);
    std::vector<int> expected = {};
    EXPECT_EQ(expected, actual);
}
TEST(GRAPH_DFS, NOT_CONNECTED)
{
    std::map<int, std::set<int>> vertices = {
    {0, {1}},
    {1, {2, 3}},
    {2, {0}},
    {3, {2, 4, 6}},
    {5, {6}}
    };
    Graph g(vertices);
    std::vector<int> actual = g.dfs(0);
    std::vector<int> expected = {0, 1, 2, 3, 4, 6};
    EXPECT_EQ(expected, actual);
}
TEST(GRAPH_DFS, EMPTY)
{
    std::map<int, std::set<int>> vertices = {};
    Graph g(vertices);
    std::vector<int> actual = g.dfs(0);
    std::vector<int> expected = {};
    EXPECT_EQ(expected, actual);
}

/******************** std::vector<int> Graph::dfs_all ********************/
TEST(GRAPH_DFS_ALL, STANDARD)
{
    std::map<int, std::set<int>> vertices = {
    {0, {1}},
    {1, {2, 3}},
    {2, {0}},
    {3, {2, 4, 6}},
    {5, {6}}
    };
    Graph g(vertices);
    std::vector<int> actual = g.dfs_all();
    std::vector<int> expected = {0, 1, 2, 3, 4, 6, 5};
    EXPECT_EQ(expected, actual);
}

TEST(GRAPH_DFS_ALL, VERTEX_OUT_OF_RANGE)
{
    std::map<int, std::set<int>> vertices = {
    {0, {1}},
    {1, {2, 3}},
    {2, {0}},
    {3, {2, 4, 6}},
    {5, {6}}
    };
    Graph g(vertices);
    std::vector<int> actual = g.dfs(7);
    std::vector<int> expected = {};
    EXPECT_EQ(expected, actual);
}

TEST(GRAPH_DFS_ALL, EMPTY)
{
    std::map<int, std::set<int>> vertices = {};
    Graph g(vertices);
    std::vector<int> actual = g.dfs(0);
    std::vector<int> expected = {};
    EXPECT_EQ(expected, actual);
}

/******************** bool PathFinder::find_path ********************/
TEST(PATH_FINDER_ALL, STANDARD_TRUE)
{
    std::vector<std::vector<int>> maze = {
    {1, 1, 0, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1}
    };
    PathFinder pf(maze);
    std::pair<int, int> start(0, 0);
    std::pair<int, int> dest(2, 4);
    bool actual = pf.find_path(start, dest);
    bool expected = true;
    EXPECT_EQ(expected, actual);
}

TEST(PATH_FINDER_ALL, STANDARD_FALSE)
{
    std::vector<std::vector<int>> maze = {
    {1, 1, 0, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1}
    };
    PathFinder pf(maze);
    std::pair<int, int> start(0, 0);
    std::pair<int, int> dest(4, 4);
    bool actual = pf.find_path(start, dest);
    bool expected = false;
    EXPECT_EQ(expected, actual);
}

TEST(PATH_FINDER_ALL, SEARCH_UP_TRUE)
{
    std::vector<std::vector<int>> maze = {
    {1, 1, 0, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1}
    };
    PathFinder pf(maze);
    std::pair<int, int> start(2, 3);
    std::pair<int, int> dest(0, 0);
    bool actual = pf.find_path(start, dest);
    bool expected = true;
    EXPECT_EQ(expected, actual);
}

TEST(PATH_FINDER_ALL, DEST_OUT_OF_BOUNDS)
{
    std::vector<std::vector<int>> maze = {
    {1, 1, 0, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1}
    };
    PathFinder pf(maze);
    std::pair<int, int> start(0, 0);
    std::pair<int, int> dest(5, 5);
    bool actual = pf.find_path(start, dest);
    bool expected = false;
    EXPECT_EQ(expected, actual);
}

TEST(PATH_FINDER_ALL, START_OUT_OF_BOUNDS)
{
    std::vector<std::vector<int>> maze = {
    {1, 1, 0, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1}
    };
    PathFinder pf(maze);
    std::pair<int, int> start(5, 5);
    std::pair<int, int> dest(2, 4);
    bool actual = pf.find_path(start, dest);
    bool expected = false;
    EXPECT_EQ(expected, actual);
}

/******************** bool QuickSort::partition ********************/
TEST(QUICKSORT_PARTITION, STANDARD)
{
    QuickSort qs;
    std::vector<int> input = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    std::vector<int> actual = qs.partition(input, 9);
    std::vector<int> expected = {5, 2, 3, 6, 12, 7, 14, 9, 10, 11};
    EXPECT_EQ(expected, actual);
}

TEST(QUICKSORT_PARTITION, I_OUT_OF_BOUNDS)
{
    QuickSort qs;
    std::vector<int> input = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    std::vector<int> actual = qs.partition(input, (int)input.size());
    std::vector<int> expected = {};
    EXPECT_EQ(expected, actual);
}

TEST(QUICKSORT_PARTITION, I_IS_MAX)
{
    QuickSort qs;
    std::vector<int> input = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    std::vector<int> actual = qs.partition(input, 6);
    std::vector<int> expected = {9, 7, 5, 11, 12, 2, 6, 3, 10, 14};
    EXPECT_EQ(expected, actual);
}

TEST(QUICKSORT_PARTITION, I_IS_MIN)
{
    QuickSort qs;
    std::vector<int> input = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    std::vector<int> actual = qs.partition(input, 5);
    std::vector<int> expected = {2, 7, 5, 11, 12, 6, 14, 3, 10, 9};
    EXPECT_EQ(expected, actual);
}