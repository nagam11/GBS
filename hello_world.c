//it provides the print function
#include <stdio.h>
#include <stdlib.h>
//leave one place for NULL
char name[6] = "John";
int age = 20;
int main(int argc, char **argv){
  //d is for signed int and s for string. They are replaced by the params after the string
  printf("Hello, I am %d years old and my name is %s.\n",age,name);
  //Correct way to print a variable
  printf("%s\n",name);
  int arrayXYZ[10];
  int i;
  int *pi;
  int intVar ;
  for (i = 0; i < 10; i++) {
    arrayXYZ[i] = i;
  }
  //pi is a pointer. ArrayXYZ is an int
  //pi = arrayXYZ[1];
  printf("%p\n",pi);
  pi = arrayXYZ;
  printf("%p\n",pi);
  pi = &arrayXYZ[0];
  printf("%p\n",pi);
  intVar = arrayXYZ[8];
  printf("%d\n",intVar);
  intVar = *(arrayXYZ+8);
  printf("%d\n",intVar);
  pi = arrayXYZ;
  printf("%p\n",pi);
  *(pi + 12) = 178;
  printf("%p\n",pi);
  pi[12] = 178;
  printf("%d\n",pi[12]);
  int *array123 = (int *) malloc(5 * sizeof(int));
  printf("%p\n",array123);
  pi = arrayXYZ;
  printf("%p\n",pi);
  pi++;
  printf("%p\n",pi);
  //Arrays cannot be changed
  //arrayXYZ++;
  printf("%p\n",arrayXYZ);
  //Arrays cannot be assigned
  //arrayXYZ = pi;
  printf("%p\n",arrayXYZ);
  int *intPtr;
  printf("%p\n",intPtr);
  if (intPtr == NULL) {
    intPtr = (int *)malloc(5 * sizeof(int));
      printf("Marla\n");
  }
  return 0 ;
}
