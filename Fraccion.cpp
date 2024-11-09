/*
 * Universidad de las Fuerzas Armadas "ESPE"
 * Enunciado: Suma Fracciones
 * Autor: Leandro Mendoza
 * Fecha de Creación: 5 de Noviembre del 2024
 * Fecha de Modificación: 9 de Noviembre del 2024
 * NRC: 1978
 * Curso: Estructura de Datos
 * Docente: Edgar Solis
 */

#include "Fraccion.h"

// Constructor por defecto
Fraccion::Fraccion() : numerador(0), denominador(1) {}

// Métodos set con validaciones
void Fraccion::setNumerador(int num) {
    numerador = num;
}

void Fraccion::setDenominador(int denom) {
    if (denom != 0) {
        denominador = denom;
    } else {
        printf("Error: El denominador no puede ser 0. Se asignara valor por defecto 1.\n");
        denominador = 1;
    }
}

// Métodos get
int Fraccion::getNumerador() const {
    return numerador;
}

int Fraccion::getDenominador() const {
    return denominador;
}

// Método para ingresar una fracción con validación
void Fraccion::ingresarFraccion() {
    int num, denom;
    printf("Ingrese el numerador: ");
    scanf("%d", &num);
    setNumerador(num);

    // Validación para asegurarse de que el denominador no sea cero
    do {
        printf("Ingrese el denominador (diferente de 0): ");
        scanf("%d", &denom);
        if (denom == 0) {
            printf("Error: El denominador no puede ser 0. Intente de nuevo.\n");
        }
    } while (denom == 0);
    setDenominador(denom);
}

// Método para mostrar la fracción
void Fraccion::mostrarFraccion() const {
    printf("%d/%d\n", getNumerador(), getDenominador());
}

// Método para sumar dos fracciones
Fraccion Fraccion::sumarFracciones(const Fraccion& otra) const {
    Fraccion resultado;
    resultado.numerador = numerador * otra.denominador + otra.numerador * denominador;
    resultado.denominador = denominador * otra.denominador;
    return resultado;
}

// Método para calcular el MCD
int Fraccion::mcd(int a, int b) const {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Método para simplificar la fracción
void Fraccion::simplificarFraccion() {
    int divisor = mcd(numerador, denominador);
    numerador /= divisor;
    denominador /= divisor;
}

// Función principal (main)
int main() {
    Fraccion fraccion1, fraccion2, resultado;

    printf("Ingrese la primera fraccion:\n");
    fraccion1.ingresarFraccion();

    printf("Ingrese la segunda fraccion:\n");
    fraccion2.ingresarFraccion();

    resultado = fraccion1.sumarFracciones(fraccion2);
    resultado.simplificarFraccion();

    printf("La suma de las fracciones es: ");
    resultado.mostrarFraccion();

    return 0;
}