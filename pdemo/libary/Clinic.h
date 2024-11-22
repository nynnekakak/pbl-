#ifndef CLINIC_H
#define CLINIC_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Clinic {
public:
    string lichhen;
    int roomID;
    int shift;
    string patientCCCD;

    Clinic();
    ~Clinic();
    
    static void save(ofstream& file, const Clinic& clinic);
    static Clinic load(ifstream& file);
    static void display(const Clinic& clinic);
    static bool compareByRoomID(const Clinic& clinic, const string& key);
};

#endif
