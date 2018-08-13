#include<iostream>
#include <list>
#include <stack>
using namespace std;


class Plato {
    int V;    // No. de tareas (vértices)

    //Apunta a la lista de adyacencia
    list<int> *adj;

    void topologicalSortaux(int v, bool visited[], stack<int> &Stack);
public:
    Plato(int V);   // Constructor

     // agrega dependencia de tareas en el Plato
    void dependencia(int v, int w);

    // muestra la receta completa
    void receta();
};

Plato::Plato(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Plato::dependencia(int v, int w)
{
    adj[v].push_back(w); // Agrega la dependencia de w con v
}

// función auxiliar
void Plato::topologicalSortaux(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true; //marca como visitado

    // va a todas las tareas adyacentes
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortaux(*i, visited, Stack);

    // Push current vertex to stack which stores result
    Stack.push(v);
}

// Función para recorrer el grafo en orden
// topologicalSortaux()
void Plato::receta()
{
    stack<int> Stack;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortaux(i, visited, Stack);

    // Print contents of stack
    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

// Driver program to test above functions
int main(const char * argv[])
{
    string instruccion, ij;
    int i, j, n, d, ki, kj;
    string enede = getline(cin, instruccion);
    n = enede[0];
    d = enede[2];
    Plato p(n);

    for(i=0; i < n; i++){
      //agregar a un arreglo el tiempo de cada tarea... o como otro elemento a la lista de adjacency
      getline(cin, instruccion);
      //falta agregar los tiempos
    }

    for(i=0; j < d; j++){

      //leer la linea y agregar la dependencia entre los arcos
      ij = getline(cin, instruccion);
      ki = ij[0];
      kj = ij[0];
      p.dependencia  (ki, kj);

    }


    //idea --> :c hacer un arreglo con el valor de tiempo de cada tarea... eso, o darle peso a los arcos, que no suena tan bonito porque el arreglo sería O(1)

    // Create a Plato given in the above diagram

    cout << " \n";
    p.receta();

    return 0;
}
