#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "../headers/static_lib.h"
#include "../headers/dynamic_lib_link.h"

int main() {
    char tmp[] = "Hello, world!\0";
    int tmp_nol = 0;

    //function from static_lib.h
    tmp_nol = number_of_letter(tmp, 'l');

    //function from dynamic_lib_link.h
    convert_to_upper_case(tmp);

    printf("%d %s\n", tmp_nol, tmp);

    //load
    void *handle;
    int (*gcd)(int, int);
    char *error;

    handle = dlopen("libdynamic_runtime.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    dlerror();

    gcd = (int (*)(int, int)) dlsym(handle, "m_gcd");

    error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }


    printf("Enter two numbers: ");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d is %d\n", a, b, (*gcd)(a, b));

    dlclose(handle);
    return 0;
}
