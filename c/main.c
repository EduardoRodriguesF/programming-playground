#include <stdio.h>
#include <stdlib.h>

void enter_a_number();
void pointers_exercise();
void pointers_are_fun();
void messing_with_struct();
void string_party();

struct Person {
	char* name;
	int age;
};

void multiply(int *x, int multiplier) 
{
	(*x) = (*x) * multiplier;
}

void strip_newline(char *str, int size)
{
	for (int i = 0; i < size; ++i) {
		if (*str != '\n') continue;

		str[i] = '\0';
		return;
	}
}

int main() 
{
	/*enter_a_number();*/
	/*pointers_exercise();*/
	/*pointers_are_fun();*/
	/*messing_with_struct();*/
	string_party();

	return 0;
}

void string_party() 
{
	int size = 256;
	char string[size];

	printf("Enter a long string: ");

	// We are actually passing the memory address, as arrays 
	// dont require an address operator (&)
	fgets(string, size, stdin);

	strip_newline(string, size);

	printf("You entered the following string: %s", string);

	printf("This should be in the same line line!");
}

void messing_with_struct()
{
	struct Person eduardo;
	struct Person *ptr;

	eduardo.name = "Eduardo";
	eduardo.age = 19;

	ptr = &eduardo;

	printf("Hello, %s! \n", ptr->name); // get whatever is at that maemory address
}

void pointers_are_fun()
{
	int x = 4;

	multiply(&x, 3);

	printf("%d", x);
}

void pointers_exercise()
{
	int size;

	printf("How much space do you want to allocate? ");
	scanf("%d", &size);
		
	int *ptr = malloc(size);

	printf("Your allocated memory is located at %p \n", &ptr);

	printf("Freeing memory... \n");
	free(ptr);
	ptr = 0;
	printf("Allocated memory is now free %p \n", ptr);
}

void enter_a_number()
{
	int my_number;

	printf("Please enter a number: ");
	scanf("%d", &my_number);
	printf("You entered %d \n", my_number);
	printf("Located at: %p \n", &my_number);

	if (my_number > 0) {
		printf("Your number is positive!");
		return;
	}

	if(my_number < 0) {
		printf("Your number is negative.");
		return;
	}

	printf("Your number is neutral.");
}
