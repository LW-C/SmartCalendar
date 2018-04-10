//
// Created by lauren on 3/22/2018.
//

#ifndef SMARTCALENDAR_SMARTCALENDAR_H
#define SMARTCALENDAR_SMARTCALENDAR_H

#endif //SMARTCALENDAR_SMARTCALENDAR_H

using namespace std;

class Event {
protected:
    string title;
    string description;
    string location;
    int startTime[2];
    int endTime[2];
    int date[3];
    int eventType;
    Event * nextEvent;
    bool isFree;
public:
    Event();
    Event(bool f);
    string getTitle();
    void setTitle(string t);
    string getDescription();
    void setDescription(string d);
    string getLocation();
    void setLocation(string l);
    int getStartHour();
    int getStartMinute();
    void setStartTime(int hour, int minute);
    int getEndHour();
    int getEndMinute();
    void setEndTime(int hour, int minute);
    int getMonth();
    int getDay();
    int getYear();
    void setDate(int d[3]);
    int getEventType();
    void setEventType(int e);
    void printEvent();
    bool getIsFree();
    void setIsFree(bool f);
};

class RepeatingEvent: public Event
{
private:
    int dayOfWeek;
    int startDate[3];   //The first occurrence of the event
    int endDate[3];     //The last occurrence of the event
public:
    RepeatingEvent();
    int getDayOfWeek();
    void setDayOfWeek(int dw);
    int getStartMonth();
    int getStartDay();
    int getStartYear();
    void setStartDate(int d[3]);
    int getEndMonth();
    int getEndDay();
    int getEndYear();
    void setEndDate(int d[3]);
};

class Day
{
private:
    Event * startOfDay;      // Head of linked list
    int dayOfWeek;
    int date[2];
public:
    Day(int m, int d);
    void insertEvent(); //still needs to be implemented
    bool checkConflicts(int start[2], int end[2]);

};


class Year
{
private:
    int year;
    Day days[365];
public:
    Year(int y);
    Day* getDays();
};

class Calendar
{
private:
    vector<Year> years;
public:
    Calendar();
    void addEvent(); //still needs to be implmented
    Year* getYears();
    void addYear(int y);

};