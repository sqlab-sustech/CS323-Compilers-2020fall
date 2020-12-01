/* compile with: gcc -o heapchunks heapchunks.c -g -m32 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    unsigned int lengths[] = {32, 4, 20, 0, 64, 32, 8, 12, 32, 32};
    unsigned int *ptr[10];
    int i;

    ptr[0] = malloc(lengths[0]);
    ptr[1] = malloc(lengths[1]);
    ptr[2] = malloc(lengths[2]);
    ptr[3] = malloc(lengths[3]);
    ptr[4] = malloc(lengths[4]);

    /* print distance between chunks, eg size of chunks */
    for(i = 0; i < 4; i++)
        printf("malloc(%2d) is at 0x%08x, %3d bytes to the next pointer\n", 
                lengths[i],
                (unsigned int)ptr[i],
                (ptr[i+1]-ptr[i])*sizeof(unsigned int));

   return 0;
}
