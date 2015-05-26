#include <stdio.h>
#include <stdlib.h>

const int MAX_VER = 20000;

int vertices[MAX_VER];

int arestas[MAX_VER][MAX_VER];
int dist[MAX_VER];
int grau[MAX_VER];

void buildGraph(int ver, int n_are, FILE *out);
void saveGraph(int ver, int are, FILE *out);

int main(int argc, char **argv) {

    FILE *out = fopen("ger_in.txt", "w");

    int ver, n_are;
    printf("Entre com a quantidade de vertices\n");
    scanf("%d", &ver);

    buildGraph(ver, n_are,  out);

    return 0;
}

void saveGraph(int ver, int are, FILE *out){
    int i, j;
    fprintf(out, "%d %d\n", ver, are);
    for (i=0; i<ver; i++){
        for(j=0; j<ver; j++){
            if(arestas[i][j]){
                fprintf(out, "%d %d %d\n", i, j, arestas[i][j]);
            }
        }
    }
}

void buildGraph(int ver, int n_are, FILE *out) {
    int dest, custo, i, j, are, cont=0;
    for (i = 0; i < ver; i++) {
        are = (ver*(ver-1));
        for (j=0; j < ver; j++) {
            if(i!=j){
                custo = (rand() % 1000)+1;
                // custo = custo+1;
                arestas[i][j] = custo;
            }
            //arestas[dest][i] = custo;
            // grau[i]++;
            // grau[dest]++;
            // cont++;
        }
    }
    saveGraph(ver, are, out);
}
