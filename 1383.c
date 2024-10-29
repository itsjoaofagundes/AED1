#include <stdio.h>

#define TAMANHO_GRADE 9

int verificar_linha(int grade[TAMANHO_GRADE][TAMANHO_GRADE], int linha) {
    int numeros_usados[TAMANHO_GRADE + 1] = {0};
    
    for (int coluna = 0; coluna < TAMANHO_GRADE; coluna++) {
        int numero = grade[linha][coluna];
        if (numero < 1 || numero > TAMANHO_GRADE || numeros_usados[numero] > 0) {
            return 0;
        }
        numeros_usados[numero]++;
    }
    return 1;
}

int verificar_coluna(int grade[TAMANHO_GRADE][TAMANHO_GRADE], int coluna) {
    int numeros_usados[TAMANHO_GRADE + 1] = {0};
    
    for (int linha = 0; linha < TAMANHO_GRADE; linha++) {
        int numero = grade[linha][coluna];
        if (numero < 1 || numero > TAMANHO_GRADE || numeros_usados[numero] > 0) {
            return 0;
        }
        numeros_usados[numero]++;
    }
    return 1;
}

int verificar_subgrade(int grade[TAMANHO_GRADE][TAMANHO_GRADE], int inicio_linha, int inicio_coluna) {
    int numeros_usados[TAMANHO_GRADE + 1] = {0};
    
    for (int linha = inicio_linha; linha < inicio_linha + 3; linha++) {
        for (int coluna = inicio_coluna; coluna < inicio_coluna + 3; coluna++) {
            int numero = grade[linha][coluna];
            if (numero < 1 || numero > TAMANHO_GRADE || numeros_usados[numero] > 0) {
                return 0;
            }
            numeros_usados[numero]++;
        }
    }
    return 1;
}

int main() {
    int quantidade_instancias;
    scanf("%d", &quantidade_instancias);
    
    for (int instancia = 1; instancia <= quantidade_instancias; instancia++) {
        int grade[TAMANHO_GRADE][TAMANHO_GRADE];
        
        for (int linha = 0; linha < TAMANHO_GRADE; linha++) {
            for (int coluna = 0; coluna < TAMANHO_GRADE; coluna++) {
                scanf("%d", &grade[linha][coluna]);
            }
        }
        
        int eh_sudoku = 1;
        for (int i = 0; i < TAMANHO_GRADE; i++) {
            if (!verificar_linha(grade, i) || !verificar_coluna(grade, i) || !verificar_subgrade(grade, i / 3 * 3, i % 3 * 3)) {
               eh_sudoku = 0;
               break;
            }
        }
        
        printf("Instancia %d\n", instancia);
        printf("%s\n\n", eh_sudoku ? "SIM" : "NAO");
    }
    
    return 0;
}
