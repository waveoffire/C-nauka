#include <stdio.h>

int main (int argc,char * argv[]){

    FILE *wp;
    unsigned long counter = 0;
    int ch;

    if(argc!=2){
        printf("Usage: %s file_name\n",argv[0]);
        return 2;
    }

    wp = fopen(argv[1],"r");
    if(!wp){
        printf("Couldn't open file %s\n",argv[1]);
        return 3;
    }
    while((ch = fgetc(wp))!= EOF){
        fputc(ch,stdout);
        counter++;
    }
    fclose(wp);
    printf("\nFile %s contains %lu characters\n",argv[1],counter);
    return 0;
}