#include <iostream>
#include <iomanip>
using namespace std;


float calcular_confiabilidade(float probabilidades[], int tamanho) 
{
    float confiabilidade = 1.0;

    for (int i = 0; i < tamanho; i++) 
    {
        
        confiabilidade = confiabilidade * probabilidades[i];
    
    }

    return confiabilidade;
}

int main() 
{
    int n;

    cout << "Digite a quantidade de componentes do sistema: ";
    cin >> n;

    float probabilidades[n];

    for (int i = 0; i < n; i++) 
    {
        cout << "Digite a probabilidade do componente " << i + 1 << " (ex: 0.95): ";
        cin >> probabilidades[i];}



    float resultado = calcular_confiabilidade(probabilidades, n);

    cout << fixed << setprecision(4);

    cout << "Confiabilidade total do sistema: " << resultado;

    cout << " (" << resultado * 100 << "%)" << endl;

  

    return 0;
}
