#include "constructs/vector.h"
#include "constructs/matrix.h"

int main(int argc, char** argv) {
    printf("TEST\n");

    // test stuff
    double values[3] = {324, 453, 542};
    vector* test_vec = construct_vector(values, 3);
    printf("%d\n", test_vec->raw_vector->size);
    print_vec(test_vec);
    destroy_vector(test_vec);
}
