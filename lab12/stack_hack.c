
/*
 * compile with (on Ubuntu 18.04): gcc stack_hack.c -o hack -m32 -fno-stack-protector -O0
 */

#include <stdlib.h>
#include <stdio.h>


void backdoor(char* cmd) {
    system(cmd);
}

void print_name() {
    char buf[32];
    printf("cheater2: %p\n", buf);
    printf("What's your name? ");
    scanf("%s", buf);
    printf("Hello, %s!\n", buf);
}

int main() {
    printf("cheater1: %p\n", backdoor);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    print_name();
    return EXIT_SUCCESS;
}
