#include <stdio.h>
#include <stdlib.h>

#include "pointerList.h"

int STANDARD_LIST_SIZE = 4;

PointerList *initialize_pointerlist() {
    return initialize_pointerlist_of_capacity(STANDARD_LIST_SIZE);
}

PointerList *initialize_pointerlist_of_capacity(int initialCapacity) {
    if (initialCapacity <= 0) {
        return NULL;
    }
    PointerList *pointerlist = malloc(sizeof(PointerList));
    pointerlist->capacity = initialCapacity;
    pointerlist->size = 0;
    pointerlist->elements = malloc(sizeof(void *) * pointerlist->capacity + 1);
    for (int i = 0; i < pointerlist->capacity; i++) {
        pointerlist->elements[i] = NULL;
    }
    return pointerlist;
}

PointerList *initialize_pointerlist_from_array(void **array, int size) {
    PointerList *pointerlist = malloc(sizeof(PointerList));
    pointerlist->capacity = size < STANDARD_LIST_SIZE ? STANDARD_LIST_SIZE : size;
    pointerlist->size = size;
    pointerlist->elements = malloc(sizeof(void *) * pointerlist->capacity + 1);
    for (int i = 0; i < size; i++) {
        pointerlist->elements[i] = array[i];
    }
    for (int i = size; i < STANDARD_LIST_SIZE; i++) {
        pointerlist->elements[i] = 0;
    }
    return pointerlist;
}

void expand_to_capacity(PointerList *pointerlist, int newCapacity) {
    void * *newElements = malloc(sizeof(void *) * newCapacity + 1);
    copy_into(pointerlist->elements, newElements, pointerlist->capacity, newCapacity);
    for (int i = pointerlist->size; i < newCapacity; i++) {
        newElements[i] = 0;
    }
    free(pointerlist->elements);
    pointerlist->elements = newElements;
    pointerlist->capacity = newCapacity;
}

void shrink_to_capacity(PointerList *pointerlist, int newCapacity) {
    void * *newElements = malloc(sizeof(void *) * newCapacity + 1);
    copy_into(pointerlist->elements, newElements, pointerlist->capacity, newCapacity);
    free(pointerlist->elements);
    pointerlist->elements = newElements;
    pointerlist->capacity = newCapacity;
}

int delete_pointerlist(PointerList *pointerlist) {
    for (int i = 0; i < pointerlist->capacity; i++) {
        free(pointerlist->elements[i]);
    }
    free(pointerlist->elements);
    free(pointerlist);
    return 0;
}

void add_pointer(PointerList *pointerlist, void * value) {
    if (pointerlist->capacity == pointerlist->size) {
        expand_to_capacity(pointerlist, pointerlist->capacity * 2);
    }
    pointerlist->elements[pointerlist->size] = value;
    pointerlist->size++;
}

void add_all_pointers(PointerList *pointerlist, void **values, int size) {
    expand_to_capacity(pointerlist, pointerlist->size + size);
    for (int i = 0; i < size; i++) {
        add_pointer(pointerlist, values[i]);
    }
}

void concat(PointerList *pointerlist1, PointerList *pointerlist2) {
    if (pointerlist2->size == 0) {
        return;
    }

    int newSize = pointerlist1->size + pointerlist2->size;
    if (newSize > pointerlist1->capacity) {
        expand_to_capacity(pointerlist1, newSize);
    }
    for (int i = 0; i < pointerlist2->size; i++) {
        add_pointer(pointerlist1, pointerlist2->elements[i]);
    }
}

void * get_pointer(PointerList *pointerlist, int index) {
    if (index < 0 || index >= pointerlist->size) {
        return NULL;
    }
    return pointerlist->elements[index];
}

void copy_into(void **array1, void **array2, int size1, int size2) {
    int smallest = size1 < size2 ? size1 : size2;
    for (int i = 0; i < smallest; i++) {
        array2[i] = array1[i];
    }
}

void print_pointers(PointerList *pointerlist) {
    for (int i = 0; i < pointerlist->size; i++) {
        printf("%p ", pointerlist->elements[i]);
    }
    printf("\n");
}

void print_pointers_in_capacity(PointerList *pointerlist) {
    for (int i = 0; i < pointerlist->capacity; i++) {
        printf("%p ", pointerlist->elements[i]);
    }
    printf("\n");
}

void * remove_at(PointerList *pointerlist, int index) {
    if (index < 0 || index >= pointerlist->size) {
        return NULL;
    }
    void * result = pointerlist->elements[index];
    for (int i = index + 1; i < pointerlist->size; i++) {
        pointerlist->elements[i - 1] = pointerlist->elements[i];
    }
    pointerlist->size--;
    pointerlist->elements[pointerlist->size] = 0;
    if (pointerlist->size <= pointerlist->capacity / 4) {
        shrink_to_capacity(pointerlist, pointerlist->capacity / 2);
    }
    return result;
}

int index_of(PointerList *pointerlist, void * value) {
    for (int i = 0; i < pointerlist->size; i++) {
        if (pointerlist->elements[i] == value) {
            return i;
        }
    }
    return -1;
}

int contains(PointerList *pointerlist, void * value) {
    return index_of(pointerlist, value) != -1;
}

//PointerList *indices_of(PointerList *pointerlist, void * value) {
//    PointerList *result = initialize_pointerlist();
//    for (int i = 0; i < pointerlist->size; i++) {
//        if (pointerlist->elements[i] == value) {
//            add_pointer(result, i);
//        }
//    }
//    return result;
//}

//PointerList *values_at(PointerList *pointerlist, PointerList *indices) {
//    PointerList *result = initialize_pointerlist_of_capacity(indices->size);
//    for (int i = 0; i < indices->size; i++) {
//        add_pointer(result, pointerlist->elements[indices->elements[i]]);
//    }
//    return result;
//}