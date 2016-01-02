#include <stdio.h>

#define MEMORY_SIZE 100

char* welcome();
void azzera_memory(int memory[], int size);
void memory_dump(int memory[], int size);
void cpu_reset(int *accumulator, int *instructionCounter, int *instructionRegister, int *operationCode, int *operand);
void cpu_dump(int accumulator, int instructionCounter, int  instructionRegister,int operationCode, int operand);
void fetch(int memory[], int size, int instructionCounter, int *instructionRegister, int *operationCode, int *operand);

int main (){

	int memory[MEMORY_SIZE];
	int accumulator, instructionCounter, instructionRegister, operationCode, operand;
	
	azzera_memory(memory,MEMORY_SIZE);
	printf("%s",welcome());

	memory[0] = 1007; /* (Legge A) */
	memory[1] = 1008; /* (Legge B) */
	memory[2] = 2007; /* (Carica A nell'accumulatore) */
	memory[3] = 3008; /* (Somma B all'accumulatore) */
	memory[4] = 2109; /* (Memorizza il valore dell'accumulatore */
	memory[5] = 1109; /* (Stampa C) */
	memory[6] = 4300; /* (Halt) */
	memory[7] = 0;    /* (Variabile A) */ 
	memory[8] = 0;    /* (Variabile B) */
	memory[9] = 0;	  /* (Risultato C) */

	memory_dump(memory,MEMORY_SIZE);
        cpu_reset(&accumulator, &instructionCounter, &instructionRegister, &operationCode, &operand);
 	fetch(memory, MEMORY_SIZE, instructionCounter, &instructionRegister, &operationCode, &operand);	
	cpu_dump(accumulator, instructionCounter, instructionRegister, operationCode, operand);

	return 0;
}

char* welcome ()
{
  return "*** Welcome to Simpletron! ***\n"
         "*** Please enter your program one istruction ***\n"
         "*** (or data word) at a time. I will type the ***\n"
         "*** location number and a question mark (?). ***\n"
         "*** You the type the word for that location. ***\n"
         "*** Type the sentiel -99999 to stop entering ***\n"
         "*** your program. ***\n";
}

void azzera_memory(int memory[], int size)
{
	int i;

	for (i=0; i<size; i++) {
		memory[i] = 0;
	}
}

void  memory_dump(int memory[], int size)
{
	int i=0, righe=0,colonne=0;
	printf("Memory: \n");

	putchar('\t');
	for (colonne=0;colonne<10;colonne++){
		printf("   %d\t ", colonne);

	}
	putchar('\n');

	for (i=0; i<size; i++) {
		if (i%10==0) {
			printf("%2d\t", righe);
			righe+=10;
		}
		printf("+%04d\t", memory[i]);

		if ((i+1)%10==0) {
			putchar('\n');
		}
	}
}

void cpu_reset(int *accumulator, int *instructionCounter, int *instructionRegister, int *operationCode, int *operand)
{
  *accumulator=0;
  *instructionCounter=0;
  *instructionRegister=0;
  *operationCode=0;
  *operand=0;
}

void cpu_dump(int accumulator, int instructionCounter, int  instructionRegister, int  operationCode, int operand)
{
  printf("accumulator: +%04d\n"
      "instructionCounter: %02d\n"
      "instructionRegister: +%04d\n"
      "operationCode: %02d\n"
      "operand: %02d\n", accumulator, instructionCounter, instructionRegister, operationCode, operand);
}  


void fetch(int memory[], int size, int instructionCounter, int *instructionRegister, int *operationCode, int *operand)
{
	instructionCounter = 0;
	*instructionRegister = memory[instructionCounter];
	*operationCode = *instructionRegister / 100;
	*operand = *instructionRegister % 100;		
}

