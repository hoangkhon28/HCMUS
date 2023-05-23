#include "NVCongNhat.h"

NVCongNhat::NVCongNhat() : NhanVien() {
    soNgayLam = 0;
}

NVCongNhat::NVCongNhat(char* _maNV, char* _hoTen, NgaySinh _ngaySinh, char* _diaChi, bool _gioiTinh, double _soNgayLam)
    : NhanVien(_maNV, _hoTen, _ngaySinh, _diaChi, _gioiTinh) {
}

NVCongNhat::NVCongNhat(const NVCongNhat& nv) : NhanVien(nv) {
    soNgayLam = nv.soNgayLam;
}

void NVCongNhat::nhap() {
    NhanVien::nhap();
    do {
        cout << "Nhap so ngay lam: ";
        cin >> soNgayLam;
        if (soNgayLam < 22 || soNgayLam > 26) {
            cout << "So ngay lam phai tu 22 den 26 ngay!" << endl;
        }
    } while (soNgayLam < 22 || soNgayLam > 26);
}

void NVCongNhat::xuat() {
    NhanVien::xuat();
    cout << "So ngay lam: " << soNgayLam << endl;
    cout << "Luong: " << fixed << setprecision(0) << tinhLuong() << endl;
}


double NVCongNhat::tinhLuong() {
    return soNgayLam * 500000;
}

double NVCongNhat::getSoNgayLam() {
    return soNgayLam;
}

void NVCongNhat::setSoNgayLam(double soNgay) {
    soNgayLam = soNgay;
}