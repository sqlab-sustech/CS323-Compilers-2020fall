#include "tac.h"
#include "mips32.h"

#define BUF_SIZE 0x10000

char buf[BUF_SIZE];

int main(int argc, char *argv[]){
    FILE *fp;
    tac *head;
    char c, *file;
    int size, len;

    if(argc != 2){
        fprintf(stderr, "Usage:\n");
        fprintf(stderr, "  %s <IR-file>\n", argv[0]);
        return 1;
    }
    file = argv[1];

    // read the IR code
    size = 0;
    fp = fopen(file, "r");
    while ((c = getc(fp)) != EOF)
        buf[size++] = c;
    buf[size] = '\x7f';
    fclose(fp);

    // write the target code
    len = strlen(file);
    file[len-2] = 's';
    file[len-1] = '\0';
    fp = stdout; // fopen(file, "w");
    head = tac_from_buffer(buf);
    mips32_gen(head, fp);
    // fclose(fp);

    return 0;
}
