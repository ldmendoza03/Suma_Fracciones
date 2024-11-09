#ifndef FRACCION_H
#define FRACCION_H

#include <stdio.h>

class Fraccion {
private:
    int numerador;
    int denominador;

public:
    // Constructor
    Fraccion();

    // Métodos set con validaciones
    void setNumerador(int num);
    void setDenominador(int denom);

    // Métodos get
    int getNumerador() const;
    int getDenominador() const;

    // Métodos para ingresar y mostrar fracción
    void ingresarFraccion();
    void mostrarFraccion() const;

    // Métodos para operar fracciones
    Fraccion sumarFracciones(const Fraccion& otra) const;
    void simplificarFraccion();

private:
    int mcd(int a, int b) const; // Método para calcular el MCD
};

#endif
