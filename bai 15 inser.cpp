#include <iostream>
#include <string>
using namespace std;

// Câu 1: Ð?nh ngh?a c?u trúc Khách hàng
struct KhachHang {
    int maKH;
    string tenKH;
    string soDienThoai;
    double tongTien;
};

// Câu 2: Hàm nh?p n khách hàng
void nhapDanhSach(KhachHang a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nNhap khach hang thu " << i + 1 << ":\n";

        cout << "Ma khach hang: ";
        cin >> a[i].maKH;
        cin.ignore();

        cout << "Ten khach hang: ";
        getline(cin, a[i].tenKH);

        cout << "So dien thoai: ";
        getline(cin, a[i].soDienThoai);

        cout << "Tong tien thanh toan: ";
        cin >> a[i].tongTien;
    }
}

// Câu 3: Hàm xu?t danh sách khách hàng
void xuatDanhSach(KhachHang a[], int n) {
    cout << "\n===== DANH SACH KHACH HANG =====\n";

    for (int i = 0; i < n; i++) {
        cout << "\nKhach hang thu " << i + 1 << ":\n";
        cout << "Ma KH: " << a[i].maKH << endl;
        cout << "Ten KH: " << a[i].tenKH << endl;
        cout << "So dien thoai: " << a[i].soDienThoai << endl;
        cout << "Tong tien thanh toan: " << a[i].tongTien << endl;
    }
}

// Câu 4: S?p x?p chèn tr?c ti?p - Insertion Sort
void insertionSort(KhachHang a[], int n) {
    for (int i = 1; i < n; i++) {
        KhachHang x = a[i];
        int j = i - 1;

        // Ðýa các ph?n t? có t?ng ti?n l?n hõn x sang ph?i
        while (j >= 0 && a[j].tongTien > x.tongTien) {
            a[j + 1] = a[j];
            j--;
        }

        // Chèn x vào v? trí thích h?p
        a[j + 1] = x;
    }
}

// Câu 5: T?m ki?m nh? phân khách hàng có t?ng ti?n = X
void timKiemNhiPhan(KhachHang a[], int n, double X) {
    int left = 0;
    int right = n - 1;
    bool found = false;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid].tongTien == X) {
            found = true;

            // T?m sang bên trái ð? l?y các khách hàng trùng X
            int i = mid;
            while (i >= 0 && a[i].tongTien == X) {
                i--;
            }

            // Xu?t các khách hàng có t?ng ti?n = X
            for (int j = i + 1; j < n && a[j].tongTien == X; j++) {
                cout << "\nMa KH: " << a[j].maKH;
                cout << "\nTen KH: " << a[j].tenKH;
                cout << "\nSo dien thoai: " << a[j].soDienThoai;
                cout << "\nTong tien: " << a[j].tongTien << endl;
            }

            break;
        }
        else if (a[mid].tongTien < X) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (!found) {
        cout << "\nKhong tim thay khach hang co tong tien = " << X << endl;
    }
}

// Câu 6: Hàm main
int main() {
    int n;

    cout << "Nhap so luong khach hang n = ";
    cin >> n;

    KhachHang a[100];

    // Nh?p danh sách
    nhapDanhSach(a, n);

    // Xu?t danh sách v?a nh?p
    cout << "\n\n--- DANH SACH VUA NHAP ---";
    xuatDanhSach(a, n);

    // S?p x?p tãng d?n theo t?ng ti?n
    insertionSort(a, n);

    cout << "\n\n--- DANH SACH SAU KHI SAP XEP ---";
    xuatDanhSach(a, n);

    // Nh?p X
    double X;
    cout << "\nNhap tong tien X can tim: ";
    cin >> X;

    // T?m ki?m nh? phân
    cout << "\n--- CAC KHACH HANG CO TONG TIEN = " << X << " ---\n";
    timKiemNhiPhan(a, n, X);

    return 0;
}
