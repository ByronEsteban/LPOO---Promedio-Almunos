#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char arraymaterias[10][50]; //aca guardamos los nombres de las materias
  float datos[3][20]; //aca guardamos el numero de materia, numero de legajo, y promedio de cada alumno
  int i = 0; //recorre las filas de DATOS para guardar informacion
  int countarray = 0; //subindice que recorre ARRAYMATERIAS
  char materia[50]; //el buffer
  char materia1[50]; //aca guardamos la primer materia que se ingresa por un error
  while (1) { //while de materia
    fflush(stdin); //para vaciar el fgets, esta aca porque sino pone error
    printf("\n////////Ingrese la materia\\\\\\\\\\\\\\\\\ \n");
    printf("---Si quiere salir, ingrese XXX---\n");
    printf("Tu materia: ");
    fgets(materia, 50, stdin); //para ingresar la materia
    if (materia[0] == 'X' && materia[1] == 'X' && materia[2] == 'X') break; //si se ingresa XXX se termina el programa
    strcpy(arraymaterias[countarray], materia); //guardamos la entrada del buffer en el array
    if(countarray == 0) strcpy(materia1, materia); // guardamos la primer materia ingresada
    system("cls");
    printf("Estamos en %s", arraymaterias[countarray]);
    while (1) { //while de numero de legajo
      float prom = 0.00; //variable de los promedios de cada legajo
      int countnotas = 0; //variable que cuenta la cantidad de notas
      int nro_legajo; //variable del numero de legajo
      printf("\nIngrese el numero de legajo del alumno\n");
      printf("---Si quiere salir, ingrese 0---\n");
      printf("Legajo: ");
      while (1) { //while que revisa si el legajo es valido
        scanf("%d", &nro_legajo); //ingresamos el numero de legajo
        if (nro_legajo >= 0) break; //si el legajo es valido sale del while, si no repite
        else printf("-_-_-_-Ingresa un legajo valido-_-_-_-\n");
      }
      if (nro_legajo == 0) break; //para darle al usuario una forma de salir de elejir el legajo
      datos[i][0] = countarray; //guardamos el numero de materia en datos
      datos[i][1] = nro_legajo; //guardamos el numero de legajo en datos
      printf("\nIngrese la nota del alumno %d\n", nro_legajo);
      printf("---Si quiere salir, ingrese -1---\n");
      while (1) { //while de notas
        int nota = 0; //variable que guarda las notas de los alumnos
        while (1) { //while de notas invalidas
          printf("Nota %d: ", countnotas+1);
          scanf("%d", &nota); //elejimos la nota
          if (nota < -1 || nota >= 11) printf("-_-_-_-Ingresa una nota valida-_-_-_-\n"); //delimitamos las notas de las materias
          else break;
        }
        if (nota == -1) break; //le damos una forma de salir de elejir notas al usuario
        prom = prom + nota; //hacemos el promedio
        countnotas++; //sumamos 1 cada vez que ponga una nota
      }
      if(countnotas == 0) printf("Promedio del alumno: %.2f\n", prom); //en el caso que no se ingrese mninguna nota en materia
	  else printf("Promedio del alumno: %.2f\n", prom/countnotas); //si si se ingresaron notas imprime promedio
      datos[i][2] = prom/countnotas; //añadimos a datos el promedio por legajo
      i++; //pasar a la siguiente fila
    }
    countarray++; //le sumamos 1 si elije otra materia
    system("cls"); //para borrar lo puesto en pantalla
  }
  printf("\n");
  float prommateria = 0.00; //promedio de la materia
  int countalumnos = 0; //contamos la cantidad de alumnos
  float max = 0.00; //materia con promedio mas alto
  int maxarray = 0; //sub indice de la nota maxima
  for (int k = 0; k < i; k++) { //imprime la matriz
    countalumnos++; //sumamos 1 cada vez que ingresa un alumno
    int submateria = (int) datos[k][0]; //submateria guarda el numero de materia, lo pasamos a entero asi nos sive de subindice
    if (k == 0 || datos[k][0] != datos[k-1][0]) { //el verificador de que seguimos en la misma materia, comparamos la materia en la que estamos con la anterior
      if(submateria == 0) printf("%s", materia1); //imprimimos el nombre de la primer materia
      //todo esto de materia1 lo hacemos porque sino tira error, es la solucion que encontramos
      else printf("%s", arraymaterias[submateria]); //imprimimos el nombre de las demas materia
      printf("    Legajo   Promedio\n");
    }
    printf("      %.0f       %.2f\n", datos[k][1], datos[k][2]);
    prommateria = prommateria + datos[k][2]; //sumamos a datos el promedio de las materias
    if (datos[k][0] != datos[k+1][0]) { //el verificador de que cambiamos de materia, comparamos la materia de esta fila con la materia de la siguiente fila
      //si entramos significa que cambiamos de materia
      
      printf("El promedio de la materia es %.2f\n", prommateria/countalumnos);
      if ((prommateria/countalumnos) > max) { //compara si el promedio de la materia es el promedio mas alto
        maxarray = submateria; //guardamos en el subindice mas alto submateria
        max = prommateria/countalumnos; // hacemos el promedio mas alto
      }
      countalumnos = 0; //hacemos que countalumnos sea igua la 0 porque el numero de alumnos es por materia, entonces una vez cambiada de materia se reinicia el contador
      prommateria = 0.00; //idem
    }
  }
  if(maxarray == 0) printf("\nLa materia con mayor promedio es %s", materia1); //este if es por si la materia de mayor promedio es la primera
  else printf("\nLa materia con mayor promedio es %s", arraymaterias[maxarray]); //sino imprime la materia de mayor promedio
  return 0;
}
