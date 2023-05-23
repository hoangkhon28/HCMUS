#include "Student.h"

class StudentList {
private:
    Student* list;
    int size;
public:
    StudentList();
    ~StudentList();
//-----------------
    void inputList();
    void printList();
    void writeList(const char* fileName) const;
    void readList(const char* fileName);
    double getAvgList() const;
    double getSumList() const;
    void writeListLowerAvg(const char* fileName) const;
    void addNewStudent();

    void studentWithSameBirthday() const;
    void printListWithGrade() const;

};

