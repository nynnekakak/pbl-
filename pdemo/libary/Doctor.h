#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Doctor {
public:
    string doctorID;
    string name;
    string phoneNumber;
    string gmail;
    string chuyennganh;

    Doctor();
    ~Doctor();
    void input();
    static void save(ofstream& file, const Doctor& doctor);
    static Doctor load(ifstream& file);
    static void display(const Doctor& doctor);
    static bool compareByID(const Doctor& doctor, const string& doctorID);
};

#endif
