#include <stdio.h>
#include <stdlib.h>


int main(){
    int d=0,uc=0,lc=0,sp=0,nl=0;
    FILE* fp;

    if ((fp = fopen("test2.txt", "r")) == NULL){
        printf("Cannot open the file!\n");
        return 0;
    }

    char c = fgetc(fp);

    while (c != EOF){
        if (c>= 'A' && c<= 'Z') uc++;
        else if (c>= 'a' && c<= 'z') lc++;
        else if (c>='0' && c<= '9') d++;
        else if (c=='\r' || c== '\n') nl++;
        else sp++;

        c = fgetc(fp);
    }
    printf("d=%d, uc=%d, lc=%d, nl=%d, sp=%d\n", d, uc, lc, nl, sp);

    fclose(fp);

    return 0;
}