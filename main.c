#include <stdio.h>


/* COMO OCORRE A SOMA DE DOIS NÚMEROS UTILIZANDO ESPAÇOS NA MEMÓRIA?
 *
 * Em C podemos acessar espaços de memória através de apontadores.
 * Apontadores frequentemente são utilizados para representar vetores.
 * Um vetor V de N elementos é uma sequência de N espaços na memória onde V
 * aponta para seu primeiro elemento, ou seja, V aponta para o primeiro
 * espaço desta memória.
 * Um vetor V de N elementos do tipo int, por ex., pode ser definido em C como:
 *
 * int V[N]; ou
 *
 * int *V (alocação dinâmica de memória para N elementos);
 *
 * Para acessarmos um elemento V[i] (i < N) deste vetor utilizamos:
 *
 * V[i] ou *(V + i)
 *
 * Note que em ambos os casos temos um apontador V que aponta para um espaço
 * na memória e, em seguida, desloca seu ponteiro 'i' posições na memória para
 * acessar o elemento V[i]. Isto caracteriza uma soma implícita se pudermos
 * manipular 'V' e 'i' convenientemente.
 *
 * Por exemplo, se quisermos somar A = 5 e B = 3 utilizando este algoritmo,
 * fazemos uma manipulação tal que possamos transformar A em um vetor, cujo
 * ponteiro aponta para o espaço de endereço A, deslocando-se B posições na
 * memória e devolvendo o seu ENDEREÇO DE MEMÓRIA (e não o elemento ali armazenado).
 * Assim, temos:
 *
 * &A = 5 (endereço 5), B = 3 (deslocamento de 3 posições) --> &(*(A + B)) = 8
 *
 * No entanto não podemos utilizar um vetor de int pois cada espaço de inteiros
 * possui 4 bytes de memória, resultando numa adição errada.
 * Neste caso utilizamos UM VETOR DE CHAR pois cada espaço de tipo char na memória
 * possui exatamente 1 byte, resultando numa adição precisa.
 *
 * A função 'h4x0r_sum' abaixo faz exatamente isto: Recebe dois números 'A' e 'B' tais
 * que A é manipulado para se tornar um ponteiro (C) que aponta para o endereço &A
 * do tipo char, ou seja, se A = 5 (endereço) então:
 *
 * char *A aponta para o endereço 5 numa memória de char elementos.
 * Se deslocarmos A em B posições (como num vetor, explicado acima) e, por fim,
 * acessarmos o endereço de memória do elemento resultante obtemos a soma implícita.
 * Em outras palavras:
 *
 * Se &A = 5 é um ponteiro de char e B = 3 é um inteiro.
 * Então &(*(A + B)) = 8
 *
 * A função 'h4x0r_sum' é implementada abaixo.
 * */


int h4x0r_sum(int A, int B) {
    // 'C' converte 'A' (casting) para um apontador de memória
    // cujo endereço, numericamente, vale 'A'.
    char *C = (char*) A;

    // A soma ocorre aqui, conforme descrito acima.
    // Note que a notação &C[B] equivale a &(*(C + B)) explicado acima,
    // com um casting para int.
    return (int) &C[B];
}


int main() {

    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("Soma: %d\n", h4x0r_sum(a, b));
    return 0;
}
