#include "libary/Doctor.h"

Doctor::Doctor() : doctorID(""), name(""), phoneNumber(""), gmail(""), chuyennganh("") {}
Doctor::~Doctor(){}
void Doctor::input() {
    cout << "Nhap ma bac si: ";
    getline(cin, doctorID);
    cout << "Nhap ten bac si: ";
    getline(cin, name);
    cout << "Nhap so dien thoai: ";
    getline(cin, phoneNumber);
    cout << "Nhap email: ";
    getline(cin, gmail);
    cout << "Nhap chuyen nganh: ";
    getline(cin, chuyennganh);
}

void Doctor::save(ofstream& file, const Doctor& doctor) {
    file << doctor.doctorID << "\n"
         << doctor.name << "\n"
         << doctor.phoneNumber << "\n"
         << doctor.gmail << "\n"
         << doctor.chuyennganh << "\n";
}

Doctor Doctor::load(ifstream& file) {
    Doctor doctor;
    getline(file, doctor.doctorID);
    getline(file, doctor.name);
    getline(file, doctor.phoneNumber);
    getline(file, doctor.gmail);
    getline(file, doctor.chuyennganh);
    return doctor;
}

void Doctor::display(const Doctor& doctor) {
    cout << "Thong tin bac si:\n"
         << " - Ma bac si: " << doctor.doctorID << "\n"
         << " - Ten: " << doctor.name << "\n"
         << " - So dien thoai: " << doctor.phoneNumber << "\n"
         << " - Email: " << doctor.gmail << "\n"
         << " - Chuyen nganh: " << doctor.chuyennganh << "\n"
         << "---------------------------------------\n";
}

bool Doctor::compareByID(const Doctor& doctor, const string& doctorID) {
    return doctor.doctorID == doctorID;
}
