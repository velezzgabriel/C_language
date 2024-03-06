
#include <stdio.h>

struct medicion {
    unsigned short anio;
    unsigned char mes;
    unsigned char dia;
    float temperatura;
    unsigned char uv;
    unsigned char viento;
};

void print_medicion(struct medicion *medicions) {
    printf("Fecha: %d-%d-%d, Registro %.1f°C. UV %d, Viento %d km/h\n",
           medicions->anio, medicions->mes, medicions->dia,
           medicions->temperatura, medicions->uv, medicions->viento);
}

int main(int argc, char** argv){
    struct medicion medidas[] = {
    {
        .anio = 2020, .mes = 11, .dia = 9,
        .temperatura = 15, .uv = 4, .viento = 15
    },
    {
        .anio = 2020, .mes = 11, .dia = 8,
        .temperatura = 10, .uv = 2, .viento = 25
    },
    {
        .anio = 2020, .mes = 11, .dia = 7,
        .temperatura = 20, .uv = 5, .viento = 12
    },
    {
        .anio = 2020, .mes = 7, .dia = 24,
        .temperatura = 40, .uv = 8, .viento = 0
    },
    {
        .anio = 2020, .mes = 1, .dia = 3,
        .temperatura = -3, .uv = 1, .viento = 80
    }    
};

    FILE *fp = fopen("temperatura.bin", "w");
    
    int total = fwrite(&medidas, sizeof(struct medicion), 5 , fp);
    if (total != 5){
        printf("algo ha salido mal \n");
    }
    fclose(fp);
   
    print_medicion(&medidas[1]);

}

