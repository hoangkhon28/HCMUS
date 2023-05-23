#ifndef NVCONGNHAT_H
#define NVCONGNHAT_H

#pragma warning(disable: 4996)
#pragma once

#include "NhanVien.h"

class NVCongNhat : public NhanVien {
private:
    double soNgayLam;

public:
    NVCongNhat();
    NVCongNhat(char* _maNV, char* _hoTen, NgaySinh _ngaySinh, char* _diaChi, bool _gioiTinh, double _soNgayLam);
    NVCongNhat(const NVCongNhat& nv);
    void nhap() override;
    void xuat() override;
    double tinhLuong() override;

    double getSoNgayLam();
    void setSoNgayLam(double soNgay);

};

#endif 