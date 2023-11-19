#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include <error.h>

#define NCOL 40
#define NLIN 16
#define SERVER_FIFO "SERVERFIFO"

char RUNNING = 1;

void termina(int sig, siginfo_t *info, void *ucontext) {
   RUNNING = 0;
}

int main(int argc, char * argv[]) {
   int x, y, interval, duration;
   struct sigaction sa;

   if (argc!=3) {
      fprintf(stderr, "[ERROR] Number of command line args!\n       ./bot <interval> <duration>\n");
      return 1;
   }
   if (sscanf(argv[1],"%d", &interval) != 1 ||
       sscanf(argv[2],"%d", &duration) != 1) {
      fprintf(stderr, "[ERROR] All args must be integers!\n");
      return 2;
   }
   srand(time(NULL));
   sa.sa_flags = SA_SIGINFO;
   sa.sa_sigaction = termina;
   sigaction(SIGINT, &sa, NULL);
   while (RUNNING) {
      sleep(interval);
      x = rand() % NCOL;
      y = rand() % NLIN;
      int fd = open (SERVER_FIFO,O_WRONLY);
     if (fd == -1)
    {
        perror("O programa recebeMSG não está a correr ");
        return -1;
    }
    int output[9];
    char xstr[3];
    char ystr[3];
    char dstr[3];
    sprintf(xstr,"%d",x);
    sprintf(ystr,"%d",y);
    sprintf(dstr,"%d",duration);
    sprintf(output,"%s %s %s", xstr, ystr, dstr);
    int size = write (fd,output, 9);
    close(fd);
    fflush(stdout);
   }
   return 0;
}
