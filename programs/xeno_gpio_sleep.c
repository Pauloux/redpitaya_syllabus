#include <signal.h>
#include <stdio.h>
#include <time.h> // nanosleep
#include <native/task.h>
#include "ledlib.h"

RT_TASK blink_task;
unsigned char *h;

void catch_signal(int sig){}

void blink(void *arg){
 int status=0;
 struct timespec tim = {0,TIMESLEEP*1000};

 rt_printf("blink task\n");
 while(1)
   {red_gpio_output(h,0,status);
    status^=0xff;
    // rt_printf("%d\n",status);
    if (nanosleep(&tim,NULL) != 0) 
       {printf("erreur usleep\n");return;}
   }
}

int main(int argc, char *argv[]) 
{
 h=red_gpio_init();
 red_gpio_set_cfgpin(h,0); // LED0
 // Avoid memory swapping for this program
 mlockall(MCL_CURRENT|MCL_FUTURE);

 signal(SIGTERM,catch_signal);
 signal(SIGINT, catch_signal);

 rt_printf("hello RT world\n");
 rt_task_create(&blink_task, "blinkLed", 0, 99, 0);
 rt_task_start(&blink_task, &blink, NULL);

 pause();

 rt_task_delete(&blink_task);
 red_gpio_cleanup();
 return 0;
}
