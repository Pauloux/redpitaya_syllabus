#include <stdlib.h>
#include <stdio.h>
#include "ledlib.h"

int main(int argc, char **argv)
{int status=0,GPIO;
 unsigned char *h;
 if (argc>1)
    GPIO=atoi(argv[1]);
 else
    GPIO=10;
 h=red_gpio_init(GPIO);
 red_gpio_set_cfgpin(h,GPIO); // LED0

 while (1) {
    red_gpio_output(h,GPIO,status); usleep(TIMESLEEP);
//    printf("status=%x\n",status);
    status^=0xff;
 }
 red_gpio_cleanup();
 return 0;
}
