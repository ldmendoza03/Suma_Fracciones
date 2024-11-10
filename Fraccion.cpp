/*
 * Universidad de las Fuerzas Armadas "ESPE"
 * Enunciado: Suma Fracciones
 * Autor: Leandro Mendoza
 * Fecha de Creacion: 5 de Noviembre del 2024
 * Fecha de Modificacion: 10 de Noviembre del 2024
 * NRC: 1978
 * Curso: Estructura de Datos
 * Docente: Edgar Fernando Solis Acosta
 */

#include "Fraccion.h"

int main() {
    Fraccion<int> fraccion1, fraccion2, resultado;

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

