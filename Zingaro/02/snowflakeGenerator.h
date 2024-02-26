#ifndef SNOWFLAKE_GENERATOR_H
#define SNOWFLAKE_GENERATOR_H

// Function prototypes
int generateRandomInt(int min, int max);
int** generateSnowflake(int n);
void freeSnowflake(int** snowflake, int n);

#endif // SNOWFLAKE_GENERATOR_H

