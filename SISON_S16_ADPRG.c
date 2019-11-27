//
// Created by Kirsten S. on 2019-11-18.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct set {
    int value;
    struct set *next;
} *Set;

Set create() {
    // Return an empty set
    Set empty_set = NULL;
    return  empty_set;
}

void print(Set list) {
    Set node = list;
    while(node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

Set add(Set list, int num) {
    // Create a new node and assign the value
    Set new_node = (Set)malloc(sizeof(struct set));;
    new_node->value = num;
    new_node->next = NULL;
    // If head is NULL, set to first node
    if (list == NULL) {
        return new_node;
    } else {
        Set curr_node = list;
        Set trail = NULL;
        Set temp = new_node;
        // Find where to insert the new node
        while (curr_node != NULL) {
            // Compare new key val with curr key val
            //printf("num: %d vs cur: %d\n", num, curr_node->value);
            if (num == curr_node->value)
                return list; // Do not add duplicates
            else if (num < curr_node->value)
                break; // Found correct position
            else {
                // Keep moving to the next nodes
                trail = curr_node;
                curr_node = curr_node->next;
            }
        }
        temp->next = curr_node;
        if (trail != NULL)
            trail->next = temp; // Insert in between
        else
            return temp; // Return as head
        return list;
    }
}

Set combine(Set a, Set b) {
    Set c = create();
    Set first = a, second = b;
    // Add all elements of the first set to Set c
    while(first != NULL) {
        c = add(c, first->value);
        first =  first->next;
    }
    // Add all elements of the second set to Set c
    while(second != NULL) {
        c = add(c, second->value);
        second =  second->next;
    }
    return c;
}

Set intersect(Set a, Set b) {
    Set d = create();
    Set first = a, second = b;
    // Traverse all of first set
    while(first != NULL) {
        // Traverse second set repeatedly
        second = b;
        while(second != NULL) {
            // If keys are the same, add the key to the list
            if (first->value == second->value)
                d = add(d, second->value);
            second = second->next;
        }
        // Move to the next node
        first = first->next;
    }
    return d;
}

Set difference(Set a, Set b) {
    Set e = create();
    Set first = a, second = b;
    int found;
    // Traverse all of first set
    while(first != NULL) {
        // Set found to 0 indicating it hasn't found a duplicate
        second = b;
        found = 0;
        // Traverse the second set
        while(second != NULL) {
            // Find a duplicate in second set
            if (first->value == second->value) {
                found = 1;
                break;
            }
            second = second->next;
        }
        // Don't add values in first set that has a duplicate in second set
        if (!found)
            e = add(e, first->value);
        // Move to the next node
        first = first->next;
    }
    return e;
}
