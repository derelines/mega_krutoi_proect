#include <iostream> // Для вывода информации на экран
#include <ctime> // Для работы с типами time_t и tm
#include <thread> // Для функции sleep_for
#include <chrono> // Для типа duration
#include "NowTime.h"
#include "Timer.h"
#include "Secundomer.h"
#include "Alarm.h"
#include "Calendar.h"

using namespace std;
using namespace std::chrono; // Для использования алиаса 1s

int main() 
    {
	setlocale(LC_ALL, "ru");
	int n;
	cout << "Какую программу вы хотите запустить?\n1) Показать текущее время\n2) Таймер\n3) Секундомер\n4) Будильник\n5) Календарь\n6) Выход из программы\n" << endl;
	cin >> n;
	while (n > 4 && n < 1) {
		cout << "Введите ваш символ: ";  cin >> n;
	}
	switch (n) {
	case 1:
		NowTime();
		break;

	case 2:
		Timer();
		break;

	case 3:
		Secundomer();
		break;

	case 4:
		Alarm();
		break;

	case 5:
		Calendar();
		break;

	case 6:
		break;
	}

    }
