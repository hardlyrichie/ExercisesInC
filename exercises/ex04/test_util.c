#include "minunit.h"
#include "trout/util.h"
#include <string.h>

static char *test() {
    char *result = icmpcode_v4(0);
    char *message = "Test failed: icmpcode_v4(0) should return \"network unreachable\"";
    mu_assert(message, strcmp(result, "network unreachable") == 0);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = test();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    
    return result != 0;
}