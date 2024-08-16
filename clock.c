#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

void fill_time(char*buffer,int format){
     time_t raw_time;
    struct tm*current_time;
    time(&raw_time);
    current_time=localtime(&raw_time);
    if(format==1){
        strftime(buffer,50, "%H:%M:%S",current_time);
    }else{
         strftime(buffer,50, "%I:%M:%S %p",current_time);
    }
}
void fill_date(char*buffer){
    time_t raw_time;
    struct tm*current_time;
    time(&raw_time);
    current_time=localtime(&raw_time);
    strftime(buffer,100,"%A %B %D %Y",current_time);
}

int input_format(){
    int format;
    printf("\nchoose the format: ");
    printf("\n1. 24 hour format");
    printf("\n2. 12 hour format(default)");
    printf("\nmake a choice(1/2): ");
    scanf("%d",&format);
    return format;
}
void clear_screen(){
    #ifdef  _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
int main(){
    char time[50],date[100];
    int format=input_format();
    while(1){
        fill_time(time,format);
        fill_date(date);
        clear_screen();
        printf("current time:%s\n",time);
        printf("date:%s\n",date);
        sleep(1);//sleep for 1sec
    }
    return 0;
}