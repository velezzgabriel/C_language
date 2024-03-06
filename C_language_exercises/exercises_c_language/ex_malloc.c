////////////////  VLA : Variable Length Array
// VLA mueren una vez salgamos de la funcion donde los hemos declarado, dado que son variables locales.
// solamente disponibles en C99, NO en C89.
// VLA muy grandes tienden a fallar. 

int main (){
    int i =40;
    float temperature[i];
} 


//////////////////// MEMORIA DINAMICA

////////////////  MALLOC
// Memoria debe ser liberada una vez no se necesite más. 
//Si alocamos memoria fuera de una función, se libera automaticamente una vez el script finaliza.
//Si alocamos memoria dentro de una función, esta debe ser liberada manualmente.  
// Devuelve NULL cuando falla. NULL se encuentra en stdio.h
// Devuelve puntero de tipo VOID

float* valores = (float*) malloc(4000 * sizeof(float));

// input from user
int main() {
    printf ("Cuantos elementos quieres almacenar??");
    int longitud;
    scanf("%d", &longitud);
    float* valores = (float*) malloc(longitud * sizeof(float));

    if (valores == NULL){
        printf("no tienes tanta memoria");
        return 1;
    }

    int i;
    for (i=0 ; i<longitud; i++){
        valores[i] = "valor en cada posicion del array";
    }
    
// despues de liberar memoria no podemos acceder a la variable a menos hagamos MALLOC nuevamente
    free (valores);
    
    return 0;
}