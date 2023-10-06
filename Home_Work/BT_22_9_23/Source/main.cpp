#include <limits>
#include "restaurant_management.h"

std::list<dish> menu;

/*
Function Name: displayMenu
Input: Menu address
Output: List of dishes included in the menu
Description: The program prints out a list of dishes on the menu
*/
void displayMenu(const std::list<dish>& menu) {
    int index = 1;
    std::cout << "-------------Menu------------\n";
    for (const dish& d : menu) {
        std::cout << index << ". " << " Name : " << d.getName() << " - Price : " << d.getPrice() << " dong.\n";
        index++;
    }
    std::cout << "-----------------------------\n";
}


int main() {
    while (true) {
        restaurant_management:
        displayMainMenu();
        int choice;
        std::cin >> choice;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please re-enter selection: " << std::endl;
        }
        else if(choice>=0&&choice<=2)
        {
            switch (choice) {
            case 1:
                int managerChoice;
                while (true) {
                    displayManagerMenu();
                    std::cin >> managerChoice;

                    if(std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input. Please re-enter selection: " << std::endl;
                    }

                    else if(choice>=0&&choice<=5)
                    {
                        switch (managerChoice) {
                        case 1:
                            
                            break;

                        case 2:
                        {
                            bool continueAdding = true;
                            while (continueAdding) {
                                std::string name;
                                std::cout << "Please enter the Dish name : ";
                                std::cin.ignore();
                                getline(std::cin, name);
                                std::cout << "Please enter the Dish price : ";
                                unsigned long price;
                                std::cin >> price;
                                dish newDish(name, price);
                                menu.push_back(newDish);
                                std::cout << "Adding dishes to the menu was successful!!!\n";
                                std::cout << "Do you want to continue adding dishes to the menu?\n";
                                std::cout << "1. Yes\n" << "2. No\n";
                                std::cout << "Please enter your choice : ";
                                int conOption;
                                std::cin >> conOption;
                                if (conOption != 1) {
                                    displayMenu(menu);
                                    continueAdding = false;
                                }
                            }
                            break;
                        }

                        case 3: 
                        {
                            bool continueEditing = true;
                            while (continueEditing) {
                                size_t editID;
                                std::cout << "Enter the ID (index) of the dish you want to edit: ";
                                std::cin >> editID;
                                if (editID >= 1 && editID <= menu.size()) {
                                    auto it = std::next(menu.begin(), editID - 1);

                                    std::cout << "Current name: " << it->getName() << " - Current price: " << it->getPrice() << " dong.\n";
                                    std::cout << "Enter the new name for the dish: ";
                                    std::string newName;
                                    std::cin.ignore();
                                    getline(std::cin, newName);
                                    while (newName.empty()) {
                                        std::cout << "Invalid input. Please enter a non-empty string: ";
                                        getline(std::cin, newName);
                                    }
                                    it->setName(newName);

                                    std::cout << "Enter the new price for the dish: ";
                                    unsigned long newPrice;
                                    std::cin >> newPrice;
                                    it->setPrice(newPrice);

                                    std::cout << "Dish with ID " << editID << " has been updated.\n";
                                    displayMenu(menu);
                                    std::cout << "Do you want to continue editing dishes from the menu?\n";
                                    std::cout << "1. Yes\n" << "2. No\n";
                                    std::cout << "Please enter your choice : ";
                                    int conOption;
                                    std::cin >> conOption;
                                    if (conOption != 1) {
                                        displayMenu(menu);
                                        continueEditing = false;
                                    }
                                } else {
                                    std::cout << "Invalid ID. Please enter a valid ID.\n";
                                }
                            }
                            break;
                        }

                        case 4:
                        {
                            bool continueRemoving = true;
                            while (continueRemoving) {
                                size_t removeID;
                                displayMenu(menu);
                                std::cout << "Enter the ID (index) of the dish you want to remove: ";
                                std::cin >> removeID;
                                if (removeID >= 1 && removeID <= menu.size()) {
                                    auto it = std::next(menu.begin(), removeID - 1);
                                    menu.erase(it);
                                    std::cout << "Dish with ID " << removeID << " has been removed.\n";
                                    displayMenu(menu);
                                    std::cout << "Do you want to continue removing dishes from the menu?\n";
                                    std::cout << "1. Yes\n" << "2. No\n";
                                    std::cout << "Please enter your choice : ";
                                    int conOption;
                                    std::cin >> conOption;
                                    if (conOption != 1) {
                                        displayMenu(menu);
                                        continueRemoving = false;
                                    }
                                } else {
                                    std::cout << "Invalid ID. Please enter a valid ID.\n";
                                }
                            }
                            break;
                        }

                        case 5:
                            displayMenu(menu);
                            break;
                        case 0:
                            goto restaurant_management;
                        }
                    }
                    else
                    {
                        std::cout << "Invalid input. Please re-enter selection: " << std::endl;
                    }
                }
            case 2:
                int staffChoice;
                while (true) {
                    displayStaffMenu();
                    std::cin >> staffChoice;

                    switch (staffChoice) {
                    case 1:
                        /* code */
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 0:
                std::cout << "--------Exit programming--------\n";
                return 0;
            } 
        } 
        else
        {
            std::cout << "Invalid input. Please re-enter selection: " << std::endl;
        } 
    }
    return 0;
}
