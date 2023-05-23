#ifndef NVSANXUAT_H
#define NVSANXUAT_H

#pragma warning(disable: 4996)
#pragma once

#include "NhanVien.h"

class NVSanXuat : public NhanVien {
private:
    int soSanPham;

public:
    NVSanXuat();
    NVSanXuat(char* _maNV, char* _hoTen, NgaySinh _ngaySinh, char* _diaChi, bool _gioiTinh, double _soSanPham);
    NVSanXuat(const NVSanXuat& nv);
    void nhap() override;
    void xuat() override;
    double tinhLuong() override;

    int getSoSanPham();
    void setSoSanPham(int _soSP);
};

#endif 