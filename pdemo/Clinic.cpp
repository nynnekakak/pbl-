#include "libary/Clinic.h"

Clinic::Clinic() : lichhen(""), roomID(0), shift(0), patientCCCD("") {}
Clinic::~Clinic(){}

void Clinic::save(ofstream& file, const Clinic& clinic) {
    file << clinic.lichhen << " " 
         << clinic.roomID << " " 
         << clinic.shift << " "
         << clinic.patientCCCD << "\n";
}

Clinic Clinic::load(ifstream& file) {
    Clinic clinic;
    getline(file, clinic.lichhen);
    file >> clinic.roomID;
    file.ignore();
    file >> clinic.shift;
    file.ignore();
    getline(file, clinic.patientCCCD);
    return clinic;
}

void Clinic::display(const Clinic& clinic) {
    cout << "Phong kham:\n"
         << " - Lich hen: " << clinic.lichhen << "\n"
         << " - Ma phong: ";
    switch (clinic.roomID) {
        case 1: cout << "F101"; break;
        case 2: cout << "F102"; break;
        case 3: cout << "F103"; break;
        case 4: cout << "F104"; break;
        default: cout << "Khong xac dinh"; break;
    }
    cout << "\n - Ca truc: ";
    switch (clinic.shift) {
        case 1: cout << "Sang"; break;
        case 2: cout << "Chieu"; break;
        case 3: cout << "Toi"; break;
        default: cout << "Khong xac dinh"; break;
    }
    cout << "\n - CCCD benh nhan: " << clinic.patientCCCD << "\n"
         << "---------------------------------------\n";
}

bool Clinic::compareByRoomID(const Clinic& clinic, const string& key) {
    int keyInt = 0;
    if (key == "F101") keyInt = 1;
    else if (key == "F102") keyInt = 2;
    else if (key == "F103") keyInt = 3;
    else if (key == "F104") keyInt = 4;
    return clinic.roomID == keyInt;
}
