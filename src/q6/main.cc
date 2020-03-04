#include <iostream>
#include "src/lib/solution.h"

int main() 
{
    QuickSort qs;

    std::vector<int> input = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};

    std::vector<int> output = qs.partition(input, 9);

    printf("output = {");
    for(int i = 0; i < (int)output.size(); i++)
    {
        if(i < 9)
        {
        printf("%d, ", output[i]);
        }
        else
        {
        printf("%d}\n", output[i]);
        }
        
    }
}