#include "temp_api.h"

void printHelp() 
{
    printf("Programm for analize temperature sensor data\n\n");
    printf("Use:\n");
    printf("  program -f <filename.csv> [-m <num_month>] [-h]\n\n");
    printf("Input Param:\n");
    printf("  -h              Help\n");
    printf("  -f <file>       Input CSV file\n");
    printf("  -m <month>      Num Month (1-12) for print statistic\n\n");
    printf("Example:\n");
    printf("  program -f data.csv\n");
    printf("  program -f data.csv -m 7\n");
    printf("  program -h\n");
}

int isValidMonth(int month) 
{
    return (month >= 1 && month <= 12);
}

void printStatistics(struct SensorTemp *data, int count, int filterMonth) 
{
    if (count == 0) 
    {
        printf("NO DATA FOR ANALIZE.\n");
        return;
    }
    
    if (filterMonth > 0) 
    {
        printf("\n========================================\n");
        printf("STATISTIC FOR ONE MONTH %d\n", filterMonth);
        printf("========================================\n");
    }
    
    if (filterMonth == 0) 
    {
        printf("\n========================================\n");
        printf("STATISTIC ALL MONTH\n");
        printf("========================================\n");
    }
    
    for (int i = 0; i < count; i++) 
    {
        if (filterMonth > 0 && data[i].month != filterMonth) 
        {
            continue;
        }
        
        // Проверяем, выводили ли уже этот месяц и год
        int alreadyPrinted = 0;
        for (int k = 0; k < i; k++) 
        {
            if (data[i].year == data[k].year && data[i].month == data[k].month) 
            {
                alreadyPrinted = 1;
                break;
            }
        }
        
        if (!alreadyPrinted) 
        {
            float sum = 0;
            int minTemp = 100;
            int maxTemp = -100;
            int cnt = 0;
            
            for (int j = 0; j < count; j++) 
            {
                if (data[j].year == data[i].year && data[j].month == data[i].month) 
                {
                    sum += data[j].temp;
                    if (data[j].temp < minTemp) minTemp = data[j].temp;
                    if (data[j].temp > maxTemp) maxTemp = data[j].temp;
                    cnt++;
                }
            }
            
            printf("%d-%02d: middle %.1f, min %d, max %d (record: %d)\n", 
                   data[i].year, data[i].month, sum / cnt, minTemp, maxTemp, cnt);
        }
    }
    
    if (filterMonth == 0) 
    {
        printf("\n========================================\n");
        printf("STATISTIC ONLY YEAR\n");
        printf("========================================\n");
        
        for (int i = 0; i < count; i++) 
        {
            int alreadyPrinted = 0;
            for (int k = 0; k < i; k++) 
            {
                if (data[i].year == data[k].year) 
                {
                    alreadyPrinted = 1;
                    break;
                }
            }
            
            if (!alreadyPrinted) 
            {
                float sum = 0;
                int minTemp = 100;
                int maxTemp = -100;
                int cnt = 0;
                
                for (int j = 0; j < count; j++) 
                {
                    if (data[j].year == data[i].year) 
                    {
                        sum += data[j].temp;
                        if (data[j].temp < minTemp) minTemp = data[j].temp;
                        if (data[j].temp > maxTemp) maxTemp = data[j].temp;
                        cnt++;
                    }
                }
                
                printf("%d year: middle %.1f, min %d, max %d (record: %d)\n", 
                       data[i].year, sum / cnt, minTemp, maxTemp, cnt);
            }
        }
    } 
}

int readCSVFile(const char *filename, struct SensorTemp **data, int *size) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) 
    {
        printf("ERROR: File is not open %s\n", filename);
        return -1;
    }
    
    char line[MAX_LINE];
    int count = 0;
    int lineNum = 0;
    int capacity = 10; 
    
    *data = (struct SensorTemp*)malloc(capacity * sizeof(struct SensorTemp));
    if (*data == NULL) 
    {
        printf("ERROR: Memory allocation failed\n");
        fclose(file);
        return -1;
    }
    
    if (fgets(line, MAX_LINE, file) != NULL) 
    {
        lineNum++;
        int year, month, day, hour, minute, temp;
        if (sscanf(line, "%d %d %d %d %d %d", &year, &month, &day, &hour, &minute, &temp) != 6 &&
            sscanf(line, "%d;%d;%d;%d;%d;%d", &year, &month, &day, &hour, &minute, &temp) != 6 &&
            sscanf(line, "%d,%d,%d,%d,%d,%d", &year, &month, &day, &hour, &minute, &temp) != 6) 
        {
            printf("Skip HEADER: %s", line);
        } else 
        {
            (*data)[count].year = year;
            (*data)[count].month = month;
            (*data)[count].day = day;
            (*data)[count].hour = hour;
            (*data)[count].minute = minute;
            (*data)[count].temp = temp;
            count++;
        }
    }
    
    while (fgets(line, MAX_LINE, file) != NULL) 
    {
        lineNum++;
        line[strcspn(line, "\n")] = 0;
        int year, month, day, hour, minute, temp;
        int parsed = 0;
        
        if (sscanf(line, "%d %d %d %d %d %d", &year, &month, &day, &hour, &minute, &temp) == 6) 
        {
            parsed = 1;
        }
        else if (sscanf(line, "%d;%d;%d;%d;%d;%d", &year, &month, &day, &hour, &minute, &temp) == 6) 
        {
            parsed = 1;
        }
        else if (sscanf(line, "%d,%d,%d,%d,%d,%d", &year, &month, &day, &hour, &minute, &temp) == 6) 
        {
            parsed = 1;
        }
        
        if (parsed) 
        {
            if (temp < -99 || temp > 99) 
            {
                printf("WARNING: LINE %d: no correct temperature %d, \n", lineNum, temp);
                continue;
            }
            
            if (count >= capacity) 
            {
                capacity *= 2;
                struct SensorTemp *newData = (struct SensorTemp*)realloc(*data, capacity * sizeof(struct SensorTemp));
                if (newData == NULL) 
                {
                    printf("ERROR: Memory reallocation failed\n");
                    free(*data);
                    fclose(file);
                    return -1;
                }
                *data = newData;
            }
            
            (*data)[count].year = year;
            (*data)[count].month = month;
            (*data)[count].day = day;
            (*data)[count].hour = hour;
            (*data)[count].minute = minute;
            (*data)[count].temp = temp;
            count++;
        } 
        else 
        {
            if (strlen(line) > 0) 
            {
                printf("WARNING: LINE %d: no correct format: %s\n", lineNum, line);
            }
        }
    }
    
    if (count > 0) 
    {
        struct SensorTemp *newData = (struct SensorTemp*)realloc(*data, count * sizeof(struct SensorTemp));
        if (newData != NULL) 
        {
            *data = newData;
        }
    }
    
    *size = count;
    fclose(file);
    return count;
}
