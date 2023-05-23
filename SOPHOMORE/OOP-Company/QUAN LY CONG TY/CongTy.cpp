#include "CongTy.h"


CongTy::CongTy(int _soNV) {
	dsnv = new NhanVien * [_soNV];
	soNV = 0;
}

CongTy::CongTy(const CongTy& ct) {
	soNV = ct.soNV;
	dsnv = new NhanVien * [ct.soNV];
	for (int i = 0; i < soNV; i++) {
		dsnv[i] = new NhanVien(*ct.dsnv[i]);
	}
}

CongTy::~CongTy() {
	for (int i = 0; i < soNV; i++) {
		delete dsnv[i];
	}
	delete dsnv;
}

CongTy& CongTy::operator=(const CongTy& ct) {
	if (this != &ct) {
		// giải phóng bộ nhớ của đối tượng gốc
		for (int i = 0; i < soNV; i++) {
			delete dsnv[i];
		}
		delete[] dsnv;

		// gán lại
		soNV = ct.soNV;
		dsnv = new NhanVien * [soNV];
		for (int i = 0; i < soNV; i++) {
			dsnv[i] = new NhanVien(*ct.dsnv[i]);
		}
	}
	return *this;
}

void CongTy::nhapDSNV() {
	cout << "Nhap so luong nhan vien: ";
	cin >> soNV;
	dsnv = new NhanVien * [soNV];

	for (int i = 0; i < soNV; i++) {
		cout << "\n\n\tNHAP NHAN VIEN THU " << i + 1 << endl;

		int loaiNV;
		cout << "Nhap loai nhan vien (1: San xuat, 2: Cong nhat): ";
		cin >> loaiNV;

		if (loaiNV == 1) {
			dsnv[i] = new NVSanXuat();
		}
		else {
			dsnv[i] = new NVCongNhat();
		}
		dsnv[i]->nhap();
	}
}

void CongTy::xuatDSNV() {
	for (int i = 0; i < soNV; i++) {
		cout << "\n\n\t NHAN VIEN THU " << i + 1 << endl;
		dsnv[i]->xuat();
	}
}

void CongTy::ghiDSNhanVienVaoFile(const char* fileName) {
	ofstream ofs(fileName, ios::binary);

	if (!ofs.is_open()) {
		cout << "Khong mo duoc file de ghi!" << endl;
		return;
	}
	ofs << "So luong nhan vien: " << soNV << endl;
	for (int i = 0; i < soNV; i++) {
		NVSanXuat* sx = dynamic_cast<NVSanXuat*>(dsnv[i]);
		if (sx) {
			ofs << "Loai nhan vien: San xuat" << endl;
			dsnv[i]->ghiNhanVien(ofs);
			ofs << "So san pham: " << sx->getSoSanPham() << endl;
			ofs << "Luong: " << fixed << setprecision(2) << sx->tinhLuong() << endl;
			ofs << endl;
		}
		NVCongNhat* cn = dynamic_cast<NVCongNhat*>(dsnv[i]);
		if (cn) {
			ofs << "Loai nhan vien: Cong nhat" << endl;
			dsnv[i]->ghiNhanVien(ofs);
			ofs << "So ngay lam: " << cn->getSoNgayLam() << endl;
			ofs << "Luong: " << fixed << setprecision(2) << cn->tinhLuong() << endl;
			ofs << endl;
		}
	}

}

void CongTy::docDSNhanVienTuFile(const char* fileName) {
	ifstream ifs(fileName, ios::binary);

	if (!ifs.is_open()) {
		cout << "Khong mo duoc file de doc!" << endl;
		return;
	}

	for (int i = 0; i < soNV; i++) {
		delete dsnv[i];
	}
	delete dsnv;

	dsnv = new NhanVien * [soNV];
	string temp;
	getline(ifs, temp, ':');
	ifs.ignore();
	ifs >> soNV;
	//cout << soNV << endl;

	for (int i = 0; i < soNV; i++) {
		getline(ifs, temp, ':');
		ifs.ignore();
		string loaiNV;
		getline(ifs, loaiNV);


		if (loaiNV == "San xuat") {
			dsnv[i] = new NVSanXuat;

			dsnv[i]->docNhanVien(ifs);

			getline(ifs, temp, ':');
			ifs.ignore();
			int soSP;
			ifs >> soSP;
			dynamic_cast<NVSanXuat*>(dsnv[i])->setSoSanPham(soSP);

			getline(ifs, temp, ':');
			ifs.ignore();

		}
		else if (loaiNV == "Cong nhat") {
			dsnv[i] = new NVCongNhat;

			dsnv[i]->docNhanVien(ifs);

			getline(ifs, temp, ':');
			ifs.ignore();
			int soNgayDiLam;
			ifs >> soNgayDiLam;
			dynamic_cast<NVCongNhat*>(dsnv[i])->setSoNgayLam(soNgayDiLam);

			getline(ifs, temp, ':');
			ifs.ignore();
		}
	}

	ifs.close();
}

double CongTy::tinhTongLuong() {
	double tongLuong = 0;
	for (int i = 0; i < soNV; i++) {
		tongLuong += dsnv[i]->tinhLuong();
	}
	return tongLuong;
}

