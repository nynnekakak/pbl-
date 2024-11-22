#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include<string.h>
#include <fstream>
#include <SFML/Graphics.hpp>
#include<math.h>
#include<cmath>
#include<iostream>
#include <sstream> 


using namespace std;
using namespace sf;

class Patient {
public:
    string CCCD;
    string name;
    string gioitinh;
    int age;
    string quequan;
    string diachi;
    string SDT;
    string benh;
    string appointment;
    string phong;
    int cakham;

    Patient();
    ~Patient();
    void in(){
        cout<<"test";
    }
    void input();
    static void save(ofstream& file, const Patient& patient);
    static Patient load(ifstream& file);
     void displayinfor(const Patient& patient) const ;
    static bool compareByCCCD(const Patient& patient, const string& CCCD);
};

#endif
