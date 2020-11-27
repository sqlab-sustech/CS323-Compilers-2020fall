#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char *truepass = "what-you-see-is-not-what-you-get";

int check_authentication(char *password) {
    char password_buffer[10] = {0};
    int auth_flag = 0;

    strncpy(password_buffer, password, 0x10);

    if(strcmp(password_buffer, truepass) == 0)
        auth_flag = 1;

    return auth_flag;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <password>\n", argv[0]);
        exit(0);
    }

    if(check_authentication(argv[1]) == 1) {
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("      Access Granted.\n");
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
    } else {
        printf("\nAccess Denied.\n\n");
    }
}
