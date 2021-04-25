#include <stdio.h>

int main(int argc, char *argv[])
{

    FILE *wp;
    char word[41];

    wp = fopen("slowa.txt","a+");
    if(wp == NULL){
        fprintf(stderr,"Couldn't open file\n");
        return 4;
    }

    fputs("Proide words to add them to a file\n",stdout);
    fputs("To end enter: #\n", stdout);
    
    while((fscanf(stdin,"%40s",word)==1) && (word[0]!='#')) {
        fprintf(wp,"%s",word);
        fprintf(wp,"%s"," ");
    }

    
    rewind(wp);
    printf("\nContent of file:\n");
    while(fscanf(wp,"%s",word)==1){
        puts(word);
    }

   if(fclose(wp)!=0){
       fprintf(stderr,"Error while closing a file\n");
   }
    return 0;
}