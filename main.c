#include <stdio.h>
#include "/opt/homebrew/Cellar/libomp/16.0.6/include/omp.h"

#define ARRAY_SIZE 10

float x[ARRAY_SIZE];
float p[ARRAY_SIZE];
float y = 2.0f;

int f(int i) {
    return i;
}

void atomicUpdate() {
    int i;

    for (i = 0; i < ARRAY_SIZE; i++) {
        x[i] = i + 1.0f;
        p[i] = i + 0.5f;
    }

    printf("Initial values:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("x[%d] = %.2f\n", i, x[i]);
        printf("p[%d] = %.2f\n", i, p[i]);
    }

    #pragma omp parallel for
    for (i = 0; i < ARRAY_SIZE; i++) {
        /* Protect against race conditions among multiple updates. */
        #pragma omp atomic
        x[i] += y;

        /* Protect against race conditions with updates through x. */
        #pragma omp atomic
        p[i] -= 1.0f;
    }

    printf("Updated values:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("x[%d] = %.2f\n", i, x[i]);
        printf("p[%d] = %.2f\n", i, p[i]);
    }

}

void atomicReadWriteUpdate() {
	int i;
    int temp[ARRAY_SIZE];

    // Parallel region with OpenMP
    #pragma omp parallel for
    for (i = 0; i < ARRAY_SIZE; i++) {
        /* Protect against race conditions with atomic read. */
        #pragma omp atomic read
        temp[i] = x[i];

        /* Perform some computation on temp. */
        temp[i] *= 2;

        /* Protect against race conditions with atomic write. */
        #pragma omp atomic write
        x[i] = temp[i];

        /* Protect against race conditions with atomic update. */
        #pragma omp atomic update
        x[i] *= 2;
    }

    printf("After atomicReadWriteUpdate:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("x[%d] = %.2f\n", i, x[i]);
    }
}

void atomicCapture() {
    int i;
    int temp1[ARRAY_SIZE]; // Temporary variable for capture
    int temp2[ARRAY_SIZE]; // Temporary variable for update

    for (i = 0; i < ARRAY_SIZE; i++) {
        int capture_val;
        int updated_val;

        // Atomic capture operation
        #pragma omp atomic capture
        {
            capture_val = x[f(i)];
            x[f(i)] += 1;
        }

        // Another atomic capture operation
        #pragma omp atomic capture
        {
            updated_val = x[f(i)]; // Capture the updated value
            x[f(i)] -= 3;          // Perform the update
        }

        temp1[i] = capture_val;
        temp2[i] = updated_val;
    }

    printf("After atomicCapture:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("x[%d] captured = %d, updated = %d\n", i, temp1[i], temp2[i]);
    }
}


int main() {
	atomicUpdate();
	atomicReadWriteUpdate();
	atomicCapture();

	return 0;
}
