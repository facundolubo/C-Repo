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
#define MAX_CURSOS 5 // Maximum number of shifts
#define MAX_ALUMNOS 128

// Define the structure for a student
struct alumno {
    int dni[8];
    char name[MAX_NAME_LENGTH];
    int score;
};

// Define the structure for a node in the linked list
struct alumnoNode {
    struct alumno data;
    struct alumnoNode* next;
};

// Define the structure for a linked list of students
struct listAlumnos {
    struct alumnoNode* head;
    struct alumnoNode* tail;
    int length;
};



// Function to create a new node
struct alumnoNode* createAlumnoNode(struct alumno data) {
    struct alumnoNode* newNode = (struct alumnoNode*)malloc(sizeof(struct alumnoNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

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
alumno  readAlumno(struct Alumno *alumno) {
    alumno->dni = getRandomInt(0, 8); // Random DNI between 10^7 and 10^8 - 1
    getRandomName(alumno->name); // Generate random name
    alumno->score = getRandomInt(0, 100); // Random score between 0 and 100
	return alumno 
}

// Initialize an empty linked list
void initializeList(struct listAlumnos* list) {
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
	for (int = 0; i< MAX_ALUMNOS; i+) {
		struct alumno alu = readAlumno()
		insertAtBeginning(&listAlumnos)
	}
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct listAlumnos* list, struct alumno data) {
    struct alumnoNode* newNode = createAlumnoNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head = newNode;
    }
    list->length++;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct listAlumnos* list, struct alumno data) {
    struct alumnoNode* newNode = createAlumnoNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->length++;
}

// Function to initialize the array of shifts
void initializeTurnos(struct listAlumnos turnos[MAX_CURSOS]) {
    for (int i = 0; i < MAX_CURSOS; i++) {
        initializeList(&turnos[i]);
    }
}

// Function to load the list of students from input
void loadList() {
    // Code to read students from input and insert them into the list
	readAlumno
}

calcTurnos() {
	/*
		- Los alumnos que obtuvieron al menos 8 en EPA deberán ir a los turnos 1 ó 4.
		- Los alumnos que obtuvieron entre 5 y 8 deberán ir a los turnos 2, 3 ó 5.
		- Los alumnos que no alcanzaron la nota 5 no se les asignará turno en CADP.
	*/

int main() {
    struct listAlumnos turnos[MAX_CURSOS];

	initializeList(listAlumnos)

    // Initialize the array of shifts
    initializeTurnos(turnos);

    // Load the list of students from input
    loadList(&turnos); // Example: Load students into the first shift

    // Distribute students into different shifts based on criteria
    // You need to implement the distribution logic here

    // Print the list of students for each shift
    for (int i = 0; i < MAX_CURSOS; i++) {
        printf("Turno %d:\n", i + 1);
        // Print the list of students for this shift
    }

    return 0;
}

