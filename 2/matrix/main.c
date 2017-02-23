#include <stdio.h>
#include <stdlib.h>

#include "DGraphAM.h"

#define MAX 10

int main(int argc, const char * argv[])
{
    int n;
    printf("Max Knoten: ");
    scanf("%d", &n);
    
    Init(n);
    
    PrintResult(n);
    // Destroy(n);
    
    TopSort();
    
    return 0;
}
