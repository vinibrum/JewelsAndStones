// Source : https://leetcode.com/problems/jewels-and-stones/
// Author : Vinícius Brum
// Date   : 31-01-2021


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Encontra a quantidade de pedras que também são jóias
//Cada caracter da string jewels representa uma jóia
//Ex.: Input: jewels = "aA", stones = "aAAbbbb"
//     Output: 3
int numJewelsInStones(char *jewels, char *stones){
    int numJewels = 0;
    char c, *p, *p2, *aux;

    while((c = *(jewels++))){
        p2 = strdup(stones);
        aux = p2;
        while((p = strchr(p2, c))){
            numJewels++;
            *p = '\0';
            p++;
            p2 = p;
        }
        free(aux);
    }

    return numJewels;
}

void printResult(char *jewels, char *stones, int numberJewels){
    printf("Jewels: %s\n", jewels);
    printf("Stones: %s\n", stones);
    printf("Number of Jewels in Stones: %d\n", numberJewels);
    printf("\n");
}

int main(){
    char *jewels = "aA";
    char *stones = "aAAbbbb";

    printResult(jewels, stones, numJewelsInStones(jewels, stones));

    jewels = "bcd";
    stones = "cba";

    printResult(jewels, stones, numJewelsInStones(jewels, stones));

    return 0;
}
