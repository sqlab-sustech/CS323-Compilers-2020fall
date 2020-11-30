
/*
 * compile with (on Ubuntu 18.04): gcc heap_hack.c -o hack -m32 -fno-stack-protector -O0
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define N 32

struct {
    char *content;
    int size;
} itemlist[N];


int read_num(){
    char buf[16], c;
    int i = 0;
    do{
        c = getchar();
        buf[i++] = c;
    } while(c!='\n' && i<16);
    while(c != '\n'){
        c = getchar();
    }
    return atoi(buf);
}

void dokodemo_doa(){
    system("/bin/sh");
}


void menu(){
    puts("1. Add a new item");
    puts("2. Delete an item");
    puts("3. Modify an item");
    puts("4. Exit");
}

void add(){
    int i, size;
    for(i = 0; i < N; ++i ) {
        if(itemlist[i].content == NULL) {
            printf("size>");
            size = read_num();
            if(size>0 && size<=127) {
                itemlist[i].content = malloc(size+1);
                itemlist[i].size = size;
                printf("content>");
                read(0, itemlist[i].content, itemlist[i].size);
            }
            return;
        }
    }
}

void del(){
    int i;
    printf("index>");
    i = read_num();
    if(i>=0 && i<N){
        free(itemlist[i].content);
    }
}

void mod(){
    int i;
    printf("index>");
    i = read_num();
    if(i>=0 && i<N) {
        printf("content>");
        read(0, itemlist[i].content, itemlist[i].size);
    }
}

void dsp(){
    int i;
    printf("index>");
    i = read_num();
    if(i>=0 && i<N) {
        printf("content>");
        // puts(itemlist[i].content);
        puts("April Fools!");
    }
}


int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

    int choice;

    itemlist[0].content = malloc(0);
    printf("%p %p %p %p\n", &itemlist, dokodemo_doa, &choice, itemlist[0].content);

    menu();
    while(1) {
        printf("choice>");
        choice = read_num();
        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                del();
                break;
            case 3:
                mod();
                break;
            case 9:
                dsp();
                break;
            default:
                puts("Bye");
                exit(0);
                break;
        }
    }
    return 0;
}
