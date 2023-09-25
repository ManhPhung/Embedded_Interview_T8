/**
  ******************************************************************************
  * @file    restaurant_management.c
  * @author  Phung Van Manh
  * @date    24-September-2023
  * @brief   Retaurant managerment embedded interview class assignment 22/9/2023
  ******************************************************************************
  */
#include "restaurant_management.h"

void displayMainMenu(){
  std::cout << "------Restaurant Management------\n";
  std::cout << "1. Manager.\n" << "2. Staff.\n"<<"0: Exit\n";
  std::cout << "Please enter your choice : ";
}

void displayManagerMenu(){
  std::cout << "-------Manager-------\n";
  std::cout << "1. Set the Table Number.\n";
  std::cout << "2. Add a dish to the menu.\n";
  std::cout << "3. Edit a dish from the menu.\n";
  std::cout << "4. Remove a dish from the menu.\n";
  std::cout << "5. Display the Menu.\n";
  std::cout << "0. Back to Restaurant Management page.\n";
  std::cout << "Please enter your choice : ";
}


void displayStaffMenu(){
  std::cout<<"1: Oder\n"<<"2: Remove\n"<<"3: Displays a list of ordered dishes\n"<<"4: Pay\n"<<"0: Back\n";
  std::cout << "Enter your choice: ";
}

void dish::setName(std::string namePassedIn){
  this->name = namePassedIn;
}

std::string dish::getName() const{
  return name;
}

void dish::setPrice(unsigned long pricePassedIn){
  this->price = pricePassedIn;
}

unsigned long dish::getPrice() const{
  return price; 
}

void orderedDish::setQuantity(unsigned int quantityPassedIn){
  this->orderQuantity = quantityPassedIn;
}

unsigned int orderedDish::getQuantity(){
  return orderQuantity;
}