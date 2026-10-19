#include "console.h"
#include <stdio.h>

void clearkeyboard(void)
{
  while(kbhit())
    getchar();
}

#if defined(__WINDOWS__)||defined(__WIN32__)
#include <windows.h>
#include <conio.h>

void gotoxy(int x,int y)
{
    HANDLE handle;
    COORD coord= {x-1,y-1};
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle,coord);
}

void clrscr(void)
{
    HANDLE handle;
    COORD coord= { 0, 0 };
    DWORD nbcar;
    CONSOLE_SCREEN_BUFFER_INFO info;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(handle,&info);
    FillConsoleOutputCharacter(handle, (TCHAR) ' ',info.dwSize.X *
                               info.dwSize.Y,coord,&nbcar);
    SetConsoleCursorPosition(handle,coord);
}

void delay(int milliseconde)
{
    fflush(stdout);
    Sleep(milliseconde);
}

#else

#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

int getch(void)
{
  struct termios oldattr, newattr;
  int ch;
  tcgetattr( STDIN_FILENO, &oldattr );
  newattr = oldattr;
  newattr.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
  return ch;
}

int getche(void)
{
  char c=getch();
  printf("%c",c);
  return(c);
}

void gotoxy(int x,int y)
{
    if(x<=0) x=1;
    if(y<=0) y=1;
    printf("\x1b[%d;%dH",y,x);
    fflush(stdout);
}

void clrscr(void)
{
    printf("\033[2J");
    fflush(stdout);
    gotoxy(0,0);
}

void delay(int milliseconde)
{
    fflush(stdout);
    usleep(1000*milliseconde);
}

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}

#endif
