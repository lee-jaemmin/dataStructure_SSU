#include <iostream>
#include "Time.h"

//20212861 이재민 

using namespace std;

void Time::readTime(bool &errorFlag)
{
    enum AM_PM {AM, PM} AM_or_PM;
    int hour, minute;

    const char delimiter = ':';

    errorFlag = true;

    if(!(cin >> hour)) return;

    if (hour < 0 || hour > 12)
        return;
    char c;
    cin >> c;
    
    if (c != delimiter)
        return;
    if (!(cin >> minute)) // formatted input
        return;
    if (minute < 0 || minute > 59)
        return;
    cin >> c;
    if (c == 'A' || c == 'a')
        AM_or_PM = AM;
    else if (c == 'P' || c == 'p')
        AM_or_PM = PM;
    else
        return;
    cin >> c;
    if (c != 'M' && c != 'm')
        return;
    errorFlag = false; 
    
    if (hour == 12)
        minutes = minute;
    else
        minutes = hour*60 + minute;
    if (AM_or_PM == PM)
        minutes += 60*12;
}

int Time::subtractTimes(Time t)
{
    return minutes - t.minutes;
}


void Time::addTimes(Time t, int avgTime)
{
    int time = t.minutes + avgTime;
    int hour, minutes;

    hour = time / 60;
    minutes = time % 60;

    cout << "\nYour expected seen by doctor time is " << hour << ":" << minutes << endl;

}