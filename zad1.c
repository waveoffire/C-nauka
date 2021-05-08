#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1
int counter=0;

int main(int argc, char *argv[])
{
    int input_fd, output_fd;   
    ssize_t ret_in, ret_out;    
    char buffer[BUF_SIZE];  

    if(argc != 2 || strcmp(argv[1], "--help") == 0) {
        printf("Usage: choose file in arg\n");
        return 1;
    }

    input_fd = open(argv[1], O_RDONLY);
    if(input_fd == -1) {
        perror("open");
        return 1;
    }

    output_fd = open(strcat(argv[1], ".red"), O_WRONLY | O_CREAT, 0644);
    if(output_fd == -1) {
        perror("create");
        return 1;
    }

    // Copy
    while((ret_in = read(input_fd, &buffer, BUF_SIZE)) > 0) {
        if(counter%3==0){
        ret_out = write(output_fd, &buffer, (ssize_t) ret_in);
        if(ret_out != ret_in) {
            perror("write");
            return 2;
        }
        }
        counter++;
    }

    close(input_fd);
    close(output_fd);

    return 0;

}