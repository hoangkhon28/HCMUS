# include "Student.h"

Student::Student() {
    fullName = new char[100];
    id = new char[10];
    dateOfBirth = new char[30];
    marks[0] = marks[1] = marks[2] = 0.0;
}

Student::Student(const Student& s) {
    fullName = new char[100];
    id = new char[10];
    dateOfBirth = new char[30];

    strcpy(fullName, s.fullName);
    strcpy(id, s.id);
    strcpy(dateOfBirth, s.dateOfBirth);
    marks[0] = s.marks[0];
    marks[1] = s.marks[1];
    marks[2] = s.marks[2];
}

Student& Student::operator=(const Student& s) {
    if (this == &s) {
        return *this;
    }
    if (fullName != NULL) {
        delete fullName;
        fullName = new char[100];
        strcpy(fullName, s.fullName);  
    }
    if (id != NULL) {
        delete id;
        id = new char[10];
        strcpy(id, s.id);

    }
    if(dateOfBirth!=NULL) {
        delete dateOfBirth;
        dateOfBirth = new char[30];
        strcpy(dateOfBirth, s.dateOfBirth);
    }
    marks[0] = s.marks[0];
    marks[1] = s.marks[1];
    marks[2] = s.marks[2];

    return *this;
}

Student::~Student() {
    delete fullName;
    fullName = NULL;
    delete id;
    id = NULL;
    delete dateOfBirth;
    dateOfBirth = NULL;;
}

void Student::inputInfo() {
    cin.ignore();
    cout << "Nhap ho ten sinh vien: ";
    cin.getline(fullName, 100);
    cout << "Nhap ma so sinh vien: ";
    cin.getline(id, 10);
    cout << "Nhap ngay sinh sinh vien: ";
    cin.getline(dateOfBirth, 30);
    cout << "Nhap diem bai tap: ";
    cin >> marks[0];
    cout << "Nhap diem giua ky: ";
    cin >> marks[1];
    cout << "Nhap diem cuoi ky: ";
    cin >> marks[2];
}

double Student::getAvgMark() const {
    return marks[0] * 0.25 + marks[1] * 0.25 + marks[2] * 0.5;
}

const char* Student::getDateOfBirth() const {
    return dateOfBirth;
}

void Student::printInfo() const {
    cout << "Ho va ten: " << fullName << endl;
    cout << "Ma so sinh vien: " << id << endl;
    cout << "Ngay sinh: " << dateOfBirth << endl;
    cout << "Diem bai tap, giua ky, cuoi ky: " << marks[0] << " " << marks[1] << " " << marks[2] << endl;
    cout << "Diem trung binh: " << getAvgMark() << endl;
}

void Student::writeFile(ofstream& fileOut) const {
    fileOut << "Ho va ten: " << fullName << endl;
    fileOut << "Ma so sinh vien: " << id << endl;
    fileOut << "Ngay sinh: " << dateOfBirth << endl;
    fileOut << "Diem bai tap, giua ky, cuoi ky: " << marks[0] << " " << marks[1] << " " << marks[2] << endl;
    fileOut << "Diem trung binh: " << getAvgMark() << endl;
    fileOut << endl;
}

void Student::readFile(ifstream& fileIn) {
    // Hoang Linh, 21120485, 24/02/2003, 8, 8, 8
    fileIn.getline(fullName, 100, ',');
    fileIn.ignore();
    fileIn.getline(id, 10, ',');
    fileIn.ignore();
    fileIn.getline(dateOfBirth, 30, ',');
    fileIn.ignore();
    fileIn >> marks[0];
    fileIn.ignore();
    fileIn >> marks[1];
    fileIn.ignore();
    fileIn >> marks[2];
}

string Student::getRate() const {
    string rate;
    double avg = getAvgMark();
    if (avg >= 9) {
        rate = "Xuat sac";
    }
    else if (avg >= 8) {
        rate = "Gioi";
    }
    else if (avg >= 6.5) {
        rate = "Kha";
    }
    else if (avg >= 5) {
        rate = "Trung binh";
    }
    else {
        rate = "Yeu";
    }
    return rate;
}
