#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void add(int ticks, int32_t *in, int scalar, int32_t *s);

int main(void)
{
        const int size = 64;
        int sizeBytes = size * sizeof(int32_t);
        int32_t *x = malloc(sizeBytes);
        int32_t *y = malloc(sizeBytes);
        int32_t *s = malloc(sizeBytes);
        int scalar = 3;

        // Generate input data
        for(int i = 0; i < size; ++i) {
                x[i] = random() % 100;
                y[i] = random() % 100;
        }

        int32_t *in = malloc(sizeBytes*2);

        // Rearrange data for streaming
        for(int i = 0; i < size; i++) {
            in[i*2] = x[i];
            in[(i*2)+1] = y[i];
        }

        int ticks = size*2;

        // Call
        add(ticks, in, scalar, s);

        return 0;
}
