#include "stats.h"
#include<math.h>

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    float sum = 0;
    
    if (setlength < 1)
    {
        s.average = NAN;
        s.min     = NAN;
        s.max     = NAN;
    }
    else
    {
        s.min     = numberset[0];
        s.max     = numberset[0];
        for (int i=0; i<setlength; i++)
        {
            if(numberset[i] < s.min)
            {
                s.min = numberset[i];
            }
            else if(numberset[i] > s.max)
            {
                s.max = numberset[i];
            }
            sum += numberset[i];
        }
        s.average = sum/setlength;
    }
    
    return s;
}
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if (computedStats.max > maxThreshold)
    {
        (*alerters[0])();
        (*alerters[1])();
    }
}
void emailAlerter()
{
  emailAlertCallCount = 1;
}

void ledAlerter()
{
  ledAlertCallCount = 1;
}
