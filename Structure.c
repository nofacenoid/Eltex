#include "Structure.h"

static unsigned int element = 0;


void PrintName (struct TelBase Base[STRUCT_SIZE], int el){
	printf ("Name: ");
	for (int i = 0; Base[el].name[i] != '0'; i++){
		printf ("%c", Base[el].name[i]);
	}
	printf ("\n");
}

void PrintTel (struct TelBase Base[STRUCT_SIZE], int el){
	printf ("Telephone number: +7");
	for (int i = 0; i < TEL_SIZE; i++){
		printf ("%c", Base[el].telephone[i]);
	}
	printf ("\n");
}

void PrintOnePerson (struct TelBase Base[STRUCT_SIZE], int el){
	printf ("\nid = %d\n", el + 1);
	PrintName(Base, el);
	PrintTel (Base, el);
}
//Функция используется для очистки буфера scanf
void FlushKeyBoard (){
	char ch;
	while ((ch = getc(stdin)) != EOF && ch != '\n');
}



void PrintAllBase (struct TelBase Base[STRUCT_SIZE]){
	if (element > 0) {
		for (int i = 0; i < element; i++){
			PrintOnePerson(Base, i);
		}
	}
	else {
		printf ("\nSorry, but the list is empty :(\n");
	}
	printf ("\n");
}

void AddElement (struct TelBase Base[STRUCT_SIZE]){
	int n = 0;
	char letter;

	printf ("Enter size name but no more than %d\n", NAME_SIZE);
	scanf ("%d", &n);
	FlushKeyBoard();
	printf ("Enter name: ");
	for (int i = 0; i < NAME_SIZE; i++){
		if (i < n) {
			scanf ("%c", &letter);
			Base[element].name[i] = letter;
		}
		else {
			Base[element].name[i] = '0';
		}
	}
	FlushKeyBoard();
	printf ("Enter telephone number: +7");
	for (int i = 0; i < TEL_SIZE; i++){
		scanf ("%c", &letter);
		Base[element].telephone[i] = letter;
	}
	FlushKeyBoard();
	element++;
}

void Delete (struct TelBase Base[STRUCT_SIZE], int el){
	if ((el - 1) < element){
		for (int i = 0; i < NAME_SIZE; i++){
			Base[el - 1].name[i] = Base[element - 1].name[i];
		}
		for (int i = 0; i < TEL_SIZE; i++){
			Base[el - 1].telephone[i] = Base[element - 1].telephone[i];
		}
	}
	element--;
}

void SearchPart(struct TelBase Base[STRUCT_SIZE], int size, char * ptrEl){
	char NameOrTel[MAX_SIZE] = {0};
	int el = 0;
	//Количество совпадений с найденным именем
	unsigned int numberOfCoincidences = 0;
	for (int i = 0; i < size; i++){
		scanf ("%c", &NameOrTel[i]);
	}
	FlushKeyBoard();
	for (int i = 0, coincidences = 0; i < element; i++, coincidences = 0){
		for ( int ii = 0; ii < size; ii++){
			if (*(ptrEl + i*sizeof(*Base) + ii*sizeof(*Base[0].name)) == NameOrTel[ii]){
			coincidences++;
			}
		}
		if (numberOfCoincidences < coincidences){
			numberOfCoincidences = coincidences;
			el = i;
		}
		if (numberOfCoincidences == size){
			PrintOnePerson(Base, el);
			printf ("\n");
			return;
		}
	}
	if (numberOfCoincidences < size && numberOfCoincidences != 0){
		printf ("\nNo exact match found.\nMost suitable: \n");
		PrintOnePerson(Base, el);
		printf ("\n");
	}
	else {
		printf ("\nSorry but no matches found :'(\n\n");
	}

}

void Search (struct TelBase Base[STRUCT_SIZE]){
	char n = '\0';
	int NameSize = 0;
	while (n != '0'){

		printf ("Search by name enter '1',\n");
		printf ("Search by telephone number enter '2'\n");
		printf ("Return to menu '0'\n");
		scanf ("%c", &n);
		FlushKeyBoard();
		switch (n){
		case '1':
			printf ("Enter name size: ");
			scanf ("%d", &NameSize);
			printf ("Enter name: ");
			FlushKeyBoard();
			SearchPart(Base, NameSize, &Base[0].name[0]);
			break;
		case '2':
			printf ("Enter telephone number: +7");
			SearchPart(Base, TEL_SIZE, &Base[0].telephone[0]);
			break;
		case '0':
			return;
		default:
			printf ("You specified the wrong command, please try again\n");
			break;
		}
	}
}

void Menu (struct TelBase Base[STRUCT_SIZE]){
	char letter = '\0';
	int el = -1;
	while (letter != '0'){
		printf ("Enter the desired action:\n1 - add new name and his telephone number\n");
		printf ("2 - show the whole list\n3 - delete name and his telephone number\n");
		printf ("4 - find the required telephone number\n0 - exit\n");
		scanf ("%c", &letter);
		FlushKeyBoard();
		switch (letter){
		case '1':
			AddElement(Base);
			break;
		case '2':
			PrintAllBase(Base);
			break;
		case '3':
			printf ("Enter the id of the phone number you want to delete: ");
			scanf ("%d", &el);
			FlushKeyBoard();
			Delete(Base, el);
			break;
		case '4':
			Search(Base);
			break;
		case '0':
			return;
		default:
			printf ("You specified the wrong command, please try again\n");
			break;
		}
	}
}
