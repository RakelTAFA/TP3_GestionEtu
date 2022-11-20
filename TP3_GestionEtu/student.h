#pragma once
#include <Qstring>

/**
 * @brief Class to construct the Promotion
 * @author Rakel Tafa
*/

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

    /**
     * @short   Constructor for Student
     * @param   QString, QString, QString, QString, QString
     */

    Student(const QString Id = QString(), QString ln = "", QString fn = "", QString dep = "", QString b = "" );

    /**
     * @short    Getter for Student ID
     * @return   QString
     */

    QString getId() const { return Id;}

    /**
     * @short   Getter for Student family name
     * @return  QString
     */

    QString getLastname() const { return Lastname;}

    /**
     * @short    Getter for Student first name
     * @return   QString
     */

    QString getFirstname() const { return Firstname;}

    /**
     * @short    Getter for Student bac
     * @return   QString
     */

    QString getBac() const { return Bac;}

    /**
     * @short    Getter for Student departement
     * @return   QString
     */

    QString getDepartement() const { return Departement;}

    void setId(QString a) { this->Id = a; }
    void setLastname(QString a) { this->Lastname = a; }
    void setFisrtname(QString a) { this->Firstname = a; }
    void setBac(QString a) { this->Bac = a; }
    void setDepartement(QString a) { this->Departement = a; }

};