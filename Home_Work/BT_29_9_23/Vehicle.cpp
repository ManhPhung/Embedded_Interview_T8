#include <iostream>
#include <vector>

struct position{
    int x, y;
};

class Dimensions{
    private : 
        float length;
        float width;
    public : 
        Dimensions(float _length, float _width)
        : length(_length), width(_width) {}
        float getLength();
        float getWidth();
};

float Dimensions::getLength(){ return length;}
float Dimensions::getWidth(){ return width;}

class Position{
    private:
        int x, y;
    public:
        Position(int _x = 0, int _y = 0)
        : x(_x), y(_y) {}
        void setX(int x);
        void setY(int y);
        int getX();
        int getY();
        bool opertor(Position otherPos);
        void displayPos();
};
void Position::setX(int x){ x = x;}
void Position::setY(int y){ y = y;}
int Position::getX(){return x;}
int Position::getY(){return y;}
bool Position::opertor(Position otherPos){
            return (x == otherPos.x && y == otherPos.y);
        }
void Position::displayPos() {
    std::cout << "(" << x << "," << y << ")";
}


/*
** Name of Class : ParkingSlot
** Properties : 
**      - dimOfSlot(Dimension of slots).
**      - isOccupited(status of Slots : Emty(flase) or Occupied(true)).
** Methods : 
**      - setSlotStatus : set the stutus of the slot (isOccupied).
**      - getDimOfSlot : returns the dimension of the slot.
**      - getSlotStatus : returns the state of the Slot.
**      - displayDimOfSlot : display to screen the dimension of the slot.
**/
class ParkingSlot{
    private:
        Dimensions dimOfSlot;
        bool isOccupied;
    public:
        ParkingSlot(float _length, float _width)
        : dimOfSlot(_length, _width), isOccupied(false){}
        void setSlotStatus(bool status);
        Dimensions getDimOfSlot();
        bool getSlotStatus();
        void displayDimOfSlot();
};

void ParkingSlot::setSlotStatus(bool status) { isOccupied = status;}
Dimensions ParkingSlot::getDimOfSlot() {return dimOfSlot;}
bool ParkingSlot::getSlotStatus() {return isOccupied;}
void ParkingSlot::displayDimOfSlot(){
    std::cout << "Dimension of slot: " << dimOfSlot.getLength() << " x " << dimOfSlot.getWidth() << std::endl;
}

/*  
** Name of Class : Car
** Properties : liscensePlate(liscense plate of car), DimOfCar(Dimension of Car)
** Methods : 
**      - getLicensePlate : Returns the license plate of the car.
**      - getDimOfCar : Returns the dimension of the car.
**      - findParkingSlot : Finding emty spots in the parking lot.
**      - isCanParking : Returns search results for the available parking spot.
**/
class Car{
    private:
        std::string licensePlate;
        Dimensions dimOfCar;
    public:
        Car(std::string _licensePlate, float _length, float _width)
        : licensePlate(_licensePlate), dimOfCar(_length, _width){}
        std::string getLicensePlate();
        Dimensions getDimOfCar();
        Position findParkingSlot(std::vector<std::vector<ParkingSlot>> slots);
        void isCanParking(ParkingSlot slots);
        void displayDimOfCar();
};

std::string Car::getLicensePlate(){return licensePlate;}
Dimensions Car::getDimOfCar(){return dimOfCar;}
Position Car::findParkingSlot(std::vector<std::vector<ParkingSlot>> slots){
    for (int i = 0; i < slots.size(); i++) {
        for (int j = 0; j < slots[i].size(); j++) {
            if (slots[i][j].getDimOfSlot().getLength() > dimOfCar.getLength() && slots[i][j].getDimOfSlot().getWidth() > dimOfCar.getWidth()) {
                Position pos(i, j);
                std::cout <<"*************************************************" << std::endl;
                std::cout << "Found one available slot matches with dimension of your car" << std::endl;
                slots[i][j].displayDimOfSlot();
                std::cout << "Position: "; pos.displayPos(); std::cout << "\n";
                std::cout <<"*************************************************" << std::endl;
                return pos;
            }
        }
    }
    std::cout << "Not found available slots for dimension of your car." << std::endl;
    Position pos;
    return pos;
}

void Car::isCanParking(ParkingSlot slots) {
    if (slots.getSlotStatus()) std::cout << "- Can't park in this slot." << std::endl;
    else std::cout << "- Can park in this slot." << std::endl;
}
void Car::displayDimOfCar() {
    std::cout << "dimension of car are : " << "[" << dimOfCar.getLength() << " x " << dimOfCar.getWidth() << "]" << std::endl;

}

/*  
** Name of Class : NavigateSystem
** Properties : parkingMap(map of parking lot), currentPos(current position of the car) 
** Methods : 
**      - calculateRoute : Returns route length in Km units .
**      - guideMovement : return movement guide
**      - setCurrentPos : set the current Position of the car
**      - getCurrentPos : get the current Position of the car
**/

class NavigateSystem{
    private:
        std::vector<std::vector<ParkingSlot>> parkingMap;
        Position currentPos;
    public:
        NavigateSystem(std::vector<std::vector<ParkingSlot>> _parkingMap, Position _currentPos)
        : parkingMap(_parkingMap), currentPos(_currentPos) {}
        void calculateRoute(Position targetPos);
        void guideMovement(Position targetPos);
        void setCurrentPos(Position pos);
        Position getCurrentPos();
};

void NavigateSystem::calculateRoute(Position targetPos){}
void NavigateSystem::guideMovement(Position targetPos) {}
void NavigateSystem::setCurrentPos(Position pos) {currentPos = pos;}
Position NavigateSystem::getCurrentPos() {return currentPos;}



int main(){
        std::vector<std::vector<ParkingSlot>> slots = {
        {
            ParkingSlot(4.5, 2.0), ParkingSlot(4.5, 2.0), ParkingSlot(4.5, 2.0)
        },
        {
            ParkingSlot(4, 1.7), ParkingSlot(4, 1.7), ParkingSlot(4, 1.7)
        },
        {
            ParkingSlot(5, 2.5), ParkingSlot(5, 2.5), ParkingSlot(5, 2.5)
        }
    };

    Car newCar("adasdre", 4.5, 1.9);
    std::cout <<"*************************************************" << std::endl;
    std::cout << " The car has a license plate is : " << newCar.getLicensePlate() ;        
    std::cout << " and ";
    newCar.displayDimOfCar();
    std::cout <<"\n*************************************************" << std::endl;

    Position emtySlot;
    emtySlot = newCar.findParkingSlot(slots);
    return 0;

}