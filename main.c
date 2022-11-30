//
// Created by Laure on 11/28/2022.
//
#include <stdio.h>
#include "library/pointerList.h"
#include "library/intList.h"

int timesFive(int x) {
    return x * 5;
}

int isEven(int x) {
    return x % 2 == 0;
}

int main() {
    PointerList *pointerList = initialize_pointerlist();
    add_int(pointerList, 4);
    add_int(pointerList, 5);
    add_int(pointerList, 2);
    add_int(pointerList, 1);
    add_int(pointerList, 8);
    add_int(pointerList, 3);
    add_int(pointerList, 6);
    add_int(pointerList, 3);
    print_ints(pointerList);
    sort_ints(pointerList);
    PointerList *indices = indices_of_int(pointerList, 3);
    print_ints(indices);
    delete_pointerlist(indices);
    print_ints(pointerList);
    apply_to_ints(pointerList, &timesFive);
    print_ints(pointerList);
    PointerList *filtered = filter_ints(pointerList, &isEven);
    print_ints(filtered);
    delete_pointerlist(filtered);
    print_ints(pointerList);
    return delete_pointerlist(pointerList);
}