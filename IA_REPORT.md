Felipe Martins Maia - 646

#include <iostream> 
#include <iomanip> 
using namespace std; 
 
 
float calcular_confiabilidade(float probabilidades[], int tamanho)  
{ 
    float confiabilidade = 0.0; 
 
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
 
 
toda resposta minha esta dando 0, sabe me explicar onde esta o erro?









O erro está nesta linha:

float confiabilidade = 0.0;

Você está começando a multiplicação com zero. Como a função faz:

confiabilidade = confiabilidade * probabilidades[i];

a primeira conta sempre será algo como:

0.0 × 0.98 = 0.0

Depois:

0.0 × 0.95 = 0.0
0.0 × 0.90 = 0.0

Por isso o resultado sempre será 0.

Como corrigir

Troque:

float confiabilidade = 0.0;

por:

float confiabilidade = 1.0;

Porque, para começar uma multiplicação, usamos 1:

1.0 × 0.98 × 0.95 × 0.90 = 0.8379

Então a função corrigida fica:

float calcular_confiabilidade(float probabilidades[], int tamanho)  
{ 
    float confiabilidade = 1.0; 
 
    for (int i = 0; i < tamanho; i++)  
    { 
        confiabilidade = confiabilidade * probabilidades[i]; 
    } 
 
    return confiabilidade; 
}

Esse é o único erro que está fazendo o programa retornar 0 nesse código. O restante da lógica da função está de acordo com o que o exercício pede.












A IA me respondeu exatamente o que eu estava procurando. A resposta me ajudou a identificar o motivo pelo qual o programa estava retornando 0 mesmo com as probabilidades preenchidas corretamente, o problema estava na inicialização da variável confiabilidade, que havia sido definida como 0.0.
Com isso aprendi que em cálculos que envolvem multiplicação acumulativa, é importante iniciar a variável com 1, pois qualquer numero multiplicado por 0 é 0.
Resposta muito boa e direta da IA, solucionando e mostrando exatamente onde estava o erro, me ajudou completamente a achar esse erro bobo.
