#include "lab3.h"


int main(){
    int quantity_of_workers;

    quantity_of_workers = quan_of_workers();
    Worker *workers = new Worker[quantity_of_workers];

    create_workers(workers, quantity_of_workers);
    display_workers(workers, quantity_of_workers);
    find_max_date(workers, quantity_of_workers);

    return 0;

}