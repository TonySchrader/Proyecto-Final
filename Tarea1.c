/*Schrader Rodriguez Luis Antonio
Proyecto Final*/

#include <stdio.h>
void leerVotos();

int voto1[100], voto2[100], voto3[100];
int totalOyentes;

void main()
{
    leerVotos();
}

/*tarea 1*/

    void leerVotos()
    {
        int c1, c2, c3; 
        i = 0;

        printf("Concurso de radio\n");
        printf("Introduce 3 canciones por oyente (escoje del 0 al 9). Para que terminar teclea -1.\n\n");

        while (i < 100)
        {
            printf("Oyente %d (3 canciones): ", i);
            scanf("%d", &c1);

            if (c1 == -1)
            break;

            scanf("%d", &c2);
            scanf("%d", &c3);

            voto1[i] = c1;
            voto2[i] = c2;
            voto3[i] = c3;
            i++;
        }

    totalOyentes = i;
    } 
