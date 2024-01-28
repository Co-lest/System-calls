#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    //int arr[] = {1, 2, 3, 4};
    char mess[] = {"Sending data"};
    int fd = open("sum", O_WRONLY); 
    if (fd == -1){
        return 1;
    }
    write(fd, mess, 13);
    /*for (int i = 0; i < 4;i++){
       //write(fd, arr[i], sizeof(int));
       
    }*/
    
    close(fd);

    return 0;
}