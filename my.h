/*
** EPITECH PROJECT, 2018
** my.h
** File description:
**
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct obj_s
{
    char *name;
    char *value;
    struct obj_s *next;
} obj_t;

typedef struct hash_table_s
{
    size_t size;
    obj_t **table;
} hash_table_t;

#endif
