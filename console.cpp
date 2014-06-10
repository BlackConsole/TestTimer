#include "console.h"

#include <termios.h>
#include <sys/ioctl.h>

#include <QDebug>
using namespace std;


Console::Console(QObject *parent) :
    QObject(parent),fCC(0)
{
    ConsoleMode=0;

//    initscr();

    //printw("Black console organization 2014\nLord!!!");
}

Console::~Console()
{
    endwin();
}


void Console::hello_scr()
{
    WINDOW *wind_hello;
    wind_hello = newwin(5,35,getmaxy(stdscr)/2-3,getmaxx(stdscr)/2-15);
    curs_set(0);
    box(stdscr,'|','-');
    wprintw(wind_hello,"Black Console Company 2014\nLord v0.1\n");
    wattron(wind_hello, A_BOLD);
    wprintw(wind_hello,"\nPress any key to start work!");
    refresh();
    wrefresh(wind_hello);
    wgetch(wind_hello);
    delwin(wind_hello);//terminate
    clear();
    curs_set(TRUE);
}

void Console::execut()
{

}

void Console::process()
{
    printf("hohohoh\n");
    return;
    hello_scr();

    move(0,0);
    scrollok(stdscr,TRUE);
    cbreak();
//    raw();
//    nonl(); //не переносить строку
    noecho();
    keypad(stdscr, TRUE);
    echochar('@');
    QString StrIn(500);
    QString StrOut(500);
    fCC=new ConsoleControl(this);
    fCC->s_in.setString(&StrIn);
    fCC->s_out.setString(&StrOut);
    echochar('&');
    int n=0;
    while(1)
    {
    int i=0;
    int ch;
    char buf[100];

    printw("Lord[%d] >> ",n++);
    while ((ch=getch())!=10)
    {
        if (ch == KEY_BACKSPACE)
        {
            int x, y;
            if (i==0) continue;
            getyx(stdscr, y, x);
            mvwaddch(stdscr, y, x-1, ' ');
            refresh();
            move(y, x-1);
            i--;
            continue;
        }
        buf[i++]=ch;
        echochar(ch);
//        printw("%d ",(int)ch);
    }
    buf[i]=0;
    echochar('\n');
    if (ch==10 && buf[0]!=0)
    {
        //parse commands
        fCC->s_in<<buf;
        fCC->ParseAll();
        //echochar('\n');
    }
    QString line;

    while(!fCC->s_out.atEnd()){
        line=fCC->s_out.readLine();
        printw(qPrintable(line));
        echochar('\n');
      }
    refresh();
    }
}

void Console::stop()
{

}


