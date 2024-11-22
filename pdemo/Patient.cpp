#include "libary/Patient.h"
#include<string.h>

Patient::Patient()
    : CCCD(""), name(""), gioitinh(""), age(0), quequan(""),
      diachi(""), SDT(""), benh(""), appointment(""), phong(""), cakham(0) {}
Patient::~Patient(){}
void Patient::input() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nhap CCCD: ";
    getline(cin, CCCD);
    cout << "Nhap ho ten benh nhan: ";
    getline(cin, name);
    cout << "Nhap gioi tinh (Nam/Nu): ";
    getline(cin, gioitinh);
    cout << "Nhap tuoi: ";
    while (!(cin >> age) || age <= 0) {
        cout << "Vui long nhap tuoi la mot so nguyen duong: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nhap que quan: ";
    getline(cin, quequan);
    cout << "Nhap dia chi: ";
    getline(cin, diachi);
    cout << "Nhap so dien thoai: ";
    getline(cin, SDT);
    cout << "Nhap benh cua benh nhan: ";
    getline(cin, benh);
    cout << "Nhap lich hen kham (DD-MM-YYYY): ";
    getline(cin, appointment);
    cout << "Nhap phong kham: ";
    getline(cin, phong);
    cout << "Nhap ca kham (1: Sang, 2: Chieu, 3: Toi): ";
    while (!(cin >> cakham) || cakham < 1 || cakham > 3) {
        cout << "Vui long nhap gia tri hop le (1: Sang, 2: Chieu, 3: Toi): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Patient::save(ofstream& file, const Patient& patient) {
    file << "CCCD: " << patient.CCCD << "\n"
         << "Ho va ten: " << patient.name << "\n"
         << "Gioi tinh: " << patient.gioitinh << "\n"
         << "Tuoi: " << patient.age << "\n"
         << "Que quan: " << patient.quequan << "\n"
         << "Dia chi: " << patient.diachi << "\n"
         << "SDT: " << patient.SDT << "\n"
         << "Benh: " << patient.benh << "\n"
         << "Lich hen: " << patient.appointment << "\n"
         << "Phong kham: " << patient.phong << "\n"
         << "Ca kham: " << patient.cakham << "\n";
}
Patient Patient::load(ifstream& file) {
    Patient patient;
    string temp;

    getline(file, temp); patient.CCCD = temp.substr(temp.find(":") + 2);
    getline(file, temp); patient.name = temp.substr(temp.find(":") + 2);
    getline(file, temp); patient.gioitinh = temp.substr(temp.find(":") + 2);
    getline(file, temp); patient.age = stoi(temp.substr(temp.find(":") + 2));
    getline(file, temp); patient.quequan = temp.substr(temp.find(":") + 2);
    getline(file, temp); patient.diachi = temp.substr(temp.find(":") + 2);
    getline(file, temp); patient.SDT = temp.substr(temp.find(":") + 2);
    getline(file, temp); patient.benh = temp.substr(temp.find(":") + 2);
    getline(file, temp); patient.appointment = temp.substr(temp.find(":") + 2);
    getline(file, temp); patient.phong = temp.substr(temp.find(":") + 2);
    getline(file, temp); patient.cakham = stoi(temp.substr(temp.find(":") + 2));

    return patient;
}
void Patient::displayinfor(const Patient& patient) const {
    cout << "Thong tin benh nhan:\n"
         << " - CCCD: " << patient.CCCD << "\n"
         << " - Ho va ten: " << patient.name << "\n"
         << " - Gioi tinh: " << patient.gioitinh << "\n"
         << " - Tuoi: " << patient.age << "\n"
         << " - Que quan: " << patient.quequan << "\n"
         << " - Dia chi: " << patient.diachi << "\n"
         << " - SDT: " << patient.SDT << "\n"
         << " - Benh: " << patient.benh << "\n"
         << " - Lich hen: " << patient.appointment << "\n"
         << " - Phong kham: " << patient.phong << "\n"
         << " - Ca kham: ";
    switch (patient.cakham) {
        case 1: cout << "Sang"; break;
        case 2: cout << "Chieu"; break;
        case 3: cout << "Toi"; break;
        default: cout << "Khong xac dinh"; break;
    }
    cout << "\n---------------------------------------\n";
}
bool Patient::compareByCCCD(const Patient& patient, const string& CCCD) {
    return patient.CCCD == CCCD;
}
