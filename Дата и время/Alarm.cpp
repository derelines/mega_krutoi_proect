#include <windows.h>
#include <process.h>
#include <iostream>
#include <stdlib.h>
#include "Alarm.h"
#include <conio.h>
using namespace std;

int e;

void gotoxy(int xpos, int ypos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}
void prin(int x)
{
    if (x < 10)
        cout << '0';
    cout << x;
}
void Thread(void* pParams)
{
    HANDLE timer;
    LARGE_INTEGER li;
    li.QuadPart = -e * 600000000;
    timer = CreateWaitableTimer(NULL, true, TEXT("timer1"));
    SetWaitableTimer(timer, &li, 0, NULL, NULL, true);

    SetSystemPowerState(true, true);

    WaitForSingleObject(timer, INFINITE);
    SetThreadExecutionState(ES_DISPLAY_REQUIRED);
    CancelWaitableTimer(timer);
}

void Alarm()
{
    int c, m, a, b, f, t;
    bool z = true, r = true;
    char x[2], y[2], s[6];

    SYSTEMTIME st;
    setlocale(LC_ALL, "");

    cout << "Введите время: ";
    cin >> s;

    x[0] = s[0];
    x[1] = s[1];
    y[0] = s[3];
    y[1] = s[4];

    c = atoi(x);
    m = atoi(y);

    cout << "Текущие время: \nОсталось: ";

    while (z)
    {
        GetSystemTime(&st);
        a = st.wHour + 7;
        b = st.wMinute;

        f = c + 24 - a;
        t = m - b;
        if (t < 0)
        {
            f--;
            t += 60;
        }
        if (f > 23)
            f -= 24;

        if (r)
        {
            r = false;
            e = f * 60 + t - 3;
            _beginthread(Thread, 0, NULL);
        }

        gotoxy(15, 1);
        prin(a);
        cout << ':';
        prin(b);

        gotoxy(10, 2);
        prin(f);
        cout << ':';
        prin(t);

        if (c == a && m == b)
            z = false;
        Sleep(1000);
    }

    cout << "\n\nДля завершения нажмите Enter...";

    while (_kbhit())
    {
        cout << '\a';
        Sleep(1000);
    }
}