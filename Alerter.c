#include "Alerter.h"


int sendemail = 0;
int LedOn = 0;

int emailAlerter()
{
    sendemail = 1;
    return 1;
}

int ledAlerter()
{
    LedOn = 1;
    return 1;
}