#include "stats.h"      
#include "Alerter.h"
#include <math.h>

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

//Reports average, minimum and maximum
struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0; 
    float sumarray = 0; //Sum of struct
    float maximum = numberset[0]; //we save the first value of the struct for compairisong
    float minimum = numberset[0]; //we save the first value of the array for compairisong

    for(int i=0; i < setlength ; i++)
    {
        sumarray = sumarray + numberset[i];

        if(numberset[i] > maximum) //Calculate the maximum value
        {
            maximum = numberset[i];
        }

        if(numberset[i] < minimum ) //Calculate the maximum value
        {
            minimum = numberset[i];
        }
    }

    //All fields of computedStats (average, max, min) must be 
    //NaN for empty array
    if(sumarray == 0 && setlength == 0)
    {
        s.average = NAN;
        s.max = NAN;
        s.min = NAN;
    } else {
        s.average = sumarray / setlength;
        s.max = maximum;
        s.min = minimum;
    }

    return s;
}


//Raises alerts when max is greater than threshold
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats) {


    
    if(computedStats.max > maxThreshold)
    {

        if(alerters[0]){

            emailAlertCallCount = 1;

        }else{

            emailAlertCallCount = 2;
        }

         if(alerters[1]){

            ledAlertCallCount = 1;

        }else{
            
            ledAlertCallCount = 2;
        }

    } else {

        emailAlertCallCount = 0;
        ledAlertCallCount = 0;
    }

    return;
};