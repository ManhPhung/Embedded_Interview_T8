#ifndef _BOOKING_H_
#define _BOOKING_H_

#include <iostream>
#include <map>
#include <vector>

std::vector<Room> roomList;

enum {
    EXIT,
    SETTING,
    UPDATETING,
    BOOKING
};

class Room{
    private: 
        unsigned int roomNumber;
        bool isBooked;
        bool isCleaned;
    public:
        Room(unsigned int _roomNumber) : roomNumber(_roomNumber) {}
        unsigned int getRoomNumber();
        bool isAvailable();
        void bookingRoom();
        void checkOut();
        void isClean();
};


void displayBookingMenu();
void bookingManagement();


#endif