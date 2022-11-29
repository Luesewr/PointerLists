//
// Created by Laure on 11/28/2022.
//
#include <stdio.h>
#include "library/pointerList.h"
#include "library/intList.h"

int main() {
    PointerList *pointerList = initialize_pointerlist();
    add_int(pointerList, 4);
    add_int(pointerList, 5);
    print_pointers(pointerList);
    set_int(pointerList, 1, 7);
    printf("%d\n", get_int(pointerList, 1));
    print_pointers(pointerList);
    return delete_pointerlist(pointerList);
}