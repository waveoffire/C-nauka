#include <stdio.h>
#include <string.h>
int main (int argc,char * argv[]){

    FILE *wp, *wp2;
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


    wp2 = fopen(strcat(argv[1], ".red"),"w");
    while((ch = fgetc(wp))!= EOF){
        if(counter%3==0){
            fputc(ch,wp2); 
        }
        counter++;
    }
    fclose(wp);
    fclose(wp2);
    printf("\nFile %s saved\n",argv[1]);
    return 0;
}