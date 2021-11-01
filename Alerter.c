#include "Alerter.h"
#include "stats.h"

emailAlertCallCount = 0;
ledAlertCallCount = 0;

void emailAlerter()
{
    emailAlertCallCount = 1;
    
}

void ledAlerter()
{
    ledAlertCallCount = 1;
}