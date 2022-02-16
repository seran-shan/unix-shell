#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void schedule(){
    printf("You chose to schedule.\n");
}

void list(){
    printf("You chose to display list.\n");
}

void cancel(){
    printf("You chose to cancel an alarm.\n");
}

void optOut(){
    printf("You chose to exit.\n");
}

int main(){
    time_t tm;
    time(&tm);
    printf("Welcome to the alarm clock! It is currently %s \n", ctime(&tm));
    printf("Please enter \"s\" (schedule), \"l\" (list), \"c\" (cancel), \"x\" (exit) \n");
    char selected = getchar();
    
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
    return 0;
}