#ifndef MANAGEMENTSYSTEM_H
#define MANAGEMENTSYSTEM_H

#include "libary/LinkedList.h"
#include "libary/Patient.h"
#include "libary/Doctor.h"
#include "libary/Clinic.h"

class ManagementSystem {
private:
    LinkedList<Patient> patients;
    LinkedList<Doctor> doctors;
    LinkedList<Clinic> clinics;

public:
    void loadAllData();
    void saveAllData();
    void addPatient();
    void removePatient();
    void displayPatients() const;
    void addDoctor();
    void removeDoctor();
    void displayDoctors() const;
    void displayClinics() const;
};

#endif
