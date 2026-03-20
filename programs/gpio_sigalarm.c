#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "ledlib.h"

volatile int status=0,GPIO; // declenche' a chaque appel du timer => exterieur
volatile unsigned char *h;

void test(int signum) {
    red_gpio_output((unsigned char*)h,GPIO,status);
    status^=0xff;
}

int main(int argc, char **argv)
{struct sigaction sa;
 struct itimerval timer;
 if (argc>1)
    GPIO=atoi(argv[1]);
 else
    GPIO=10;
 h=red_gpio_init(GPIO);
 red_gpio_set_cfgpin(h,GPIO); // LED0

 memset(&sa, 0,sizeof(sa));
 sa.sa_handler = &test;
 sigaction(SIGVTALRM,&sa, NULL);
 /* Configure the timer to expire after TIMESLEEP msec ... */
 timer.it_value.tv_sec = 0;
 timer.it_value.tv_usec = TIMESLEEP;
 /* ... and every TIMESLEEP usec after that. */
 timer.it_interval.tv_sec = 0;
 timer.it_interval.tv_usec = TIMESLEEP;
 setitimer(ITIMER_VIRTUAL, &timer, NULL);
 printf("pointer: %p\n",h);fflush(stdout);
 while(1) {};
 red_gpio_cleanup();
 return 0;
}

