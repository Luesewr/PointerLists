#include "pointerList.h"
#include <stdlib.h>

void add_int(PointerList *pointerList, int value) {
    int * pointer = malloc(sizeof(int));
    *pointer = value;
    add_pointer(pointerList, pointer);
}

int get_int(PointerList *pointerList, int index) {
    return * (int *) get_pointer(pointerList, index);
}

void set_int(PointerList *pointerList, int index, int value) {
    *(int *)get_pointer(pointerList, index) = value;
}