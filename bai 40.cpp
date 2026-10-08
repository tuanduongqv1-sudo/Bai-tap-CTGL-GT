#include <iostream>
#include <string>
using namespace std;

// =====================================================
// CÂU 1: Ð?nh ngh?a c?u trúc Sinh viên
// =====================================================

struct SinhVien {
    int maSV;
    string tenSV;
    string lop;
    float tongKet;
    string hanhKiem;
};

// =====================================================
// CÂU 2: C?u trúc cây nh? phân t?m ki?m
// =====================================================

// Ð?nh ngh?a m?t node
struct Node {
    SinhVien data;
    Node* left;
    Node* right;
};

// Ki?u cây
typedef Node* Tree;


// =====================================================
// 1. Kh?i t?o cây
// =====================================================

void KhoiTao(Tree &T) {
    T = NULL;
}


// =====================================================
// 2. T?o m?i m?t nút ch?a d? li?u
// =====================================================

Node* TaoNode(SinhVien sv) {
    Node* p = new Node;

    p->data = sv;
    p->left = NULL;
    p->right = NULL;

    return p;
}


// =====================================================
// 3. Chèn nút vào cây
// M? sinh viên là khóa
// =====================================================

void ChenNode(Tree &T, Node* p) {

    // Cây r?ng
    if (T == NULL) {
        T = p;
    }

    // M? sinh viên nh? hõn khóa hi?n t?i
    else if (p->data.maSV < T->data.maSV) {
        ChenNode(T->left, p);
    }

    // M? sinh viên l?n hõn khóa hi?n t?i
    else if (p->data.maSV > T->data.maSV) {
        ChenNode(T->right, p);
    }

    // M? sinh viên b? trùng
    else {
        cout << "Ma sinh vien da ton tai!\n";
        delete p;
    }
}


// =====================================================
// 4. T?m ki?m sinh viên theo m? sinh viên
// =====================================================

Node* TimKiem(Tree T, int maSV) {

    // Không t?m th?y
    if (T == NULL) {
        return NULL;
    }

    // T?m th?y
    if (T->data.maSV == maSV) {
        return T;
    }

    // T?m bên trái
    if (maSV < T->data.maSV) {
        return TimKiem(T->left, maSV);
    }

    // T?m bên ph?i
    return TimKiem(T->right, maSV);
}


// =====================================================
// 5. Duy?t cây - NLR (Preorder)
// =====================================================

void DuyetCay(Tree T) {

    if (T != NULL) {

        // X? l? node hi?n t?i
        cout << "\nMa SV: " << T->data.maSV;
        cout << "\nTen SV: " << T->data.tenSV;
        cout << "\nLop: " << T->data.lop;
        cout << "\nTong ket: " << T->data.tongKet;
        cout << "\nHanh kiem: " << T->data.hanhKiem;
        cout << "\n--------------------------";

        // Duy?t cây con trái
        DuyetCay(T->left);

        // Duy?t cây con ph?i
        DuyetCay(T->right);
    }
}


// =====================================================
// Hàm nh?p thông tin sinh viên
// =====================================================

SinhVien NhapSinhVien() {

    SinhVien sv;

    cout << "Ma sinh vien: ";
    cin >> sv.maSV;
    cin.ignore();

    cout << "Ten sinh vien: ";
    getline(cin, sv.tenSV);

    cout << "Lop: ";
    getline(cin, sv.lop);

    cout << "Tong ket: ";
    cin >> sv.tongKet;
    cin.ignore();

    cout << "Hanh kiem (Tot/Kha/Trung binh/Yeu): ";
    getline(cin, sv.hanhKiem);

    return sv;
}


// =====================================================
// CÂU 3, 4, 5: Chýõng tr?nh chính
// =====================================================

int main() {

    Tree T;

    // Kh?i t?o cây
    KhoiTao(T);

    // -----------------------------------------------
    // CÂU 3: Nh?p n sinh viên vào cây
    // -----------------------------------------------

    int n;

    cout << "Nhap so luong sinh vien n = ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        cout << "\n===== NHAP SINH VIEN THU "
             << i + 1 << " =====\n";

        SinhVien sv = NhapSinhVien();

        Node* p = TaoNode(sv);

        ChenNode(T, p);
    }


    // -----------------------------------------------
    // CÂU 4: Duy?t cây
    // -----------------------------------------------

    cout << "\n\n================================";
    cout << "\nDANH SACH SINH VIEN TRONG CAY";
    cout << "\n================================\n";

    DuyetCay(T);


    // -----------------------------------------------
    // CÂU 5: T?m ki?m sinh viên
    // -----------------------------------------------

    int maCanTim;

    cout << "\n\nNhap ma sinh vien can tim: ";
    cin >> maCanTim;

    Node* ketQua = TimKiem(T, maCanTim);

    if (ketQua != NULL) {

        cout << "\n===== SINH VIEN TIM THAY =====\n";

        cout << "Ma SV: "
             << ketQua->data.maSV << endl;

        cout << "Ten SV: "
             << ketQua->data.tenSV << endl;

        cout << "Lop: "
             << ketQua->data.lop << endl;

        cout << "Tong ket: "
             << ketQua->data.tongKet << endl;

        cout << "Hanh kiem: "
             << ketQua->data.hanhKiem << endl;
    }
    else {

        cout << "\nKhong co sinh vien co ma "
             << maCanTim
             << " trong cay!\n";
    }

    return 0;
}
