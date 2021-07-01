#include <iostream>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
using namespace std;

int main()
{
  int consoleSize;
  struct winsize w;

  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  consoleSize = w.ws_col;

  cout << endl
       << endl
       << consoleSize << endl
       << endl;

  return 0;
}
