/**
  ******************************************************************************
  * @file    retaurant_management.h
  * @author  Phung Van Manh
  * @date    24-September-2023
  * @brief   Retaurant managerment embedded interview class assignment 22/9/2023
  ******************************************************************************
  */  

#ifndef __RESTAURANT_MANAGEMENT_H
#define __RESTAURANT_MANAGEMENT_H

#include <iostream>
#include <list>
#include <fstream>
#include <string>

typedef enum {
  EMTY,
  OCCUPIED
}status;

class dish {
  protected:
    std::string name;
    unsigned long price;
  public:
    dish(std::string namePassedIn, unsigned long pricePassedIn) : name(namePassedIn), price(pricePassedIn) {}
    void setName(std::string namePassedIn);
    std::string getName() const;
    void setPrice(unsigned long pricePassedIn);
    unsigned long getPrice() const;
};

class orderedDish : public dish{
  private:
    unsigned int orderQuantity;
  public:
    orderedDish(std::string namePassedIn, unsigned long pricePassedIn, unsigned int quantityPassedIn) : dish(namePassedIn, pricePassedIn), orderQuantity(quantityPassedIn) {}
    void setQuantity(unsigned int quantityPassedIn);
    unsigned int getQuantity();
};

struct table{
  int ID;
  status currentStatus;
  std::list<orderedDish> orderList;
};

void displayMainMenu();
void displayManagerMenu();
void displayStaffMenu();
#endif