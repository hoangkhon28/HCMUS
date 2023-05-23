#include "NVSanXuat.h"

NVSanXuat::NVSanXuat() : NhanVien() {
    soSanPham = 0;
}

NVSanXuat::NVSanXuat(char* _maNV, char* _hoTen, NgaySinh _ngaySinh, char* _diaChi, bool _gioiTinh, double _soSanPham)
    : NhanVien(_maNV, _hoTen, _ngaySinh, _diaChi, _gioiTinh) {
    soSanPham = _soSanPham;
}

NVSanXuat::NVSanXuat(const NVSanXuat& nv) : NhanVien(nv) {
    soSanPham = nv.soSanPham;
}

void NVSanXuat::nhap() {
    NhanVien::nhap();
    do {
        cout << "Nhap so san pham: ";
        cin >> soSanPham;
        if (soSanPham < 10 || soSanPham > 15) {
            cout << "So san pham phai tu 10 den 15 san pham!" << endl;
        }
    } while (soSanPham < 10 || soSanPham > 15);
}

void NVSanXuat::xuat() {
    NhanVien::xuat();
    cout << "So san pham: " << soSanPham << endl;
    cout << "Luong: " << fixed <<setprecision(0) << tinhLuong() << endl;
} 

double NVSanXuat::tinhLuong() {
    return soSanPham * 50000;
}

int NVSanXuat::getSoSanPham() {
    return soSanPham;
}

void NVSanXuat::setSoSanPham(int soSP) {
    soSanPham = soSP;
}