#include "NhanVien.h"

NhanVien::NhanVien() {
    maNV = new char[6];
    hoTen = new char[51];
    diaChi = new char[101];
    gioiTinh = 0;
}


NhanVien::NhanVien(char* _maNV, char* _hoTen, NgaySinh _ngaySinh, char* _diaChi, bool _gioiTinh) {
    maNV = new char[6];
    strcpy(maNV, _maNV);
    hoTen = new char[51];
    strcpy(hoTen, _hoTen);
    ngaySinh = _ngaySinh;
    diaChi = new char[101];
    strcpy(diaChi, _diaChi);
    gioiTinh = _gioiTinh;
}


NhanVien::NhanVien(const NhanVien& nv) {
    maNV = new char[6];
    strcpy(maNV, nv.maNV);
    hoTen = new char[51];
    strcpy(hoTen, nv.hoTen);
    ngaySinh = nv.ngaySinh;
    diaChi = new char[101];
    strcpy(diaChi, nv.diaChi);
    gioiTinh = nv.gioiTinh;
}

NhanVien::~NhanVien() {
    delete[] maNV;
    delete[] hoTen;
    delete[] diaChi;
}

void NhanVien::nhap() {
    do {
        cout << "Nhap ma nhan vien (chuoi gom 5 ki tu so): ";
        cin >> maNV;
        if (strlen(maNV) != 5) {
            cout << "Ma nhan vien khong hop le" << endl;
        }
    } while (strlen(maNV) != 5);
    cout << "Nhap ho ten: ";
    cin.ignore();
    cin.getline(hoTen, 51);
    cout << "Nhap gioi tinh (0-Nam, 1-Nu): ";
    cin >> gioiTinh;
    do {
        ngaySinh.nhapNS();
        if (gioiTinh == 0 && (ngaySinh.tinhTuoi() < 18 || ngaySinh.tinhTuoi() > 60)) {
            cout << "Do tuoi hop le phai tu 18 - 60 tuoi." << endl;
        }
        if (gioiTinh == 1 && (ngaySinh.tinhTuoi() < 18 || ngaySinh.tinhTuoi() > 55)) {
            cout << "Do tuoi hop le phai tu 18 - 55 tuoi. " << endl;
        }
    } while ((gioiTinh == 0 && (ngaySinh.tinhTuoi() < 18 || ngaySinh.tinhTuoi() > 60))
        || (gioiTinh == 1 && (ngaySinh.tinhTuoi() < 18 || ngaySinh.tinhTuoi() > 55)));

    cout << "Nhap dia chi: ";
    cin.ignore();
    cin.getline(diaChi, 101);
}


void NhanVien::xuat() {
    cout << "Ma nhan vien: " << maNV << endl;
    cout << "Ho ten: " << hoTen << endl;
    ngaySinh.xuatNS();
    cout << "Tuoi: " << ngaySinh.tinhTuoi() << endl;
    if (gioiTinh == 0) cout << "Gioi tinh: Nam" << endl;
    else cout << "Gioi tinh: Nu" << endl;
    cout << "Dia chi: " << diaChi << endl;
}

double NhanVien::tinhLuong() {
    return 0;
}


void NhanVien::ghiNhanVien(ofstream& ofs) const {
    ofs << "Ma nhan vien: " << maNV << endl;
    ofs << "Ho ten: " << hoTen << endl;
    if (gioiTinh == 0) ofs << "Gioi tinh: nam" << endl;
    else ofs << "Gioi tinh: nu" << endl;
    ofs << "Ngay sinh: " << ngaySinh.getNgay() << "/" << ngaySinh.getThang() << "/" << ngaySinh.getNam() << endl;
    ofs << "Dia chi: " << diaChi << endl;

}

void NhanVien::docNhanVien(ifstream& ifs) {
    string temp;
    getline(ifs, temp, ':');
    ifs.ignore();
    ifs >> maNV;

    getline(ifs, temp, ':');
    ifs.ignore();
    ifs.getline(hoTen, 50);

    getline(ifs, temp, ':');
    ifs.ignore();
    string gioi;
    getline(ifs, gioi);
    if (gioi == "nam")
        gioiTinh = 0;
    else if (gioi == "nu")
        gioiTinh = 1;

    int ngay, thang, nam;
    getline(ifs, temp, ':');
    ifs.ignore();
    ifs >> ngay;
    ifs.ignore();
    ifs >> thang;
    ifs.ignore();
    ifs >> nam;
    ngaySinh.setNgay(ngay);
    ngaySinh.setThang(thang);
    ngaySinh.setNam(nam);

    getline(ifs, temp, ':');
    ifs.ignore();
    ifs.getline(diaChi, 100);
}

char* NhanVien::getMaNV() {
    return maNV;
}

char* NhanVien::getHoTen() {
    return hoTen;
}

NgaySinh NhanVien::getNgaySinh() {
    return ngaySinh;
}

