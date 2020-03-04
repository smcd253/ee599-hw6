#include <iostream>
#include "src/lib/solution.h"

int main() {
    QuickSort qs;

    int input[10] = {8, 3, 0, 1, 2, 9, 6, 7, 4, 5};

    int p = qs.partition(input, sizeof(input)/sizeof(int), 6);

    printf("output = {");
    for(int i = 0; i < 10; i++)
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