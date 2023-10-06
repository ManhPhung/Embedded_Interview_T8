#include "booking.h"



void displayMenu(){
    std::cout<<"******************  WELCOME  ******************"<<std::endl;
    std::cout<<"***     1. Booking                          ***"<<std::endl;
    std::cout<<"***     2. Customer Management              ***"<<std::endl;
    std::cout<<"***     3. Employee Manager                 ***"<<std::endl;
    std::cout<<"***     4. Payment                          ***"<<std::endl;
    std::cout<<"***     5. Security and Access              ***"<<std::endl;
    std::cout<<"***     6. Reporting and Statistic          ***"<<std::endl;
    std::cout<<"***     7. Manage feedback and Evaluation   ***"<<std::endl;
    std::cout<<"***********************************************"<<std::endl;
    std::cout<<"Please enter your choice : ";
}

extern unsigned int checkSelection(unsigned totalOption){
    unsigned int choice; 
    while(1){
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cout <<"Invalid selection. Please re-enter your choice : ";
            std::cin.clear();
            std::cin.ignore(200,'\n');
        }
        if (choice >= 1 && choice <= totalOption)     break;
        else{
            std::cout <<"Invalid selection. Please re-enter your choice : ";
            std::cin.clear();
            std::cin.ignore(2,'\n');
        }
    }
    return choice;
}

int main(){

    displayMenu();
    switch (checkSelection(7))
    {
    case 1:
        bookingManagement();
        break;
    case 2:
        /*
        .
        .
        .
        */
       break;
    case 3:
        /*
        .
        .
        .
        */
       break;
    default:
        break;
    }

    
    return 0;
}