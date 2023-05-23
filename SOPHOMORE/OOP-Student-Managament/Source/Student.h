#pragma once
#pragma warning(disable : 4996)

#include<iostream>
#include <cstring>
#include <fstream>
#include <ctime>

using namespace std;
class Student{
    private:
    char* fullName;
    char* id;
    char* dateOfBirth;
    double marks[3];

public:
    Student();
    Student(const Student& s);
    ~Student(); 
    //------------------------
    void inputInfo();
    double getAvgMark() const;
    void printInfo() const;
    void writeFile(ofstream& fileOut) const;
    void readFile(ifstream& fileIn);
    string getRate() const;
    Student& operator=(const Student& s);
    const char* getDateOfBirth() const;
};


void menu();