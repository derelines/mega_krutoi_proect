#include <iostream>
#include <chrono>
#include <thread>
#include "Timer.h"
#include <typeinfo>

using namespace std;

// Функция для запуска таймера
void timer(int minutes)
{
    // Преобразуем минуты в секунды
    int seconds = minutes * 60;

    // Выводим сообщение о том, что таймер запущен
    cout << "Таймер запущен на " << minutes << ((minutes == 1) ? " минуту" : " минут") << endl;

    // Запускаем таймер с помощью цикла
    for (int i = seconds; i > 0; i--)
    {
        // Приостанавливаем поток на 1 секунду
        this_thread::sleep_for(chrono::seconds(1));

        // Выводим оставшееся время в формате минут:секунд
        cout << i / 60 << ":" << i % 60 << endl;
    }

    cout << "Время вышло!" << endl;
}

int Timer()
{
    int minutes;

    // Запрашиваем время у пользователя
    cout << "Введите время таймера в минутах: ";
    cin >> minutes;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Вы ввели не число!" << endl;
    }
    else
    {
        timer(minutes);
    }

    return 0;
}