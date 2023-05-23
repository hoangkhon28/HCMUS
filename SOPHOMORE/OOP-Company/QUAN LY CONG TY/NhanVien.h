#ifndef NHANVIEN_H
#define NHANVIEN_H

#pragma warning(disable: 4996)
#pragma once

#include "NgaySinh.h"

class NhanVien {
protected:
    char* maNV;
    char* hoTen;
    NgaySinh ngaySinh;
    char* diaChi;
    bool gioiTinh;

public:
    NhanVien();
    NhanVien(char* _maNV, char* _hoTen, NgaySinh _ngaySinh, char* _diaChi, bool _gioiTinh);
    NhanVien(const NhanVien& nv);
    ~NhanVien();
    virtual void nhap();
    virtual void xuat();
    virtual double tinhLuong();

    void ghiNhanVien(ofstream& ofs) const;
    void docNhanVien(ifstream& ifs);
    char* getMaNV();
    char* getHoTen();
    NgaySinh getNgaySinh();
};

#endif