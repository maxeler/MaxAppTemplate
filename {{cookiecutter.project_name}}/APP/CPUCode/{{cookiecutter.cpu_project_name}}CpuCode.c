{% if cookiecutter.slic_interface|lower == 'dynamic' %}
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Maxfiles.h"
#include "MaxSLiCInterface.h"

int main(void)
{
        const int size = 384;
        int sizeBytes = size * sizeof(int32_t);
        int32_t *x = malloc(sizeBytes);
        int32_t *y = malloc(sizeBytes);
        int32_t *s = malloc(sizeBytes);
        int scalar = 3;

        // TODO Generate input data
        for(int i = 0; i < size; ++i) {
                x[i] = random() % 100;
                y[i] = random() % 100;
        }

        max_file_t *maxfile = {{cookiecutter.stem_name}}_init();
        max_engine_t *engine = max_load(maxfile, "*");

        max_actions_t* act = max_actions_init(maxfile, "default");

        max_set_param_uint64t(act, "N", size);
        max_set_param_uint64t(act, "A", scalar);
        max_queue_input(act, "x", x, sizeBytes);
        max_queue_input(act, "y", y, sizeBytes);
        max_queue_output(act, "s", s, sizeBytes);

        printf("Running on DFE (mode: ComputeWithScalar)...\n");
        max_run(engine, act);
        max_unload(engine);

        // TODO Use result data
        for(int i = 0; i < size; ++i)
                if ( s[i] != x[i] + y[i] + scalar)
                        return 1;

        printf("Done.\n");
        return 0;
}
{% elif cookiecutter.slic_interface|lower == "advanced_static" %}
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Maxfiles.h"
#include "MaxSLiCInterface.h"

int main(void)
{
        const int size = 384;
        int sizeBytes = size * sizeof(int32_t);
        int32_t *x = malloc(sizeBytes);
        int32_t *y = malloc(sizeBytes);
        int32_t *s = malloc(sizeBytes);
        int scalar = 3;

        // TODO Generate input data
        for(int i = 0; i < size; ++i) {
                x[i] = random() % 100;
                y[i] = random() % 100;
        }

        max_file_t *maxfile = {{cookiecutter.stem_name}}_init();
        max_engine_t *engine = max_load(maxfile, "*");

        printf("Running on DFE (interface: ComputeWithScalar)...\n");

        {{cookiecutter.stem_name}}_actions_t run_scalar;
        run_scalar.param_N = size;
        run_scalar.param_A = scalar;
        run_scalar.instream_x = x;
        run_scalar.instream_y = y;
        run_scalar.outstream_s = s;

        {{cookiecutter.stem_name}}_run(engine, &run_scalar);

        // TODO Use result data
        for(int i = 0; i < size; ++i)
                if ( s[i] != x[i] + y[i] + scalar)
                        return 1;

        max_unload(engine);
        printf("Done.\n");
        return 0;
}
{% else %}
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Maxfiles.h"
#include "MaxSLiCInterface.h"

int main(void)
{
        const int size = 384;
        int sizeBytes = size * sizeof(int32_t);
        int32_t *x = malloc(sizeBytes);
        int32_t *y = malloc(sizeBytes);
        int32_t *s = malloc(sizeBytes);

        // TODO Generate input data
        for(int i = 0; i < size; ++i) {
                x[i] = random() % 100;
                y[i] = random() % 100;
        }

        printf("Running on DFE.\n");
        int scalar = 3;
        {{cookiecutter.stem_name}}(scalar, size, x, y, s);

        // TODO Use result data
        for(int i = 0; i < size; ++i)
                if ( s[i] != x[i] + y[i] + scalar)
                        return 1;

        printf("Done.\n");
        return 0;
}
{% endif %}
