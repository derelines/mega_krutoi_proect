#include <iostream> // Для вывода информации на экран
#include <ctime> // Для работы с типами time_t и tm
#include <thread> // Для функции sleep_for
#include <chrono> // Для типа duration

using namespace std;
using namespace std::chrono; // Для использования алиаса 1s

void NowTime() {
    setlocale(LC_ALL, "rus");
    while (true) { // Бесконечный цикл
        time_t now = time(0); // Текущее время в формате time_t
        tm tm_now; // Структура tm для хранения информации о дате и времени
        localtime_s(&tm_now, &now); // Инициализация структуры tm_now данными из now

        // Вывод информации на экран
        cout << "Год: " << 1900 + tm_now.tm_year << endl;
        cout << "Месяц: " << 1 + tm_now.tm_mon << endl;
        cout << "День: " << tm_now.tm_mday << endl;
        cout << "Часы: " << tm_now.tm_hour << endl;
        cout << "Минуты: " << tm_now.tm_min << endl;
        cout << "Секунды: " << tm_now.tm_sec << endl;

        // Засыпание на 1 секунду
        this_thread::sleep_for(1s);
        cout << "\033[2J\033[1;1H";
    }
}