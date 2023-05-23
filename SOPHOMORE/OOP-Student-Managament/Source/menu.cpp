#include "StudentList.h"

void menu() {
    StudentList st;
    int choosen;
    bool quit = false;
    do {
        system("cls");
        cout << "====================== *STUDENT LIST MANAGEMENT* ==========================" << endl;
        cout << "1. Nhap danh sach sinh vien. " << endl;
        cout << "2. Xuat danh sach sinh vien. " << endl;
        cout << "3. Ghi danh sach sinh vien vao tap tin. " << endl;
        cout << "4. Doc danh sach sinh vien tu tap tin. " << endl;
        cout << "5. Danh sach sinh vien co diem trung binh nho hon diem trung binh cua lop. " << endl;
        cout << "6. Them sinh vien vao danh sach. " << endl;
        cout << "7. Danh sach sinh vien co thong tin xep loai. " << endl;
        cout << "8. Danh sach sinh vien co cung ngay sinh nhat trong ngay hien tai. " << endl;
        cout << "0. Thoat chuong trinh." << endl;
        cout << "============================================================================" << endl;

        cout << "\nNhap lua chon cua ban: ";
        cin >> choosen;
        switch (choosen) {
        case 1:
        {
            st.inputList();
            system("pause");
        }
        break;
        case 2:
        {
            st.printList();
            system("pause");
        }
        break;
        case 3:
        {
            cin.ignore();
            cout << "Nhap ten file de ghi danh sach vao: ";
            char* fileName;
            fileName = new char[50];
            cin.getline(fileName, 50);
            st.writeList(fileName);
            system("pause");
        }
        break;
        case 4:
        {
            cin.ignore();
            cout << "Nhap ten file de doc vao danh sach: ";
            char* fileName = new char[50];
            cin.getline(fileName, 50);
            st.readList(fileName);
            system("pause");
        }
        break;
        case 5:
        {
            cin.ignore();
            cout << "Nhap ten file de ghi danh sach vao: ";
            char* fileName = new char[50];
            cin.getline(fileName, 50);
            st.writeListLowerAvg(fileName);
            system("pause");
        }
        break;
        case 6:
        {
            st.addNewStudent();
            system("pause");
        }
        break;
        case 7:
        {
            st.printListWithGrade();
            system("pause");
        }
        break;
        case 8:
        {
            st.studentWithSameBirthday();
            system("pause");
        }
        break;
        case 0:
        {
            exit(0);
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
}
