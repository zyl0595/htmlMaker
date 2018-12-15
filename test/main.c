#include <stdio.h>
#include "html_maker.h"

#define PROGRAM_HOLD get_char_hold();
static void get_char_hold(void)
{
    int ch;
    ch = getchar();
}


int main(void)
{
    int c; // note: int, not char, required to handle EOF
    FILE* fp = fopen("../../test/test.html", "r");

    if(!fp) {
        printf("File opening failed");
        PROGRAM_HOLD
        return 0;
    }

    while ((c = fgetc(fp)) != EOF) { // standard C I/O file reading loop
        putchar(c);
    }

    if (ferror(fp))
        printf("\r\nI/O error when reading");
    else if (feof(fp))
        printf("\r\nEnd of file reached successfully");

    fclose(fp);
    
    PROGRAM_HOLD
    return 1;
}