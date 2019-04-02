#include <stdio.h>
#include <termios.h>
#include <unistd.h>

// https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux

char getch() {
  /*#include <unistd.h>   //_getch*/
  /*#include <termios.h>  //_getch*/
  char buf = 0;
  struct termios old = {0};
  fflush(stdout);
  if (tcgetattr(0, &old) < 0)
    perror("tcsetattr()");
  old.c_lflag &= ~ICANON;
  old.c_lflag &= ~ECHO;
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &old) < 0)
    perror("tcsetattr ICANON");
  if (read(0, &buf, 1) < 0)
    perror("read()");
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;
  if (tcsetattr(0, TCSADRAIN, &old) < 0)
    perror("tcsetattr ~ICANON");
  printf("%c\n", buf);
  return buf;
}

/* Let's test it out */
int main(void) {
  char c;
  printf("(getche example) please type a letter: ");
  c = getch();
  printf("\nYou typed: %c\n", c);
  printf("(getch example) please type a letter...");
  c = getch();
  printf("\nYou typed: %c\n", c);
  return 0;
}