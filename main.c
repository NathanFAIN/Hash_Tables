/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my.h"

size_t hash(char *name)
{
    size_t result = 0;

    for (size_t index = 0; name[index] != '\0'; index++) {
        result += name[index] * (index + 1);
    }
    return (result);
}

hash_table_t *create_table(size_t size)
{
    hash_table_t *new = malloc(sizeof(hash_table_t));

    new->size = size;
    new->table = malloc(sizeof(obj_t *) * size);
    for (size_t index = 0; index != size; index++) {
        new->table[index] = NULL;
    }
    return (new);
}

void destroy_table(hash_table_t *table)
{
    for (size_t index = 0; index != table->size; index++) {
        if (table->table[index] != NULL) {
            free(table->table[index]);
        }
    }
    free(table->table);
    free(table);
}

obj_t *create_element(char *name, char *value)
{
    obj_t *new = malloc(sizeof(obj_t));

    new->name = name;
    new->value = value;
    new->next = NULL;
    return (new);
}

void add_element(hash_table_t *table, char *name, char *value)
{
    size_t index = hash(name) % table->size;
    obj_t *tmp;

    if (table->table[index] != NULL) {
        for (tmp = table->table[index]; tmp->next != NULL && \
        strcmp(tmp->name, name); tmp = tmp->next);
        if (strcmp(tmp->name, name) == 0) {
            tmp->value = value;
        } else {
            tmp->next = create_element(name, value);
        }
    } else {
        table->table[index] = create_element(name, value);
    }
}

char *get_element(hash_table_t *table, char *name)
{
    size_t index = hash(name) % table->size;
    obj_t *tmp;

    if (table->table[index] != NULL) {
        for (tmp = table->table[index]; tmp->next != NULL && \
        strcmp(tmp->name, name); tmp = tmp->next);
        if (strcmp(tmp->name, name) == 0) {
            return (tmp->value);
        } else {
            return (NULL);
        }
    } else {
        return (NULL);
    }
}


int main(void)
{
    hash_table_t *table = create_table(10);
    char *name[] = {"KYT", "CAT", "TOTO", "TATA"};
    char *value[] = {"A", "B", "C", "D"};

    for (size_t index = 0; index != 4; index++) {
        add_element(table, name[index], value[index]);
    }
    printf("[%s]\n", get_element(table, "TOTOO"));
    destroy_table(table);
    return (0);
}
