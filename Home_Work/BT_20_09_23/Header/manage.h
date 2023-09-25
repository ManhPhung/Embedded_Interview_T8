#ifndef _MANAGE_H_
#define _MANAGE_H_

#include<iostream>
#include<string>

typedef enum{
    MALE = 1,
    FEMALE,
    OTHER
}typeOfGender;

typedef enum{
    EXCELLENT,
    GOOD,
    RATHER,
    MEDIUM,
    WEAK
}typeOfAcademicAbility;

class Student{
    private:
        static int ID;
        std::string name;
        int age;
        typeOfGender gender;
        double scoreInMath;
        double scoreInPhysics;
        double scoreInEnglish;
    public:
        Student(std::string nameInput, int ageInput, typeOfGender gender, double scoreInMathInput,double scoreInPhysicsInput, double scoreInEnglishInput);
        void setName(std::string name);
        void setAge(int age);
        void setGender(typeOfGender gender);
        void setMathScore(double scoreInMath);
        void setPhysicScore(double scoreInPhysics);
        void setEnglishScore(double scoreInEnglish);
        std::string getName();
        int getAge();
        std::string getGender();
        double getScoreInMath();
        double getScoreInPhysics();
        double getScoreInEnglish();
};

void displayMenu();
void addStudent();
void deleteStudent();
void searchStudent();

#endif