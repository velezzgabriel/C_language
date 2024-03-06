

////////////////  MANIPULACION DE BITS
/*
X =     1 0 0 1 1 1 0 0     156
NOT(X)  0 1 1 0 0 0 1 1     99

a =         1 0 1 1 1 0 0 1     185
b =         0 0 1 1 0 1 0 0     52

AND(a,b) =  0 0 1 1 0 0 0 0     48     -> a & b    
OR(a,b)  =  1 0 1 1 1 1 0 1     189    -> a | b
XOR (a,b)=  1 0 0 0 1 1 0 1     141    -> a ^ b
*/


///////////////// MASCARAS DE BITS
/*
char        7 6 5 4 3 2 1 0

7 azul      1 0 0 0 0 0 0 0     ->  128
6 verde     0 1 0 0 0 0 0 0     ->  64
5 rojo      0 0 1 0 0 0 0 0     ->  32
4 naranja   0 0 0 1 0 0 0 0     ->  16
3 amarillo  0 0 0 0 1 0 0 0     ->  8   
2 pardo     0 0 0 0 0 1 0 0     ->  4
1  blanco   0 0 0 0 0 0 1 0     ->  2
0 negro     0 0 0 0 0 0 0 1     ->  1

x OR 0 = x
0 OR 0 = 0
0 OR 1 = 1

x AND 1 = x
0 AND 1 = 0
1 AND 1 = 1


operacion( azul | verde | pardo)
1 0 0 0 0 0 0 0  |
0 1 0 0 0 0 0 0  |   
0 0 0 0 0 1 0 0  |
------------------
1 1 0 0 0 1 0 0     --> 196


--------> en còdigo
* operador desplazamiento (<<) o (>>)
x=          1 0 1 1 0 0 1 0
x << 1      0 1 1 0 0 1 0 0
x << 2      1 1 0 0 1 0 0 0 
x >> 1      0 1 0 1 1 0 0 1
x >> 2      0 0 1 0 1 1 0 0

#define AZUL        1 << 7
#define VERDE       1 << 6
#define ROJO        1 << 5
#define NARANJA     1 << 4
#define AMARILLO    1 << 3
#define PARDO       1 << 2
#define BLANCO      1 << 1
#define NEGRO       1 << 0


---------> para verificar si un COLOR está activo, uso AND()
            tomo el input & el COLOR que quiero verificar.

AND(input, COLOR)
1 1 1 0 0 1 0 1     input
0 0 0 0 1 0 0 0     COLOR (amarillo) que quiero verificar
-----------------
0 0 0 0 0 0 0 0     amarillo NO está encendido


1 1 1 0 0 1 0 1     input
0 0 0 0 0 1 0 0     COLOR (pardo) que quiero verificar
-----------------
0 0 0 0 0 1 0 0     pardo SI está encendido


---------> para APAGAR un bit uso AND() con el complemento del valor a apagar:
1 1 1 0 0 1 0 1      input
1 0 1 1 1 1 1 1     ~(VERDE) (complemento) OJO!! Sin el parentesis quedaria ~1 << 6, diferente de ~(1<<6)
-----------------
1 0 1 0 0 1 0 1      ya se apagó


---------->  CODIGO 
void operacion (unsigned char colores) {
    if (colores & AZUL){
        printf("AZUL\n");
    }
    if (colores & VERDE){
        printf("VERDE\n");
    }
    if (colores & ROJO){
        printf("ROJO\n");
    }
    if (colores & NARANJA){
        printf("NARANJA\n");
    }
    if (colores & PARDO){
        printf("PARDO\n");
    }
    if (colores & AMARILLO){
        printf("AMARILLO\n");
    }
    if (colores & BLANCO){
        printf("BLANCO\n");
    }
    if (colores & NEGRO){
        printf("NEGRO\n");
    }
}

int main(){
    operacion (azul | verde | pardo)
}

*/


////////////////////////////////////////////////////////////////////
                //      EXERCISES       //



//--> Setting a specific bit in an integer to 1 without affecting the other bits.
unsigned int setBit(unsigned int num, int bit) {
    return num | bit;
}

int main() {
    unsigned int number = 5; // Binary: 0101
    int bitToSet = 2;  // Binary: 0010
    unsigned int result = setBit(number, bitToSet); // Result: 0111 (7 in decimal)
    printf("Result: %u\n", result);
    return 0;
}


//--> Clearing a specific bit in an integer to 0 without affecting the other bits.
unsigned int clearBit(unsigned int num, int bit) {
    return num & ~bit;
}

int main() {
    unsigned int number = 7; // Binary: 0111
    int bitToClear = 2; //      Binary: 0010 Clear the third bit (from the right)
    unsigned int result = clearBit(number, bitToClear); // Result: 0101 (5 in decimal)
    printf("Result: %u\n", result);
    return 0;
}



//--> Checking the value of a specific bit in an integer.
int isBitSet(unsigned int num, int bit) {
    return (num & (1 << bit)) != 0;
}

int main() {
    unsigned int number = 5; // Binary: 0101
    int bitToCheck = 2; // index two from the right, (0-based index).
    int result = isBitSet(number, bitToCheck); // Result: 1 (true)
    printf("Result: %d\n", result);
    return 0;
}



//-->  creating bit masks
unsigned int createBitMask(int startBit, int endBit) {
    unsigned int mask = (1u << (endBit - startBit + 1)) - 1;
    return mask << startBit;
}

int main() {
    int startBit = 2;
    int endBit = 4;
    unsigned int mask = createBitMask(startBit, endBit); // Creates a mask for bits 2 to 4 (0011100)
    printf("Mask: %u\n", mask);
    return 0;
}



// --> extract each of the bytes of a byte
// int main() {
//     int byte = 4; 

//  (0-based index) starting from the right!!!!!!!

//     int bit0 = (byte >> 0) & 1;
//     int bit1 = (byte >> 1) & 1;
//     int bit2 = (byte >> 2) & 1;
//     int bit3 = (byte >> 3) & 1;
//     int bit4 = (byte >> 4) & 1;
//     int bit5 = (byte >> 5) & 1;
//     int bit6 = (byte >> 6) & 1;
//     int bit7 = (byte >> 7) & 1;

//     printf("Bit 0: %d\n", bit0);
//     printf("Bit 1: %d\n", bit1);
//     printf("Bit 2: %d\n", bit2);
//     printf("Bit 3: %d\n", bit3);
//     printf("Bit 4: %d\n", bit4);
//     printf("Bit 5: %d\n", bit5);
//     printf("Bit 6: %d\n", bit6);
//     printf("Bit 7: %d\n", bit7);

//     return 0;
// }

