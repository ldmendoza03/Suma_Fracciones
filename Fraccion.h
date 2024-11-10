#ifndef FRACCION_H
#define FRACCION_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // Para usar getch()

template <typename T>
class Fraccion {
private:
    T numerador;
    T denominador;

public:
    // Constructor por defecto
    Fraccion() : numerador(0), denominador(1) {}

    // Métodos set con validaciones
    void setNumerador(T num) { numerador = num; }
    void setDenominador(T denom) {
        if (denom != 0) denominador = denom;
        else {
            printf("Error: El denominador no puede ser 0. Se asignará valor por defecto 1.\n");
            denominador = 1;
        }
    }

    // Métodos get
    T getNumerador() const { return numerador; }
    T getDenominador() const { return denominador; }

    // Método para ingresar un número con validación
    T ingresarNumero(const char* mensaje) {
        printf("%s", mensaje);
        char cad[10], c;
        int i = 0;
        while ((c = getch()) != 13) {  // 13 es el código ASCII de Enter
            if (c >= '0' && c <= '9' && i < 9) { // Solo permite números
                printf("%c", c);
                cad[i++] = c;
            } else if (c == 8 && i > 0) { // Permite borrar con Backspace
                printf("\b \b");
                i--;
            }
        }
        cad[i] = '\0';
        printf("\n");
        return atoi(cad); // Convierte la cadena a un número entero
    }

    // Método para ingresar una fracción con validación
    void ingresarFraccion() {
        setNumerador(ingresarNumero("Ingrese el numerador: "));
        do {
            setDenominador(ingresarNumero("Ingrese el denominador (diferente de 0): "));
            if (getDenominador() == 0) {
                printf("Error: El denominador no puede ser 0. Intente nuevamente.\n");
            }
        } while (getDenominador() == 0);
    }

    // Método para mostrar la fracción
    void mostrarFraccion() const { printf("%d/%d\n", getNumerador(), getDenominador()); }

    // Método para sumar dos fracciones
    Fraccion<T> sumarFracciones(const Fraccion<T>& otra) const {
        Fraccion<T> resultado;
        resultado.setNumerador(numerador * otra.getDenominador() + otra.getNumerador() * denominador);
        resultado.setDenominador(denominador * otra.getDenominador());
        return resultado;
    }

    // Método para simplificar la fracción
    void simplificarFraccion() {
        T divisor = mcd(numerador, denominador);
        numerador /= divisor;
        denominador /= divisor;
    }

private:
    T mcd(T a, T b) const {
        if (b == 0) return a;
        return mcd(b, a % b);
    }
};

#endif
