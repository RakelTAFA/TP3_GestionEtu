#pragma once
#include <Qstring>

class Student
{
private:
    QString Id;
    QString Lastname;
    QString Firstname;
    QString Bac;
    QString Departement;

public:
    Student() { ; }
    Student(const QString Id = QString(), QString ln = "", QString fn = "", QString dep = "", QString b = "" );

    QString getId() const { return Id;}
    QString getLastname() const { return Lastname;}
    QString getFirstname() const { return Firstname;}
    QString getBac() const { return Bac;}
    QString getDepartement() const { return Departement;}

    void setId(QString a) { this->Id = a; }
    void setLastname(QString a) { this->Lastname = a; }
    void setFisrtname(QString a) { this->Firstname = a; }
    void setBac(QString a) { this->Bac = a; }
    void setDepartement(QString a) { this->Departement = a; }

};