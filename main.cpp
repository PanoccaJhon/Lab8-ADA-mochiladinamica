#include <iostream>
#include <vector>

/**
 * Autor: Jhon Franklin Panocca Merma
 */
using namespace std;

/**
 * Metodo que calcula el maximo de dos elementos
 * @brief max
 * @param a Valor entero
 * @param b Valor entero
 * @return  EL máximo valor de a y b
 */
int max(int a, int b){
    return (a<b)? b:a;
}

/**
 * Metodo que calcula el beneficio maximo al satisfacer la capacidad
 * de la "mochila" con una lista de items (kilos por item)
 * @brief mochilaDinamica
 * @param capacidad Valor a satisfacer al convinar una lista de items
 * @param kilos Lista de valores a convinar por ítem.
 * @return Retorna el beneficio maximo
 */
int mochilaDinamica(int capacidad,vector<int>kilos)
{
    //crear la matriz
    vector<vector<int>> mat(kilos.size()+1,vector<int>(capacidad+1));
    //llenar de 0s la primera fila
    mat[0] = vector<int>(capacidad+1,0);
    //llenar de 0s la primera columna
    for(int i=0; i <= kilos.size(); i++){
        mat[i][0] = 0;
    }
    //Algoritmo de solucion
    for (int i = 1; i <= capacidad; i++) {
        for(int j = 1; j <= kilos.size(); j++){
            if(kilos[j-1] <= i)
                mat[j][i] = max(1+mat[j-1][i-kilos[j-1]],mat[j-1][i]);
            else
                mat[j][i] = mat[j-1][i];
        }
    }

    return mat[kilos.size()][capacidad];
}




int main()
{
    vector<int> capacidad = {12,10,6,18,360,360,1360};
    vector<vector<int>> kilos = {  {1,2,5},
                                   {1,3,4},
                                   {1,3,4},
                                   {1,3,5,7},
                                   {1,2,3,4,5,6,7,8,9},
                                   {1,2,5,7,11,13},
                                   {1,2,5,7,11,13}};
    //Respuestas: 3,3,2,4,40,28,106
    for(int i = 0; i< capacidad.size();i++)
        cout<<mochilaDinamica(capacidad[i],kilos[i])<<endl;

    return 0;
}


