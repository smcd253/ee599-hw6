#include <iostream>
#include "src/lib/solution.h"

int main() {
    QuickSort qs;

    std::vector<int> input = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};

    int p = qs.partition(input, 9);

    printf("output = {");
    for(int i = 0; i < (int)input.size(); i++)
    {
        if(i < 9)
        {
        printf("%d, ", input[i]);
        }
        else
        {
        printf("%d}\n", input[i]);
        }
        
    }
    printf("p = %d\n", p);
}