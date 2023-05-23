#ifndef NGAYSINH_H
#define NGAYSINH_H

#pragma warning(disable: 4996)
#pragma once

#include<iostream>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

class NgaySinh {
private:
    int ngay, thang, nam;

public:
    NgaySinh();
    int getNgay() const;
    int getThang() const;
    int getNam() const;
    void setNgay(int _ngay);
    void setThang(int _thang);
    void setNam(int _nam);
    void nhapNS();
    void xuatNS();
    int tinhTuoi();
};
#endif