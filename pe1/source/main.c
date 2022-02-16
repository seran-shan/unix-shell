#include<stdio.h>
#include<time.h>
#include<stdlib.h>

char selected;

//TODO - Complete this.
/**
 * @brief This is the method that will be called if user choses to schedule an alarm.
 * 
 */
void schedule(){
    printf("You chose to schedule.\n");
}

//TODO - Complete this.
/**
 * @brief This is the method that will be called if user choses to list all alarms.
 * 
 */
void list(){
    printf("You chose to display list.\n");
}

//TODO - Complete this.
/**
 * @brief This is the method that will be called if user choses to cancel an alarm.
 * The user will also be prompted an input where the program will tell the user to 
 * write the ID of the alarm to cancel.
 * 
 */
void cancel(){
    printf("You chose to cancel an alarm.\n");
}

//TODO - Complete this.
/**
 * @brief This is the method that will be called if user choses to exit out of the program.
 * 
 */
void optOut(){
    printf("Goodbye!\n");
}

void checkInput(){
    switch (selected)
    {
    case 's':
        schedule();
        break;
    case 'l':
        list();
        break;
    case 'c':
        cancel();
        break;
    case 'x':
        optOut();
        break;
    default:
        printf("Nothing selected \n");
        break;
    }
}

//TODO - Not finished, will be updated.
/**
 * @brief This is the main method, and will display a menu.
 * 
 */
int main(){
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Welcome to the alarm clock! It is currently %d-%d-%d %d:%d:%d\n", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("Please enter \"s\" (schedule), \"l\" (list), \"c\" (cancel), \"x\" (exit) \n");
    selected = getchar();
    checkInput();
    return 0;
}