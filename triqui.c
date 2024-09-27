/*
- Autor: Ing(c) Burbano Rodriguez Angel Gabriel
- Nombre del lenguaje utilizado: C
- Versión del lenguaje utilizado: C11
- Versión del compilador utilizado: GCC 6.3.0
- Versión del S.O: Windows 10 Pro Versión 22H2
- Descripcion del programa: Este programa consiste en un algoritmo para jugar el juego del triqui con solo string.
- Salvedad: si se ingresa un dato que no sea un entero, no garantizamos los resultados.
*/

#include<stdio.h>
#include <ctype.h>

/*
Función PrintTable que imprime el tablero de triqui
- table: array de caracteres que representa el tablero
*/
void PrintTable(char table[]) {
    printf("\n %c | %c | %c \n---+---+---\n %c | %c | %c \n---+---+---\n %c | %c | %c \n", 
           table[0], table[1], table[2], table[3], table[4], table[5], table[6], table[7], table[8]);
}

/*
Función CheckWin que verifica todas las combinaciones ganadoras
- table: array de caracteres que representa el tablero
*/
int CheckWin(char table[]) {
    int lines[8][3] = { {0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6} };
    for (int i = 0; i < 8; i++){
        if (table[lines[i][0]] == table[lines[i][1]] && table[lines[i][1]] == table[lines[i][2]] && table[lines[i][0]] != ' '){
            return 1;
        }
    }
    return 0;
}

int main() {

    //Variable game que guardará todo el juego del triqui
    char game[] = "123456789";

    //Variable turn que guardará el turno del jugador
    int turn = 1;

    PrintTable(game);

    for (int i = 0; i < 9; i++) {
        // Variable answer que guardará la casilla elegida
        int answer;
        printf("\nJugador %i: Ingrese número de casilla: ", turn);
        scanf("%i", &answer);
        answer--; 

        if (answer < 0 || answer > 8) {
            printf("\nCasilla inválida\n");
            i--;
        }else if(!isdigit(game[answer])){
            printf("\nCasilla ya jugada\n");
            i--;
        } else {
            game[answer] = (turn == 1) ? 'X' : 'O';
            PrintTable(game);
            if (CheckWin(game)) {
                printf("\nJugador %i ha ganado!", turn);
                break;
            }
            turn = (turn == 1) ? 2 : 1;
        }
    }

    if (!CheckWin(game))
        printf("\nEmpate\n");

    return 0;
}