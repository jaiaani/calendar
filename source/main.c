#include <stdio.h>
#include <stdlib.h>

int get_1st_weekDay(int year){
    
    int d;
    d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;

    return d;
}

int main(){

 // system("Color 1");
    printf("\033[1;35m"); 

    int year, startingDay;

    printf("\n Enter your desired year: ");
    scanf("%d", &year);


    printf("\033[0m");

    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int weekDays = 0;
    
    if((year % 4 == 0 && year && 100 != 0) || year % 400 == 0){
        monthDays[1] = 29;
    }

    startingDay = get_1st_weekDay(year);

    

    for(int month = 0; month < 12; month++){
        
        printf("\n\n---------------%s-------------------\n",months[month]);
        printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");

        for (weekDays = 0; weekDays < startingDay; weekDays++)
             printf("     ");
    
        for(int day = 1; day <= monthDays[month]; day++){
            printf("%5i", day);

            if(++weekDays> 6){
                printf("\n");
                weekDays = 0;
            }
            startingDay = weekDays;
        }
    }

    printf("\n \n");

    return 0;
}

/*
The difference between char *months[] and char months[] lies in how they store the strings:

    char *months[]: This declares an array of pointers to strings. Each element of the array is a pointer to the first character of a string. In this case, the array months holds pointers to string literals "January", "February", etc. The strings themselves are stored as separate entities in memory, and the array months holds pointers to the memory locations where these strings are stored.

    char months[]: This declares a two-dimensional array of characters. It's effectively an array of character arrays, where each element of months is itself an array of characters representing a month name. In this case, each element of months directly stores the characters of the corresponding month name, without using pointers to external memory locations.

Here's a brief comparison:

    With char *months[], you have an array of pointers, and the strings themselves are stored in read-only memory (typically in the data segment of the program). This means the strings are immutable.
    With char months[], you have a two-dimensional array of characters, and the strings are stored directly in the memory allocated for months. This allows you to modify the strings if needed, but it consumes more memory because it stores each string in the array itself
*/