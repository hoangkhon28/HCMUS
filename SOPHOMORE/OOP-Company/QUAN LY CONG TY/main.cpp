#include "CongTy.h"

int main() {
    int ch;
    bool quit = false;
    CongTy ct;
    do {
        system("cls");
        cout << "------------------* QUAN LY NHAN VIEN *-------------------------" << endl;
        cout << "1. Nhap danh sach nhan vien" << endl;
        cout << "2. Xuat danh sach nhan vien" << endl;
        cout << "3. Ghi danh sach nhan vien vao file 'ds_NhanVien.txt'" << endl;
        cout << "4. Doc danh sach nhan vien tu file 'ds_NhanVien.txt'" << endl;
        cout << "5. Tinh tong tien luong cua tat ca nhan vien" << endl;
        cout << "6. Tim nhan vien co luong cao nhat" << endl;
        cout << "7. Tinh luong trung binh cua cong ty" << endl;
        cout << "8. Tim nhan vien co ma tuong ung" << endl;
        cout << "9. Tim nhan vien co ten tuong ung" << endl;
        cout << "10. Dem so nhan vien sinh trong thang 5" << endl;
        cout << "11. Them mot nhan vien vao danh sach va cap nhat lai file 'ds_NhanVien" << endl;
        cout << "12. Xoa mot nhan vien ra khoi danh sach va cap nhat lai file 'ds_NhanVien" << endl;
        cout << "13. Ghi tat ca nhan vien co luong trung binh nho hon luong trung binh cua cong ty len file 'emp_LowerAvgSalary.txt'" << endl;
        cout << "0. Thoat" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Nhap lua chon cua ban: "; cin >> ch;
        switch (ch) {
        case 1:
        {
            ct.nhapDSNV();
            system("pause");
        }
        break;
        case 2:
        {
            ct.xuatDSNV();
            system("pause");
        }
        break;
        case 3:
        {
            ct.ghiDSNhanVienVaoFile("ds_NhanVien.txt");
            system("pause");
        }
        break;
        case 4:
        {
            ct.docDSNhanVienTuFile("ds_NhanVien.txt");
            system("pause");
        }
        break;
        case 5:
        {
            cout << "Tong tien luong cua tat ca nhan vien la: " <<fixed << setprecision(2) << ct.tinhTongLuong();
            system("pause");
        }
        break;
        case 6:
        {
             NhanVien* nvCaoNhat = ct.timNhanVienLuongCaoNhat();
             cout << "Nhan vien luong cao nhat: " << endl;
             nvCaoNhat->xuat();
             system("pause");
        }
        break;
        case 7:
        {
            cout << "Luong trung binh cua cong ty: " << fixed << setprecision(2) << ct.tinhLuongTrungBinh();
            system("pause");
        }
        break;
        case 8:
        {
            ct.timNhanVienTheoMa();
            system("pause");
        }
        break;
        case 9:
        {
            ct.timNhanVienTheoTen();
            system("pause");
        }
        break;
        case 10:
        {
            ct.demSoNhanVienSinhThang5();
            system("pause");
        }
        break;
        case 11:
        {
            ct.themNhanVien();
            system("pause");
        }
        break;
        case 12:
        {
            ct.xoaNhanVien();
            system("pause");
        }
        break;
        case 13:
        {
            ct.ghiDSNVLuongNhoHonTrungBinh("emp_LowerAvgSalary.txt");
            system("pause");
        }
        break;
        case 0:
        {
            exit(0);
            system("pause");
        }
        break;
        default:
        {
            cout << "Lua chon khong hop le!";
            system("pause");
        }
        break;
        }
    } while (!quit);
    return 0;
}