NhanVien* CongTy::timNhanVienLuongCaoNhat() {
	if (soNV == 0) {
		return NULL;
	}

	NhanVien* nhanVienLuongCaoNhat = dsnv[0];
	for (int i = 1; i < soNV; i++) {
		if (dsnv[i]->tinhLuong() > nhanVienLuongCaoNhat->tinhLuong()) {
			nhanVienLuongCaoNhat = dsnv[i];
		}
	}
	return nhanVienLuongCaoNhat;
}

double CongTy::tinhLuongTrungBinh() {
	if (soNV == 0) {
		return 0;
	}

	double tongLuong = tinhTongLuong();
	return tongLuong / soNV;
}

void CongTy::timNhanVienTheoMa() {
	char* ma;
	ma = new char[6];
	cout << "Nhap ma nhan vien can tim: ";
	cin.ignore();
	cin.getline(ma, 6);
	for (int i = 0; i < soNV; i++) {
		if (strcmp(dsnv[i]->getMaNV(), ma) == 0) {
			dsnv[i]->xuat();
			return;
		}
	}
	cout << "Khong tim thay nhan vien co ma " << ma << endl;
}

void CongTy::timNhanVienTheoTen() {
	char* ten;
	ten = new char[51];
	cin.ignore();
	cout << "Nhap ten nhan vien can tim: ";
	cin.getline(ten, 51);
	for (int i = 0; i < soNV; i++) {
		if (strcmp(dsnv[i]->getHoTen(), ten) == 0) {
			dsnv[i]->xuat();
			return;
		}
	}
	cout << "Khong tim thay nhan vien co ten " << ten << endl;

}

void CongTy::demSoNhanVienSinhThang5() {
	int count = 0;
	for (int i = 0; i < soNV; i++) {
		if (dsnv[i]->getNgaySinh().getThang() == 5) {
			count++;
			dsnv[i]->xuat();
			cout << endl;
		}
	}
	cout << "Co " << count << " nhan vien sinh thang 5" << endl;
	
}


void CongTy::themNhanVien() {
	NhanVien* nvMoi;
	int loaiNV;
	cout << "Nhap loai nhan vien (1: san xuat, 2: cong nhat): ";
	cin >> loaiNV;
	if (loaiNV == 1) {
		nvMoi = new NVSanXuat();
	}
	else if (loaiNV == 2) {
		nvMoi = new NVCongNhat();
	}
	else {
		cout << "Loai nhan vien khong hop le!" << endl;
		return;
	}
	nvMoi->nhap();

	NhanVien** newDSNV = new NhanVien * [soNV + 1];

	for (int i = 0; i < soNV; i++) {
		newDSNV[i] = dsnv[i];
	}

	newDSNV[soNV] = nvMoi;

	delete[] dsnv;
	dsnv = newDSNV;

	soNV++;

	ghiDSNhanVienVaoFile("ds_NhanVien.txt");

	cout << "Da them nhan vien vao file " << endl;

}

void CongTy::xoaNhanVien() {
	char* id;
	id = new char[6];
	cout << "Nhap ma nhan vien can xoa: ";
	cin.ignore();
	cin.getline(id, 6);

	int index = -1;
	for (int i = 0; i < soNV; i++) {
		if (strcmp(dsnv[i]->getMaNV(), id) == 0) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "Khong tim thay nhan vien co ma " << id << endl;
		return;
	}

	delete dsnv[index];
	for (int i = index + 1; i < soNV; i++) {
		dsnv[i - 1] = dsnv[i];
	}

	soNV--;

	ghiDSNhanVienVaoFile("ds_NhanVien.txt");

	cout << "Da xoa nhan vien co ma " << id << " ra khoi file" << endl;
}

void CongTy::ghiDSNVLuongNhoHonTrungBinh(const char* filename) {
	
	ofstream ofs(filename);

	if (!ofs.is_open()) {
		cout << "Khong mo duoc file!" << endl;
		return;
	}

	ofs << "\n\n\tTHONG TIN NHAN VIEN CO LUONG NHO HON LUONG TRUNG BINH: " <<fixed << setprecision(2) <<"("<< tinhLuongTrungBinh() << ")" << endl;
	for (int i = 0; i < soNV; i++) {
		if (dsnv[i]->tinhLuong() < tinhLuongTrungBinh()) {
			NVSanXuat* sx = dynamic_cast<NVSanXuat*>(dsnv[i]);
			if (sx) {
				ofs << "Loai nhan vien: San xuat" << endl;
				dsnv[i]->ghiNhanVien(ofs);
				ofs << "So san pham: " << sx->getSoSanPham() << endl;
				ofs << "Luong: " << fixed << setprecision(2) << sx->tinhLuong() << endl;
				ofs << endl;
			}

			NVCongNhat* cn = dynamic_cast<NVCongNhat*>(dsnv[i]);
			if (cn) {
				ofs << "Loai nhan vien: Cong nhat" << endl;
				dsnv[i]->ghiNhanVien(ofs);
				ofs << "So ngay lam: " << cn->getSoNgayLam() << endl;
				ofs << "Luong: " << fixed << setprecision(2) << cn->tinhLuong() << endl;
				ofs << endl;
			}
		}
	}
	ofs.close();
}

