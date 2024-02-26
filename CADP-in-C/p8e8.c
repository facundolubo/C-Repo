/*
 *
 *
 La cátedra de CADP está organizando la cursada para el año 2019. Para ello, dispone de una lista con
todos los alumnos que cursaron EPA. De cada alumno se conoce su DNI, apellido, nombre y la nota obtenida.
Escribir un programa que procese la información de alumnos disponible y los distribuya en turnos utilizando
los siguientes criterios:
- Los alumnos que obtuvieron al menos 8 en EPA deberán ir a los turnos 1 ó 4.
- Los alumnos que obtuvieron entre 5 y 8 deberán ir a los turnos 2, 3 ó 5.
- Los alumnos que no alcanzaron la nota 5 no se les asignará turno en CADP.
Al finalizar, el programa debe imprimir en pantalla la lista de alumnos para cada turno.
Nota: La distribución de alumnos debe ser lo más equitativa posible.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 64
#define MAX_CURSOS 5 
#define MAX_ALUMNOS 128
#define TRUE 1
#define FALSE 0

// Define the structure for a student
typedef struct alumno {
    int dni[10]; // Assuming 10-digit DNI
    char name[MAX_NAME_LENGTH];
    int score;
} Alumno; // Use 'struct' keyword for clarity

// Define the structure for a node in the linked list
typedef struct alumnoNode {
    Alumno data;
    struct alumnoNode* next;
} AlumnoNode;

// Define the structure for a linked list of students
typedef struct listAlumnos {
    AlumnoNode* head;
    AlumnoNode* tail;
    int length;
} ListAlumnos;

// Function to generate a random integer between min and max
int getRandomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate a random name
void getRandomName(char *name) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int nameLength = getRandomInt(5, 10); // Random name length between 5 and 10 characters

    for (int i = 0; i < nameLength; ++i) {
        name[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    name[nameLength] = '\0'; // Null-terminate the string
}

// Function to read Alumno record with random values
Alumno readAlumno() {
    Alumno alumno;
    for (int i = 0; i < 10; i++) {
        alumno.dni[i] = getRandomInt(0, 8); // Random DNI between 0 and 8
    }
    getRandomName(alumno.name); // Generate random name
    alumno.score = getRandomInt(0, 10); // Random score between 0 and 10
    return alumno;
}

// Function to create a new node
AlumnoNode* createAlumnoNode(Alumno data) {
    AlumnoNode* newNode = (AlumnoNode*)malloc(sizeof(AlumnoNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(ListAlumnos* lAlu, Alumno data) {
    AlumnoNode* newNode = createAlumnoNode(data);
    if (lAlu->head == NULL) {
        lAlu->head = newNode;
        lAlu->tail = newNode;
    } else {
        newNode->next = lAlu->head;
        lAlu->head = newNode;
    }
    lAlu->length++;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(ListAlumnos* lAlu, Alumno data) {
    AlumnoNode* newNode = createAlumnoNode(data);
    if (lAlu->head == NULL) {
        lAlu->head = newNode;
        lAlu->tail = newNode;
    } else {
        lAlu->tail->next = newNode;
        lAlu->tail = newNode;
    }
    lAlu->length++;
}

// Initialize an empty linked list
void createList(ListAlumnos* lAlu, int len) {
    lAlu->head = NULL;
    lAlu->tail = NULL;
    lAlu->length = len;
    for (int i = 0; i < len; i++) {
        Alumno alu = readAlumno();
        insertAtBeginning(lAlu, alu);
    }
}

// Function to initialize the array of shifts
void initializeTurnos(ListAlumnos turnos[MAX_CURSOS]) {
    for (int i = 0; i < MAX_CURSOS; i++) {
        createList(&turnos[i], FALSE);
    }
}

int switchAbove8() {
    static struct {
        unsigned int value: 2;
    } twoBitVar = {0};
    twoBitVar.value = ~twoBitVar.value;
    return twoBitVar.value;
}

int switchOthers() {
    static struct {
        unsigned int value: 3;
    } threeBitVar = {0};
	threeBitVar.value = 1 << threeBitVar.value;
    if (threeBitVar.value == 0) {
		threeBitVar.value = 1 << threeBitVar.value;
	}
    return threeBitVar.value;
}


void calcTurnos(ListAlumnos turnos[MAX_CURSOS], ListAlumnos lAlu) {
    /*
        - Los alumnos que obtuvieron al menos 8 en EPA deberán ir a los turnos 1 ó 4.
        - Los alumnos que obtuvieron entre 5 y 8 deberán ir a los turnos 2, 3 ó 5.
        - Los alumnos que no alcanzaron la nota 5 no se les asignará turno en CADP.
    */
    int index;
    AlumnoNode *current = lAlu.head;
    Alumno currentAlu;
    int score;
    AlumnoNode *auxPointer;

    while (current != NULL)  {
        currentAlu = current->data;
        score = currentAlu.score;
        //printf("Actual score: %d\n", score); // Corrected printf format specifier
        if (score >= 8) {
            // index turno 1 = 0, index turno 4 = 3
            //index = switchAbove8();
            printf("%d\n", index);
            insertAtEnd(&turnos[index], currentAlu);
        }
        else if (score >= 5) {
            // index turno 2,3,5 = 1,2,4
            index = switchOthers();
            printf("%d\n", index);
            insertAtEnd(&turnos[index], currentAlu);
        }
        auxPointer = current;
        current = current->next;
        free(auxPointer);
    }
}

void printList(ListAlumnos list) {
    AlumnoNode* current = list.head;
    printf("Length: %d\n", list.length);
    while (current != NULL) {
        printf("DNI: ");
        for (int i = 0; i < 10; i++) {
            printf("%d", current->data.dni[i]);
        }
        printf(", Name: %s, Score: %d\n", current->data.name, current->data.score);
        current = current->next;
    }
}
void printTodo(ListAlumnos turnos[MAX_CURSOS]) {
    for (int i = 0; i < MAX_CURSOS; i++) {
        printf("Turno %d:\n", i + 1);
        printList(turnos[i]);
    }
}

int main() {
    ListAlumnos turnos[MAX_CURSOS];
    ListAlumnos lAlu;
    createList(&lAlu, MAX_ALUMNOS);

    // Initialize the array of shifts
    initializeTurnos(turnos);

    // Calculate shifts for students
    calcTurnos(turnos, lAlu);

    // Print the list of students for each shift
    printTodo(turnos);

    return 0;
}
