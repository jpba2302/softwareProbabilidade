#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* FUNÇÃO PARA CALCULAR O FATORIAL DE UM NÚMERO
recebe um número de elementos e retorna o fatorial dele.
*/

int fatorial (int elementos) {
    int permutacoes = 1;
    for (int i = elementos;i > 0;i--) {
        permutacoes = permutacoes * i;
    }
    return permutacoes;
}

/* FUNÇÃO PARA LER UM NÚMERO INTEIRO MAIOR QUE ZERO
retorna um inteiro maior que zero, ou caso inválido retorna -1
*/

int leNumero () {
    int aux;
    scanf("%d",&aux);
    if (aux <= 0) {
        return -1;
    }
    return aux;
}

int main() {

    int opcao = -1;
    int elementos;
    int resultado;
    int aux, aux2, aux3;
    printf("=============SOFTWARE DE CÁLCULOS DE PROBABILIDADE===============\n");

    while (opcao != 0) {
        printf("\n===========MENU DE OPÇÕES=============\n");
        printf("1- Calcular permutação\n");
        printf("2- Calcular combinação\n");
        printf("3- Calcular arranjo\n");
        printf("0- Encerrar programa\n");
        printf("\nSELECIONE SUA OPÇÃO: ");
        scanf("%d",&opcao);
        switch (opcao) {

            case 1 :
                printf("\n==========CALCULAR PERMUTAÇÃO=============\n");
                printf("Digite quantos elementos tem o conjunto: ");
                elementos = leNumero();
                    if (elementos == -1) {
                        printf("\nINSIRA UM NÚMERO MAIOR QUE ZERO\n");
                        break;
                    }
                    printf("Digite quantos elementos diferentes se repetem: ");
                    aux = leNumero();
                    if (aux != -1) {
                        aux3 = 1;
                        for (int i = 0;i < aux;i++) {
                            printf("Digite quantas vezes o elemento %d se repete: ",i + 1);
                            aux2 = leNumero();
                            if (aux2 == -1) {
                                printf("\nNÚMERO INVÁLIDO, TENTE NOVAMENTE\n");
                                i--;
                            }
                            aux2 = fatorial(aux2);
                            aux3 = aux3 * aux2;
                        }
                        resultado = fatorial(elementos) / aux3;
                        printf("\nO número de permutações com repetição que podem ser feitos com %d elementos é: %d\n",elementos, resultado);
                    } else {
                        resultado = fatorial(elementos);
                        printf("\nO número de permutações simples que podem ser feitos com %d elementos é: %d\n",elementos, resultado);
                        break;
                    }
                break;
            case 2 :
                printf("\n==============CALCULAR COMBINAÇÃO=================\n");
                printf("Digite o número de elementos: ");
                elementos = leNumero();
                if (elementos == -1) {
                    printf("\nDIGITE UM NÚMERO MAIOR QUE 0\n");
                }
                printf("Digite quantos elementos tem as combinações que você quer fazer: ");
                aux = leNumero();
                if (aux == -1) {
                    aux = 0;
                }
                printf("Os elementos podem ser repetidos?\n");
                printf("\n1- Sim\n0 - Não\n");
                printf("\nDigite sua opção: ");
                opcao = leNumero();
                if (opcao > 0) {
                    resultado = fatorial((elementos + aux - 1)) / (fatorial(aux) * fatorial((elementos - 1)));
                } else {
                    resultado = fatorial(elementos) / (fatorial(aux) * fatorial(elementos - aux));
                }
                opcao = -1;
                printf("Você pode formar %d combinações diferentes de %d elementos\n",resultado, aux);
                break;
            case 3 :
                printf("\n============CALCULAR ARRANJO==============\n");
                printf("Digite o número de elementos: ");
                elementos = leNumero();
                if (elementos == -1) {
                    printf("\nINSIRA UM NÚMERO MAIOR QUE 0\n");
                    break;
                }
                printf("Digite quantos elementos você quer no arranjo: ");
                aux = leNumero();
                if (aux == -1) {
                    printf("\nINSIRA UM NÚMERO MAIOR QUE 0\n");
                    break;
                }
                printf("Algum elemento se repete?\n");
                printf("\n1- Sim\n0- Não\n");
                printf("\nDigite sua opção: ");
                opcao = leNumero();
                if (opcao <= 0) {
                    resultado = (fatorial(elementos) / fatorial((elementos - aux)));
                } else {
                    resultado = pow(elementos, aux);
                }
                printf("O número de arranjos de %d elementos que você pode formar com %d elementos é: %d\n", aux, elementos, resultado);
                opcao = -1;

                break;
            default :
                if (opcao != 0) {
                    printf("\nOPÇÃO INVÁLIDA, TENTE DE NOVO\n");
                }
        }
    }

    printf("\n==============FIM DO PROGRAMA=================\n");

    return 0;
}
