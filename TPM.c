#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include <error.h>
#define SERVER_FIFO "SERVERFIFO"


int main(){
    int fd = open (SERVER_FIFO,O_WRONLY);
     if (fd == -1)
    {
        perror("O programa recebeMSG não está a correr ");
        return -1;
    }
    int size = write (fd,"ola\n",4);
    close(fd);

}