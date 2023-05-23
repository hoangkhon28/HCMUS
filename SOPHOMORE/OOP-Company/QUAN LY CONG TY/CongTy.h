#ifndef CONGTY_H
#define CONGTY_H

#pragma warning(disable: 4996)
#pragma once

#include "NVSanXuat.h"
#include "NVCongNhat.h"

class CongTy {
private:
	NhanVien** dsnv;
	int soNV;

public:
	CongTy(int _soNV = 0);
	CongTy(const CongTy& ct);
	~CongTy();
	CongTy& operator=(const CongTy& ct);
	void nhapDSNV();
	void xuatDSNV();
	void ghiDSNhanVienVaoFile(const char* fileName);
	void docDSNhanVienTuFile(const char* fileName);
	double tinhTongLuong();
	NhanVien* timNhanVienLuongCaoNhat();
	double tinhLuongTrungBinh();
	void timNhanVienTheoMa();
	void timNhanVienTheoTen();
	void demSoNhanVienSinhThang5();
	void themNhanVien();
	void xoaNhanVien();
	void ghiDSNVLuongNhoHonTrungBinh(const char* filename);
};

#endif 