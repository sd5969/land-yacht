/* A Simple GPIO application
* Written by Derek Molloy for the book "Exploring BeagleBone: Tools and 
* Techniques for Building with Embedded Linux" by John Wiley & Sons, 2014
* ISBN 9781118935125. Please see the file README.md in the repository root 
* directory for copyright and GNU GPLv3 license information.            */

#include <iostream>
#include <unistd.h> //for usleep
#include "gpio/PWM.h"
using namespace exploringBB;
using namespace std;

// 570000 ns = ~-90 degrees
// 1460000 ns = ~0 degrees
// 2350000 ns = ~90 degrees

int main(){
   PWM pwm("pwm_test_P9_22.15");
   pwm.setPeriod(20000000); // 20 ms
   pwm.setDutyCycle(570000); // 0.57 ms
   pwm.setPolarity(PWM.ACTIVE_HIGH);
   pwm.run();
   while(true) {
      for(int i = 570; i < 2350; i++) {
         pwm.setDutyCycle(i*1000l);
         usleep(50000); // 50 ms
      }
   }
   return 0;
}
