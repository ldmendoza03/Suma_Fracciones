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

int main() {
    Fraccion<int> fraccion1, fraccion2, resultado;

    printf("Ingrese la primera fracción:\n");
    fraccion1.ingresarFraccion();

    printf("Ingrese la segunda fracción:\n");
    fraccion2.ingresarFraccion();

    resultado = fraccion1.sumarFracciones(fraccion2);
    resultado.simplificarFraccion();

    printf("La suma de las fracciones es: ");
    resultado.mostrarFraccion();

    return 0;
}
