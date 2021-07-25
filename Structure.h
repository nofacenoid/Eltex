#include <stdio.h>

#define NAME_SIZE 		12
#define TEL_SIZE		10
#define MAX_SIZE		12
#define STRUCT_SIZE		100

struct TelBase {
	char name [NAME_SIZE];
	char telephone [TEL_SIZE];
};

void PrintName (struct TelBase Base[STRUCT_SIZE], int el);
void PrintTel (struct TelBase Base[STRUCT_SIZE], int el);
void PrintOnePerson (struct TelBase Base[STRUCT_SIZE], int el);
void FlushKeyBoard ();
void PrintAllBase(struct TelBase Base[STRUCT_SIZE]);
void AddElement (struct TelBase Base[STRUCT_SIZE]);
void Delete (struct TelBase Base[STRUCT_SIZE], int el);
void SearchPart(struct TelBase Base[STRUCT_SIZE], int size, char * ChEl);
void Search (struct TelBase Base[STRUCT_SIZE]);
void Menu (struct TelBase Base[STRUCT_SIZE]);
