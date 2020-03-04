#include <iostream>
#include "src/lib/solution.h"

int main() {
    std::vector<std::vector<int>> maze = {
    {1, 1, 0, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1}
    };
    PathFinder pf(maze);
    std::pair<int, int> start(0, 0);
    std::pair<int, int> dest1(2, 4);
    printf("Is there a path from (0, 0) to (2, 4)?\n");
    bool result = pf.find_path(start, dest1);
    printf("Answer: %s\n", result ? "Yes" : "No");

    std::pair<int, int> dest2(4, 4);
    printf("Is there a path from (0, 0) to (4, 4)?\n");
    result = pf.find_path(start, dest2);
    printf("Answer: %s\n", result ? "Yes" : "No");
}