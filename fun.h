#ifndef FUN_H
#define FUN_H

// Ponteiro generico
typedef void * ponteiroGenerico;

// Ponteiro para função
typedef bool (*Compare)(const ponteiroGenerico a, const ponteiroGenerico b);

void min(ponteiroGenerico first, ponteiroGenerico last, size_t size, Compare cmp);

#endif /* FUN_H */