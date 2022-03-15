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
    ARCHIVO: MostrarPerfectos.cpp
    DESARROLLO:
        Implementación de un algoritmo que calcule los primeros n números perfectos.
    ENTREGA: 
        14/03/2022
*/

// librerías
#include <iostream>
#include <cmath>
#include <sstream>

/**
 * Función que checa si un número es perfecto, es decir la suma de sus divisores excluyendo el numero mismo.
 * 
 * @param n El numero que queremos saber si es perfecto
 * @return bool - resultado de evaluar si el numero n es perfecto o no
 */
bool Perfecto(const std::uint64_t& n, std::uint64_t& ct)
{
    ct++;
    std::uint64_t sum{1}; // variable para guardar la suma de los divisores
    ct++;
    auto sqrt{std::ceil(std::sqrt(n))}; // calculamos el techo de la raíz cuadrada de n
    ct++; 
    unsigned int i; // variable para iterar
    for(i=2; i<sqrt; i++) // iteramos desde 2 hasta la variable sqrt
    {
        ct++;
        if(n % i == 0 && i != n/i) // checamos si n es divisible entre i, y que i no sea su par de factores de n, es decir n/i
        {
            ct++;
            ct++;
            sum += i+n/i; // en ese caso a nuestra variable sum, sumamos ambos factores
        }
        ct++;
        ct++;
    }
    ct++;
    ct++;
    return (sum == n && n!=1) ? true : false; // en caso de que sum sea igual a n, y n no sea 1, retornamos true, en caso contrario false
}

/**
 * Función que calcula los primeros n numeros perfectos
 * 
 * @param n La cantidad de numeros perfectos a imprimir
 */
void MostrarPerfectos(int n, std::uint64_t& ct)
{
    ct++;
    int aux{0}; // variable para guardar cuantos números perfectos hemos calculado
    ct++;
    std::uint64_t i; // variable para iterar
    for(i=6; aux<n ; i++) // iteramos desde 6, que es el primer perfecto, hasta que aux sea >= n
    {
        ct++;
        if(Perfecto(i, ct)) // checamos si el i actual es un número perfecto
        {
            ct++;
            ct++;
            std::cout << i << " "; // en ese caso lo imprimos junto con un espacio, para imprimirlo como lista.
            ct++;
            aux++; // aumentamos el valor de aux, puesto que hemos encontrado un número perfecto.
        }
        ct++;
        ct++;
    }
    ct++;
    ct++;
    std::cout << "\n"; // imprimimos un salto de linea.
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
    int n; // variable para ver cuántos números perfectos vamos a imprimir
    if(argc >1) // checamos si nos pasan argumentos por línea de comandos
    {
        std::istringstream iss(argv[1]); // en ese caso lo guardamos
        iss >> n; // y lo asignamos a nuestra variable n
    }
    else // caso contrario
    {
        std::cout << "Ingrese el valor de n: "; // escribimos en pantalla que necesitamos el valor de n
        std::cin >> n; // guardamos el valor de n
    }
    std::uint64_t contador{}; // inicializacion del contador
    MostrarPerfectos(n, contador); // calculamos los n primeros numeros perfectos
    std::cout << "El algoritmo hizo: " << contador << " operaciones.\n"; // imprimimos cuantas operaciones hizo el algoritmo
    return 0;
}