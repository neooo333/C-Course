// Prints the weekday name for a number 1–7
#include <stdio.h>

void DayName (void){

        int week_number;

        printf ("Please enter weekday number: ");
        scanf ("%d", &week_number);
        
        const char* list_days [] = {
            "Sunday", "Monday" , "Tuesday", 
            "Wednesday", "Thursday", "Friday",
            "Saturday"
                    };
                    
        if (week_number <= 0 || week_number > 7){
            printf ("Invalid weekday number \n");
            return;
        }


        printf ("Day %d is a %s \n", week_number, list_days[week_number-1]);
}

int main (void){
    DayName ();
    return 0;
}