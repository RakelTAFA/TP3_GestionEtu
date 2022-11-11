#pragma once
#include<qstring>
#include<iostream>
using namespace std;

class Student
{
private:
    int numero;
    QString prenom;
    QString nom;
    QString bac;
    QString departement;

public: 
    Student(int& _numero, QString& _prenom, QString& _nom, QString& _bac, QString& _departement) : numero(_numero), prenom(_prenom), nom(_nom), bac(_bac), departement(_departement) { ; }

    int getNumero() const { return numero; }
    const QString getPrenom() const { return prenom; }
    const QString getNom() const { return nom; }
    const QString getBac() const { return bac; }
    const QString getDepartement() const { return departement; }
};

