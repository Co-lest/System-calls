#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    //int arr[4];
    char mess[13];
    int fd = open("sum", O_RDONLY);
    if (fd == -1){
        return 1;
    }
    read(fd, &mess, 13);
    //write(fd, mess, 13);
    printf("Received: %s from main1.c\n", mess);

    close(fd);
    return 0;
}