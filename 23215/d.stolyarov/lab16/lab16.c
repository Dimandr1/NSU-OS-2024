#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
int main(){
    printf("asd? [y/n]: ");
    int fd = open("/dev/tty", O_RDONLY);
    char c;
    struct termios tty, save;
    tcgetattr(fd, &tty);
    save = tty;
    tty.c_lflag &= ~(ICANON);
    tcsetattr(fd, TCSAFLUSH, &tty);
    read(fd, &c, 1);
    if(c == 'y' || c == 'n'){
        printf("\nended succeessfully\n");
    }
    else{
        printf("\nwrong symbol\n");
    }
    tcsetattr(fd, TCSANOW, &save);
    exit(0);
}