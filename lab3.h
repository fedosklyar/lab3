#include<iostream>
#include<string>
#include<time.h>
#include<string.h>

using namespace std;



class Worker{
    string name;
    tm date_of_employing { 0 };
public:
    string getName();
    void getDay();
    void getMonth();
    void getYear();
    void getAll();
    void setName();
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    time_t getTime();
};

int quan_of_workers();
void create_workers(Worker *workers, int quantity);
void display_workers(Worker *workers, int quantity);
bool day_validate(int day, int month, int year);
void enter_date(int &day, int &month, int &year);
void find_max_date(Worker *workers, int quantity);