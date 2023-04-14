#include "lab3.h"

int quan_of_workers(){
    int quan;
    cout<<"===========================================\n"<<endl;
    cout<<"Enter the quantity of workers: ";
    cin>>quan;

    return quan;
}




void create_workers(Worker *workers, int quantity){
    string name, num_line;
    int num, day, year, month;
    bool check = true;


    cin.ignore();
    for(int i = 0; i < quantity; i++){
        cout<<"Enter the name of "<<i + 1<<" worker: ";
        workers[i].setName();
        cout<<"Name --> "<<workers[i].getName()<<endl;
       
       do{
        cout<<"Enter the date of employing (dd.mm.yyyy): ";
        enter_date(day, month, year);
        check = day_validate(day, month, year);
        if(check == false) cout<<"Wrond date, please, try again: "<<endl;
       }while(!check);

        workers[i].setDay(day);
        workers[i].setMonth(month);
        workers[i].setYear(year);

        workers[i].getDay();
        workers[i].getMonth();
        workers[i].getYear();
    }


}





void display_workers(Worker *workers, int quantity){
    cout<<"\n\t================The list of workers================"<<endl;
    for(int i = 0; i < quantity; i++) {
        workers[i].getAll();
        cout<<endl;
    }
}







void find_max_date(Worker *workers, int quantity){
    time_t max = workers[0].getTime(), curr = 0, picked {0}, difference{0};
    int indexes[quantity] , day { 0 } , month {0}, year {0}, experience {0}, quan_of_indexes {0};
    bool check = true;
    tm *picked_date = localtime(&max);
    indexes[quan_of_indexes] = 0;

    for(int i = 1; i < quantity; i++){
        curr = workers[i].getTime();
        if(curr < max){
            quan_of_indexes = 0;
            max = curr;
            indexes[quan_of_indexes] = i;
        }
        else if(curr == max){
            quan_of_indexes++;
            indexes[quan_of_indexes] = i;

        }
    }

    do{
        cout<<"Enter the date for determining the worker with the longest experience (dd.mm.yyyy): ";
        enter_date(day, month, year);
        check = day_validate(day, month, year);
        if(check == false) cout<<"Wrong date, please, try again: "<<endl;
    }while(!check);




    cout<<"\n\nPicked date --> "<<day<<"."<<month<<"."<<year<<endl;
    picked_date ->tm_year = year - 1900;
    picked_date ->tm_mon = month - 1;
    picked_date ->tm_mday = day;
    picked = mktime(picked_date);
    if(picked < max) cout<<"\nNobody haven't worked yet...";
    else {
        difference = (picked - max) / (60*60*24*365);
        if(quan_of_indexes == 0){
        cout<<"Employee with the longest experience"; difference > 1 ? cout<<"("<<difference<<" years)" : cout<<"(less than 1 year)";
        cout<<" --> "<<workers[indexes[quan_of_indexes]].getName()<<endl;
        }

        else{
        cout<<"Employees with the longest experience ";
        difference > 1 ? cout<<"("<<difference<<" years) :"<<endl : cout<<"(less than 1 year) :"<<endl;
        for(int i = 0; i <= quan_of_indexes; i++) cout<<i + 1<<" --> "<<workers[indexes[i]].getName()<<endl;
    } 
    }  
    getchar();
}





bool day_validate(int day, int month, int year){
    bool check = true;
    time_t curr_time = time(NULL);
    tm *current_date = localtime(&curr_time);


    if(day > 31 || day < 1 || month > 12 || month < 1 || year < 1970 || year > current_date->tm_year + 1900) {
        check = false;
        }
    else if((month == 4 || month == 6 || month == 9 || month == 11 || month == 2) && day == 31 || day >= 30 && month == 2) check = false;

    return check;
}

void enter_date(int &day, int &month, int &year){
    bool check = true;
    string num_line;

        getline(cin, num_line, '.');
        day = stoi(num_line);
        getline(cin, num_line, '.');
        month = stoi(num_line);
        getline(cin, num_line);
        year = stoi(num_line);
        cout<<"\nDay - "<<day<<" Month - "<<month<<" Year - "<<year<<endl;
}





string Worker::getName(){ return name;}
void Worker::getYear() {cout<<"Year --> "<<date_of_employing.tm_year<<endl;}
void Worker::getDay(){ cout<<"Day --> "<<date_of_employing.tm_mday<<endl;}
void Worker::getMonth(){ cout<<"Month --> "<<date_of_employing.tm_mon<<endl;}


void Worker::setName(){
    string enter_name;
    getline(cin, name);}



void Worker::setDay(int day) {
    date_of_employing.tm_mday = day;
}


void Worker::setMonth(int month) {
    date_of_employing.tm_mon = month;
    }

    
void Worker::setYear(int year) {
    date_of_employing.tm_year = year;
    }



void Worker::getAll(){
    cout<<"Name --> "<<name<<endl;
    cout<<"Date of employing: "; 
    date_of_employing.tm_mday > 9? cout<<date_of_employing.tm_mday : cout<<"0"<<date_of_employing.tm_mday; cout<<".";
    date_of_employing.tm_mon > 9? cout<<date_of_employing.tm_mon : cout<<"0"<<date_of_employing.tm_mon; cout<<".";
    cout<<date_of_employing.tm_year<<endl;
}

time_t Worker::getTime(){
    date_of_employing.tm_year -= 1900;
    date_of_employing.tm_mon -= 1;
    return mktime(&date_of_employing);
}