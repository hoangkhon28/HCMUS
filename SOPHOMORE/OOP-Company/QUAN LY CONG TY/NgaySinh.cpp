#include "NgaySinh.h"

NgaySinh::NgaySinh() {
    ngay = thang = nam = 0;
}

int NgaySinh::getNgay() const {
    return ngay;
}

int NgaySinh::getThang() const {
    return thang;
}

int NgaySinh::getNam() const {
    return nam;
}

void NgaySinh::setNgay(int _ngay) {
    ngay = _ngay;
}
void NgaySinh::setThang(int _thang) {
    thang = _thang;
}
void NgaySinh::setNam(int _nam) {
    nam = _nam;
}

void NgaySinh::nhapNS() {
    cout << "Nhap ngay sinh (ngay thang nam): ";
    cin >> ngay >> thang >> nam;
}

void NgaySinh::xuatNS() {
    cout << "Ngay sinh: " << ngay << "/" << thang << "/" << nam << endl;
}

int NgaySinh::tinhTuoi() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int tuoi = ltm->tm_year + 1900 - nam;
    if (ltm->tm_mon + 1 < thang || (ltm->tm_mon + 1 == thang && ltm->tm_mday < ngay)) {
        tuoi--;
    }
    return tuoi;
}