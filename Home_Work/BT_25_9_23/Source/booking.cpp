#include "booking.h"

unsigned Room::getRoomNumber(){
    return roomNumber;
}

bool Room::isAvailable(){
    return isBooked&&isCleaned;
}

void Room::checkOut(){
    isBooked = false;
    isCleaned = false;
}

void Room::isClean(){
    this->isCleaned = true;
}




void displayBookingMenu(){
    std::cout<<"************  BOOKING MANAGEMENT  *************"<<std::endl;
    std::cout<<"***     1. Setting number of Room           ***"<<std::endl;
    std::cout<<"***     2. Update room status               ***"<<std::endl;
    std::cout<<"***     3. Make a reservation               ***"<<std::endl;
    std::cout<<"***     0. Exit                             ***"<<std::endl;
    std::cout<<"***********************************************"<<std::endl;
    std::cout<<"Please enter your choice : ";
}



void checkEmtyRoom(){


}

unsigned int errorNotification(unsigned int choice){
    while(!(0<=choice<=3)){
        std::cout<<"Invalid selection .Please re-enter your choice : "<<std::endl;
    }
    return choice;
}

void settingRoomNumber(){

}

void updateRoomStatus(){

}

void bookingRoom(){

}

void bookingManagement(){
    displayBookingMenu();
    unsigned int choice;
    std::cin>>choice;
    switch (choice)
    {
    case EXIT:
        return;
    case SETTING:
        settingRoomNumber();
    case UPDATETING:
        updateRoomStatus();
    case BOOKING:
        bookingRoom();    
    default:
        errorNotification(choice);
    }

}