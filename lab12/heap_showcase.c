#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct note {
    void (*printnote)();
    char *content;
} note;

note *notelist[5];
int count = 0;

void print_note_content(note *this) {
    puts(this->content);
}

void add_note() {
    int size;
    if(count >= 5) {
        puts("Full");
        return;
    }
    for(int i = 0; i < 5; i++){
        if(!notelist[i]){
            notelist[i] = (note*)malloc(sizeof(note));
            notelist[i]->printnote = print_note_content;
            printf("Note size: ");
            scanf("%d", &size);
            notelist[i]->content = (char*)malloc(size);
            printf("Content: ");
            read(0, notelist[i]->content, size);
            puts("Success!");
            count++;
            break;
        }
    }
}

void del_note() {
    int idx;
    printf("Index: ");
    scanf("%d", &idx);
    if(idx < 0 || idx >= count) {
        puts("Out of bound!");
        exit(0);
    }
    if(notelist[idx]) {
        free(notelist[idx]->content);
        free(notelist[idx]);
        puts("Success!");
    }
}

void print_note() {
    int idx;
    printf("Index: ");
    scanf("%d", &idx);
    if(idx < 0 || idx >= count) {
        puts("Out of bound!");
        exit(0);
    }
    if(notelist[idx]) {
        notelist[idx]->printnote(notelist[idx]);
    }
}

void magic() {
    system("/bin/sh");
}

void menu() {
    puts("----------------------");
    puts("       HackNote       ");
    puts("----------------------");
    puts(" 1. Add note          ");
    puts(" 2. Delete note       ");
    puts(" 3. Print note        ");
    puts(" 4. Exit              ");
    puts("----------------------");
    printf("Your choice: ");
};

int main() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    // a treater, assume we have info leak
    printf("%p\n", magic);

    int c;
    while(1) {
        menu();
        scanf("%d", &c);
        if(c == 1)
            add_note();
        else if(c == 2)
            del_note();
        else if(c == 3)
            print_note();
        else
            exit(0);
    }
    return 0;
}
