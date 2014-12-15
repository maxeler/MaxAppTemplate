#include <stdio.h>
#include <stdlib.h>

void add(int ticks, int32_t *in, int scalar, int32_t *s) {
    const int size = 2;
    int sizeBytes = size * sizeof(int32_t);
    int32_t *in_buf = malloc(sizeBytes);
    for(int i = 0; i < ticks; i++) {
        int mod = i%sizeBytes;
        in_buf[mod] = in[i];
        if(mod == 0) {
            int si = i / size;
            s[si] = scalar;
            for(int j = 0; j < size; j++) {
                s[si] += in_buf[j];
            }
        }
    }
}


