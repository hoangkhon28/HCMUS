#include "StudentList.h"

StudentList::StudentList() {
    list = NULL;
    size = 0;
}

StudentList::~StudentList() {
    delete[] list;
    list = NULL;
}

void StudentList::writeList(const char* fileName) const {
    ofstream fileOut(fileName);
    if (!fileOut.is_open()) {
        cout << "Khong mo duoc file de ghi!" << endl;
        return;
    }
    fileOut << "So luong sinh vien: " << size << endl;
    for (int i = 0; i < size; i++) {
        list[i].writeFile(fileOut);
    }
    fileOut.close();
    cout << "Da ghi danh sach sinh vien vao file." << endl;
}

void StudentList::readList(const char* fileName) {
    ifstream fileIn(fileName);
    if (!fileIn.is_open()) {
        cout << "Khong mo duoc file de doc!" << endl;
        return;
    }

    fileIn >> size;
    fileIn.ignore();

    list = new Student[size];

    for (int i = 0; i < size; i++) {
        list[i].readFile(fileIn);
        fileIn.ignore();
    }

    fileIn.close();
    cout << "Da doc thanh cong!" << endl;
}

void StudentList::inputList() {
    cout << "Nhap so luong sinh vien: ";
    cin >> size;
    list = new Student[size];

    for (int i = 0; i < size; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        list[i].inputInfo();
    }
}
void StudentList::printList() {
    for (int i = 0; i < size; i++) {
        cout << "\nSinh vien " << i + 1 << ": " << endl;
        list[i].printInfo();
    }
}

double StudentList::getSumList() const {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += list[i].getAvgMark();
    }
    return sum;
}

double StudentList::getAvgList() const {
    return getSumList() / size;
}

void StudentList::writeListLowerAvg(const char* fileName) const {
    ofstream fileOut(fileName);
    if (!fileOut.is_open()) {
        cout << "Khong mo duoc file de ghi!" << endl;
        return;
    }
    fileOut<<"Danh sach sinh vien co diem trung binh nho hon diem trung binh cua lop (" << getAvgList() << "):" << endl;
    for (int i = 0; i < size; i++) {
        if (list[i].getAvgMark() < getAvgList()) {
            list[i].writeFile(fileOut);
        }
    }

    fileOut.close();
    cout << "Ghi file thanh cong!" << endl;
}

void StudentList::addNewStudent() {
    Student newStudent;
    newStudent.inputInfo();

    Student* newList = new Student[size + 1];
    for (int i = 0; i < size; i++) {
        newList[i] = list[i];
    }
    newList[size] = newStudent;
    size++;

    delete[] list;
    list = newList;

    cout << "Da them sinh vien thanh cong. " << endl;
    // Ghi sinh vien moi them vao tap tin
    cin.ignore();
    cout << "Nhap ten file de them sinh vien vao: ";
    char* fileName = new char[50];
    cin.getline(fileName, 50);
    writeList(fileName);
}

void StudentList::studentWithSameBirthday() const {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    int currentDay = ltm->tm_mday;
    int currentMonth = ltm->tm_mon + 1;
    int currentYear = ltm->tm_year + 1900;

    bool found = false;
    for (int i = 0; i < size; i++) {
        const char* dob = list[i].getDateOfBirth();
        int day, month, year;
        sscanf(dob, "%d/%d/%d", &day, &month, &year);

        if (day == currentDay && month == currentMonth) {
            if (!found) {
                cout << "Danh sach sinh vien co cung ngay sinh nhat trong ngay hom nay: " << endl;
                found = true;
            }
            list[i].printInfo();
            cout << endl;
        }
    }
    if (!found) {
        cout << "Khong co sinh vien co cung ngay sinh nhat trong ngay hien tai.";
    }
}


void StudentList::printListWithGrade() const {
    for (int i = 0; i < size; i++) {
        cout << "\nSinh vien thu " << i + 1 << endl;
        list[i].printInfo();
        cout << "Xep loai: " << list[i].getRate() << endl;
    }
}