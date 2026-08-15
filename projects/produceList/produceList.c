#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum produceType {
  APPLE,
  GRAPE,
  BANANA,
  CORN,
  CARROT,
  BROCCOLI,
  FRUITCOUNT
};

struct Produce {
  enum produceType pt;
  char name[32];
  float price;
  int quantity;
};

struct produceList {
  int capacity;
  int count;
  float total;
  struct Produce * list;
};

//produceList functions
void initProduceList(struct produceList *);
void updateProduceList(struct produceList *, enum produceType, int);
void addProduceList(struct produceList *);
void totalProduceList(struct produceList *);
void saveProduceList(struct produceList *);
void printProduceList(struct produceList *);
void freeProduceList(struct produceList *);

//Produce functions
void initProduce(struct Produce *, enum produceType, int);

int main() {


  struct produceList list;
  initProduceList(&list);
  

  int choice = getchar();
  int isSaved = 0;

  while(getchar() != '3') {
  printf("\033[2J\033[H");
  printf("Produce List App :D\n");
  printf("add(1) save(2) quit(3)\n");

  printProduceList(&list);
  totalProduceList(&list);
  choice = getchar();
  
  switch(choice) {
      case '1':
        addProduceList(&list);
        break;
      case '2':
        saveProduceList(&list);
        isSaved = 1;
        break;
      case '3':
        goto end;
        break;
    }
  }

  end:
  if(isSaved > 0)
    printf("\nProduce List Saved!\n");
  freeProduceList(&list);
  return 0;
}
void initProduceList(struct produceList * pl) {

  pl->capacity = 1;
  pl->count = 0;
  pl->total = 0.0f;
  pl->list = malloc(sizeof(struct Produce));
  
}

void updateProduceList(struct produceList * pl, enum produceType pt, int quantity) {
  
  initProduce(&pl->list[pl->count], pt, quantity);
  pl->capacity++;
  pl->count++;

  pl->list = realloc(pl->list, pl->capacity * sizeof(struct Produce));

}

void addProduceList(struct produceList * pl) {

choiceProduce:
  printf("Apple (0)\n");
  printf("Grape (1)\n");
  printf("Banana (2)\n");
  printf("Corn (3)\n");
  printf("Carrot (4)\n");
  printf("Broccoli (5)\n");
  printf("Please enter a Fruit: ");
  int choiceProduce;
  scanf("%d", &choiceProduce);
  if(choiceProduce < 0 || choiceProduce > 5) {
    printf("please enter a valid selection\n");
    goto choiceProduce;
  }

// choiceQuantity:
  printf("\nenter the Quanity: ");
  int choiceQuantity;
  scanf("%d", &choiceQuantity);

  updateProduceList(pl, choiceProduce, choiceQuantity);

  
}

void totalProduceList(struct produceList * pl) {
  pl->total = 0;
  for(int i = 0; i < pl->count; i++) {
    pl->total += pl->list[i].price * pl->list[i].quantity;
  }
  printf("total : ------\n");
  printf("[ %lf ]\n", pl->total);
}

void saveProduceList(struct produceList * pl) {
  FILE * file = fopen("produceList.txt", "w");
  
  fprintf(file, "Produce List :\n");
  fprintf(file, "--------------\n");
  fprintf(file, "[#][Name]\t[Price]\t[Quantity]\n");

  for(int i = 0; i < pl->count; i++) {
    fprintf(file, "[%d]%s\t%.2lf\t%d\n", i, pl->list[i].name, pl->list[i].price, pl->list[i].quantity);
  }

  fclose(file);
  
}

void printProduceList(struct produceList * pl) {

  printf("[Grocery List]\n");
  printf("[#][Name]\t[Price]\t[Quantity]\n");
  for(int i = 0; i < pl->count; i++) {
    printf("[%d]%s\t%.2lf\t%d\n", i, pl->list[i].name, pl->list[i].price, pl->list[i].quantity);
  }
  
}

void freeProduceList(struct produceList * pl) {
  free(pl->list);
}

void initProduce(struct Produce * p, enum produceType pt, int quantity) {
  
  p->pt = pt;
  p->quantity = quantity;

  switch(p->pt) {
    case APPLE:
      p->price = 0.99;    
      strcpy(p->name, "apple");
      break;
    case GRAPE:
      p->price = 0.02;    
      strcpy(p->name, "grape");
      break;
    case BANANA:
      p->price = 0.33;    
      strcpy(p->name, "banana");
      break;
    case CORN:
      p->price = 0.25;    
      strcpy(p->name, "corn");
      break;
    case CARROT:
      p->price = 0.17;    
      strcpy(p->name, "carrot");
      break;
    case BROCCOLI:  
      p->price = 0.40;    
      strcpy(p->name, "broccoli");
      break;
    case FRUITCOUNT:
      break;
  }
}
