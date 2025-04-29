#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {
	
template<typename T>
concept Sortable = requires(T& t) { 
    {t < t} -> std::convertible_to<bool>;}; // il tipo T deve supportare l'operazione < e il risultato dell'operazione deve poter essere convertito in bool

template<Sortable T>

// BUBBLE SORT
void BubbleSort(std::vector<T>& v)
{
	const unsigned int n = v.size();
	for (unsigned int i=0; i<n-1; i++)
	{
		for (unsigned int j=i+1; j<n; j++)
		{
			if (v[j] < v[i]) // se l'elemento in posizione j-esima è minore dell'elemento in posizione i-esima allora li inverto
			{
				// swap
			    T tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}	
	}	
}	

template<Sortable T>

//HEAP SORT
void HeapSort(std::vector<T>& v) 
{
    const unsigned int n = v.size();

    // Fase di costruzione dell'heap (max-heap) (ogni nodo padre è maggiore dei suoi figli)
    for (int i = n / 2 - 1; i >= 0; i--) { //partiamo dai nodi non foglia 
        unsigned int parent = i;
        while (true) {
            unsigned int sx = 2 * parent + 1; // indice figlio sx
            unsigned int dx = 2 * parent + 2; // indice figlio dx
            unsigned int max = parent;

            if (sx < n && v[sx] > v[max]) // confronta padre e figlio sx
                max = sx; 

            if (dx < n && v[dx] > v[max]) //confronta padre e figlio dx
                max = dx;

            if (max == parent) // se il padre è il maggiore termina il ciclo
                break;
            //swap // se il padre non è il maggiore lo scambia con quale dei due figli è maggiore
            T tmp = v[parent];
            v[parent] = v[max];
			v[max] = tmp;
            parent = max;
        }
    }

    for (int i = n - 1; i > 0; i--) {
		// swap         // Sposta la radice (massimo) alla fine
		T tmp = v[0];
		v[0] = v[i];
		v[i] = tmp;

        int parent = 0;
        while (true) { //applichiamo lo stesso metodo sulla parte non ordinata
            int sx = 2 * parent + 1;
            int dx = 2 * parent + 2;
            int max = parent;

            if (sx < i && v[sx] > v[max])
                max = sx;

            if (dx < i && v[dx] > v[max])
                max = dx;

            if (max == parent)
                break;

            T tmp = v[parent];
            v[parent] = v[max];
			v[max] = tmp; 
            parent = max;
        }
    }
}

}	

