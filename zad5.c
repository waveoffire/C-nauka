#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    char buf[BUF_SIZE];
    pid_t pid,ch_pid;
    int status;

    //check args
    if(argc !=2 || strcmp(argv[1],"-help")==0 || strcmp(argv[1],"-h")==0){
        printf("A program that writes numbers divisible by 3 to a user-specified file. \n");
        printf("Usage: %s filename. \n", argv[0]);
        return 1; 
        //args error return
    }
    //save numbers divisible by 3 to buffer
    for(int i=9;i<=99;i++){
        if(i%3==0){
            sprintf(buf, "%s%i ", buf,i);
        }
    }
    pid = fork();
    if(pid ==-1){
        //procces not created
        printf("Cannot create a process. \n");
        printf("Error: %s. \n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    if(pid == 0){
        //child process
        //create a new file, if exist delete text   buffer
        FILE *stream;
        stream = fopen(argv[1], "w");

        //check stream exist and writing is success
        if(!stream || fputs(buf, stream) == EOF) {
            printf("Error while creating/writing. %s\n Error: %s\n", argv[1], strerror(errno));
            fclose(stream);
            _exit(EXIT_FAILURE);
        }
        fclose(stream);
        _exit(EXIT_SUCCESS);
    }
    if(pid > 0){
        //parrent process

        ch_pid=wait(&status);
        if(WIFEXITED(status)){
            printf("Child process ended with status: %d\n",WEXITSTATUS(status));
        }
        if(status == EXIT_FAILURE) exit(EXIT_FAILURE);
        
    }

    //open file    non buffer

    return EXIT_SUCCESS; // normal program end
}