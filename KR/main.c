#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "temp_api.h"

int main(int argc, char* argv[])
{
    struct SensorTemp *records = NULL;
    int recordCount = 0;
    char *inputFile = NULL;
    int filterMonth = 0;
    int showHelp = 0;

    
    for (int i = 1; i < argc; i++) 
    {
        if (strcmp(argv[i], "-h") == 0) 
        {
            showHelp = 1;
        }
        else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) 
        {
            inputFile = argv[++i];
        }
        else if (strcmp(argv[i], "-m") == 0 && i + 1 < argc) 
        {
            filterMonth = atoi(argv[++i]);
            if (!isValidMonth(filterMonth)) 
            {
                printf("ERROR: Month may be 1 - 12\n");
                return 1;
            }
        }
        else 
        {
            printf("ERROR: Unknown param %s\n", argv[i]);
            printHelp();
            return 1;
        }
    }

    if (showHelp) 
    {
        printHelp();
        return 0;
    }
    
    if (inputFile == NULL) 
    {
        printf("ERROR: File input not specified\n");
        printHelp();
        return 1;
    }

    recordCount = readCSVFile(inputFile, &records, &recordCount);
    if (recordCount < 0) 
    {
        if (records != NULL) free(records);
        return 1;
    }
    
    if (recordCount == 0) 
    {
        printf("In file no data\n");
        if (records != NULL) free(records);
        return 1;
    }
    
    printf("\nLoad record: %d\n", recordCount);
    
    printStatistics(records, recordCount, filterMonth);

    free(records);
    
    return 0;
}