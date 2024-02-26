// repetitionChecker.h
#ifndef REPETITION_CHECKER_H
#define REPETITION_CHECKER_H

typedef struct {
    int* indices;
    int count;
} IndexList;

IndexList* findRepetitions(int* rowSums, int n);

void freeIndexList(IndexList* list);

#endif

