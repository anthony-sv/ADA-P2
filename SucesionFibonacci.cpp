/*
    INSTITUTO POLITÉCNICO NACIONAL
    ESCUELA SUPERIOR DE CÓMPUTO
    ASIGNATURA:
        ANÁLISIS DE ALGORITMOS
    GRUPO: 
        3CV11
    PROFESOR: 
        LUNA BENOSO BENJAMÍN
    ALUMNO: 
        STEINER VÁZQUEZ ANTHONY FRANCIS
    TÍTULO: 
        PRÁCTICA 2: COMPLEJIDADES TEMPORALES POLINOMIALES Y NO POLINOMIALES.
    ARCHIVO: SucesionFibonacci.cpp
    DESARROLLO:
        Implementación de un algoritmo que calcule el n-ésimo término de la sucesión de Fibonacci,
        tanto en su forma iterativa como en su forma recursiva.
    ENTREGA: 
        14/03/2022
*/

// librerías
#include <iostream>
#include <vector>
#include <sstream>

/**
 * Función iterativa que calcula el n-esimo termino de la sucesion de Fibonacci.
 * 
 * @param n n-esimo termino a calcular de la sucesion de Fibonacci
 * @return int - n-esimo termino de la sucesion de Fibonacci F_n
 */
int FibonacciIterativo(unsigned int n, unsigned int& ct)
{
    ct++;
    int fib{}; // variable para guardar el n-esimo termino de la sucesión
    ct++;
    int ant1{1}; // variable para guardar el n-1 termino de la sucesión
    ct++;
    int ant2{}; // variable para guardar el n-2 termino de la sucesión
    ct++;
    int i; // variable para iterar 
    for (i = 1; i <= n; i++) //for que va desde 1 hasta n inclusivo
    {
        ct++;
        if (i == 1) // checamos si i es 1
        {
            ct++;
            ct++;
            fib = 1; // en ese caso decimos que el Fn = 1
            ct++;
            continue; // saltamos a la siguiente condición
        }
        else // caso contrario
        {
            ct++;
            ct++;
            fib = ant1 + ant2; // calculamos el nuevo Fn sumando el Fn-1 con Fn-2
            ct++;
            ant2 = ant1; // ahora nuestro Fn-2 es el Fn-1 actual
            ct++;
            ant1 = fib; // ahora nuestro Fn-1 es el Fn actual
        }
        ct++;
    }
    ct++;
    ct++;
    return fib; //retornamos el n-esimo término
}

/**
 * Función recursiva que calcula el n-esimo termino de la sucesion de Fibonacci.
 * 
 * @param n n-esimo termino a calcular de la sucesion de Fibonacci
 * @return int - n-esimo termino de la sucesion de Fibonacci F_n
 */
int FibonacciRecursivo(unsigned int n, unsigned int& ct)
{
    if (n == 0) // checamos si n es 0
    {
        ct++;
        ct++;
        return 0; // en ese caso retornamos 0
    }
    else if (n == 1) // checamos si n es 1
    {
        ct++;
        ct++;
        ct++;
        return 1; // en ese caso retornamos 1
    }
    else
    {
        ct++;
        ct++;
        ct++;
        ct++;
        return FibonacciRecursivo(n - 1, ct) + FibonacciRecursivo(n - 2,ct); // retornamos recursivamente Fn-1 + Fn-2
    }
}

/**
 * @brief Función main
 * 
 * @param argc contador de argumentos
 * @param argv arreglo de strings con los argumentos
 * @return 0 - valor de retorno de la función main
 */
int main(int argc, char const *argv[])
{
    int n; // variable para ver que número de la serie de Fibonacci queremos
    if (argc > 1) // checamos si nos pasan argumentos por línea de comandos
    {
        std::istringstream iss(argv[1]); // en ese caso lo guardamos
        iss >> n; // y lo asignamos a nuestra variable n
    }
    else // caso contrario
    {
        std::cout << "Ingrese el valor de n: "; // escribimos en pantalla que necesitamos el valor de n
        std::cin >> n; // guardamos el valor de n
    }
    unsigned int contador1{}; // inicializacion del contador para la versión iterativa
    unsigned int contador2{}; // inicializacion del contador para la versión recursiva
    int fibi = FibonacciIterativo(n, contador1); // calculamos el Fn con la versión iterativa.
    int fibr = FibonacciRecursivo(n, contador2); // calculamos el Fn con la versión recursiva.
    std::cout << fibi << "\n"; // imprimimos el Fn de la versión iterativa.
    std::cout << fibr << "\n"; // imprimimos el Fn de la versión recursiva.
    std::cout << "El algoritmo iterativo hizo: " << contador1 << " operaciones.\n"; // imprimimos cuantas operaciones hizo la versión iterativa
    std::cout << "El algoritmo recursivo hizo: " << contador2 << " operaciones.\n"; // imprimimos cuantas operaciones hizo la versión recursiva
    return 0; // retornamos 0
}