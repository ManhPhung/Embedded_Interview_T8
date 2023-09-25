#include "manage.h"

Student::Student(std::string nameInput, int ageInput, typeOfGender genderInput, double scoreInMathInput,double scoreInPhysicsInput, double scoreInEnglishInput){
    static int id = 1000;
    ID = id; 
    id++;
    name = nameInput;
    age = ageInput;
    gender = genderInput;
    scoreInMath = scoreInMathInput;
    scoreInPhysics = scoreInPhysicsInput;
    scoreInEnglish = scoreInEnglishInput;
}

int Student::ID = 1000;

void Student::setName(std::string name){
    Student::name = name;
}

void Student::setAge(int age){
    Student::age = age;
}

void Student::setGender(typeOfGender gender){
    Student::gender = gender;
}

void Student::setMathScore(double scoreInMath){
    Student::scoreInMath = scoreInMath;
}

void Student::setPhysicScore(double scoreInPhysics){
    Student::scoreInPhysics = scoreInPhysics;
}

void Student::setEnglishScore(double scoreInEnglish){
    Student::scoreInEnglish = scoreInEnglish;
}

std::string Student::getName(){
    return Student::name;
}

int Student::getAge(){
    return Student::age;
}

std::string Student::getGender(){
    switch (Student::gender)
    {
    case MALE:
        return "MALE";
    case FEMALE:
        return "FEMALE";
    case OTHER:
        return "OTHER";
    }
}

double Student::getScoreInMath(){
    return Student::scoreInMath;
}

double Student::getScoreInPhysics(){
    return Student::scoreInPhysics;
}
double Student::getScoreInEnglish(){
    return Student::scoreInEnglish;
}

void displayMenu(){
    std::cout<<"-----Student Management Menu-----\n";
    std::cout<<"1. Add Student\n";
    std::cout<<"2. Delete Student\n";
    std::cout<<"3. Search Student by Name\n";
    std::cout<<"4. Exit\n";
    std::cout<<"Enter your choise : ";

}

void addStudent(){

    

}

void deleteStudent(){

}

void searchStuden(){
    // std::string searchName;
    // std::cout << "Enter student name to search: ";
    // std::cin.ignore();
    // std::getline(std::cin, searchName);

    // bool found = false;
    // for (const Student& student : studentList) {
    //     if (student.getName() == searchName) {
    //         cout << "Student found - ";
    //         student.display();
    //         found = true;
    //         break;
    //     }
    // }

    // if (!found) {
    //     std::cout << "Student not found." << std::endl;
    // }
}
