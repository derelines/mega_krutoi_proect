#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "Calendar.h"

using namespace std;

int Calendar()
{
    setlocale(LC_ALL, "RUS"); //устанавливаем русскую локаль

    time_t t; //объявляем переменную для работы со временем
    time(&t); //вычисляем текущее время

    struct tm timeinfo; //создаем структуру для хранения даты
    localtime_s(&timeinfo, &t); //заполняем структуру данными текущей даты

    //выводим на экран дату в формате ДД.ММ.ГГГГ
    cout << timeinfo.tm_mday << "." << timeinfo.tm_mon + 1 << "." << timeinfo.tm_year + 1900 << endl;
    return 0;
}