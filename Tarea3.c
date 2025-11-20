/*Schrader Rodriguez Luis Antonio
Proyecto Final*/

#include <stdio.h>

void leerVotos();
void calcularVotos();
void calcularGanador();

int voto1[100], voto2[100], voto3[100];
int totalOyentes;
int puntosCancion[10];
int cancion1, cancion2;
int puntosOyente[100];

void main()
{
    int i;

    leerVotos();   
    calcularVotos();
    calcularGanador();
}
/*Tarea 1*/

void leerVotos()
{
    int c1, c2, c3;
    int i = 0;

    printf("Concurso de radio\n");
    printf("Introduce 3 canciones por oyente (escoje del 0 al 9). Para terminar teclea -1.\n\n");

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

/*Tarea 2*/

void calcularVotos()
{
    int i;

    for (i = 0; i < 10; i++)
    {
        puntosCancion[i] = 0;
    }

    for (i = 0; i < totalOyentes; i++)
    {
        puntosCancion[voto1[i]] += 3;
        puntosCancion[voto2[i]] += 2;
        puntosCancion[voto3[i]] += 1;
    }

     printf("\nPuntaje de cada cancion:\n");
    for (i = 0; i < 10; i++)
    {
        printf("Cancion %d: %d puntos\n", i, puntosCancion[i]);
    }

    cancion1 = 0;
    for (i = 1; i < 10; i++)
    {
        if (puntosCancion[i] > puntosCancion[cancion1])
        {
            cancion1 = i;
        }
    }

    if (cancion1 == 0)
        cancion2 = 1;
    else
        cancion2 = 0;

    for (i = 0; i < 10; i++)
    {
        if (i != cancion1)
        {
            if (puntosCancion[i] > puntosCancion[cancion2])
            {
                cancion2 = i;
            }
        }
    }

    printf("\nLa cancion mas votada fue: %d\n", cancion1);
    printf("La 2da cancion mas votada: %d\n", cancion2);
}

/*Tarea 3*/

void calcularGanador()
{
    int i;
    int tiene1, tiene2;
    int ganador = 0;
    int maxPuntos = -1;

    printf("\nPuntos de cada oyente:\n");

    for (i = 0; i < totalOyentes; i++)
    {
        tiene1 = 0;
        tiene2 = 0;
        puntosOyente[i] = 0;

        if (voto1[i] == cancion1 || voto2[i] == cancion1 || voto3[i] == cancion1)
        {
            puntosOyente[i] += 30;
            tiene1 = 1;
        }

        if (voto1[i] == cancion2 || voto2[i] == cancion2 || voto3[i] == cancion2)
        {
            puntosOyente[i] += 20;
            tiene2 = 1;
        }

        if (tiene1 == 1 && tiene2 == 1)
        {
            puntosOyente[i] += 10;
        }

        printf("Oyente %d: %d puntos\n", i, puntosOyente[i]);

        if (puntosOyente[i] > maxPuntos)
        {
            maxPuntos = puntosOyente[i];
            ganador = i;
        }
    }

    printf("\nEl ganador es el oyente numero %d con %d puntos.\n", ganador, maxPuntos);
}
