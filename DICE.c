/*** includes ***/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//typedef unsigned int u2;

/*** prototypes ***/

int inputSides (int *sides);
int inputMods (int *mods);
int inputNumRolls(int *numRolls);
int roll (int sides, int mods, int numRolls);

/*** dice data ***/

typedef struct {
  int sides;
	int numRolls;
	int mods;
} dice;

dice D;

/*** main function ***/

int main() {
srand(time(NULL));
dice *ptr;
ptr = &D;

int count = -1;
  
  while(count != 0) {
    printf("--- Dice Board ---\n");
    printf("1 - Sides\n2 - Mods\n3 - No. of Dice\n4 - Roll Dice\n0 - Close Program\n");
    printf("Select your option: ");
    scanf("%d", &count);

    if (count < 0 || count > 4) {
      printf("Invalid options. Enter a number from the selection.\n");
    } else if (count == 1) {
        inputSides(&ptr -> sides);
    } else if (count == 2) {
        inputMods(&ptr -> mods);
    } else if (count == 3) {
        inputNumRolls(&ptr -> numRolls);
    } else if (count == 4) {
        roll(ptr -> sides, ptr -> mods, ptr -> numRolls);
    } else if (count == 0) {
        printf("Program closed.\n");
    }
  
  }

return 0;}

/*** other functions ***/

int inputSides (int *sides) {
  printf("Input number of sides: ");
  scanf("%d", sides);
}

int inputMods (int *mods) {
  printf("Input calculated modifiers: ");
  scanf("%d", mods);
}

int inputNumRolls (int *numRolls) {
  printf("Input number of rolled dice: ");
  scanf("%d", numRolls);
}

int roll (int sides, int mods, int numRolls) {
  if (mods > 0) { 
    printf("Rolling: %dd%d + %d\n", numRolls, sides, mods);
  } else if (mods < 0) {
    printf("Rolling: %dd%d - %d\n", numRolls, sides, -mods);
  } else {
    printf("Rolling: %dd%d\n", numRolls, sides);
  }
  
 for (int i = 0; i < numRolls; i++){ 
    int calc = rand()%(sides) + 1 + (mods);
    printf("%d ", calc);
  }
printf("\n");
}

