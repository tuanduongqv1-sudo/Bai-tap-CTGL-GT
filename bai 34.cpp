#include <iostream>
#include <string>
using namespace std;

// Câu 1: Ð?nh ngh?a c?u trúc Nhân viên
struct NhanVien {
    int maNV;
    string hoTen;
    string ngaySinh;
    double luong; // Ðõn v?: tri?u ð?ng
};

// Câu 2: Hàm nh?p n nhân viên
void nhapDanhSach(NhanVien a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nNhap nhan vien thu " << i + 1 << ":\n";

        cout << "Ma nhan vien: ";
        cin >> a[i].maNV;
        cin.ignore();

        cout << "Ho ten: ";
        getline(cin, a[i].hoTen);

        cout << "Ngay sinh (dd/mm/yyyy): ";
        getline(cin, a[i].ngaySinh);

        cout << "Luong (trieu dong): ";
        cin >> a[i].luong;
    }
}

// Câu 3: Hàm xu?t n nhân viên
void xuatDanhSach(NhanVien a[], int n) {
    cout << "\n===== DANH SACH NHAN VIEN =====\n";

    for (int i = 0; i < n; i++) {
        cout << "\nNhan vien thu " << i + 1 << ":\n";
        cout << "Ma NV: " << a[i].maNV << endl;
        cout << "Ho ten: " << a[i].hoTen << endl;
        cout << "Ngay sinh: " << a[i].ngaySinh << endl;
        cout << "Luong: " << a[i].luong << " trieu dong" << endl;
    }
}

// Câu 4: S?p x?p n?i b?t (Bubble Sort)
// S?p x?p tãng d?n theo lýõng
void bubbleSort(NhanVien a[], int n) {
    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - 1 - i; j++) {

            if (a[j].luong > a[j + 1].luong) {
                // Hoán ð?i 2 nhân viên
                NhanVien temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Câu 5: T?m ki?m nh? phân
// T?m các nhân viên có lýõng b?ng X
void timKiemNhiPhan(NhanVien a[], int n, double X) {
    int left = 0;
    int right = n - 1;
    bool found = false;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid].luong == X) {
            found = true;

            // T?m v? bên trái ð? t?m nhân viên
            // có cùng m?c lýõng X
            int i = mid;

            while (i >= 0 && a[i].luong == X) {
                i--;
            }

            // Xu?t t?t c? nhân viên có lýõng = X
            for (int j = i + 1;
                 j < n && a[j].luong == X;
                 j++) {

                cout << "\nMa NV: " << a[j].maNV;
                cout << "\nHo ten: " << a[j].hoTen;
                cout << "\nNgay sinh: " << a[j].ngaySinh;
                cout << "\nLuong: " << a[j].luong
                     << " trieu dong\n";
            }

            break;
        }
        else if (a[mid].luong < X) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (!found) {
        cout << "\nKhong tim thay nhan vien co luong = "
             << X << " trieu dong.\n";
    }
}

// Câu 6: Hàm chính
int main() {
    int n;

    cout << "Nhap so luong nhan vien n = ";
    cin >> n;

    NhanVien a[100];

    // Nh?p n nhân viên
    nhapDanhSach(a, n);

    // Hi?n th? danh sách v?a nh?p
    cout << "\n\n--- DANH SACH VUA NHAP ---";
    xuatDanhSach(a, n);

    // S?p x?p tãng d?n theo lýõng
    bubbleSort(a, n);

    cout << "\n\n--- DANH SACH SAU KHI SAP XEP ---";
    xuatDanhSach(a, n);

    // Nh?p X
    double X;

    cout << "\nNhap muc luong X can tim: ";
    cin >> X;

    // T?m ki?m nh? phân
    cout << "\n--- NHAN VIEN CO LUONG = "
         << X << " ---\n";

    timKiemNhiPhan(a, n, X);

    return 0;
}
