#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdio.h>
#include <inttypes.h>

#define MAX_LINE 200

#pragma pack(push,1)

// Структура для хранения записи о температуре
struct SensorTemp
{
    unsigned short year;
    unsigned short month;
    unsigned short day;
    unsigned short hour;
    unsigned short minute;
    short temp;
};

#pragma pack(pop)

// Функция для вывода справки
void printHelp();

// Функция для проверки корректности месяца
int isValidMonth(int month);

// Функция для вывода статистики
void printStatistics(struct SensorTemp *data, int count, int filterMonth);

// Функция для чтения CSV файла
int readCSVFile(const char *filename, struct SensorTemp **data, int *size);

#endif