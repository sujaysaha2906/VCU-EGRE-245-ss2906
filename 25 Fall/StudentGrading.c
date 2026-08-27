/******************************************************************************
* Lab #: [Sort a list/Lab #10]
*
* Programmer: [Mahki Holmes]
*
* Due Date: [November 13, 2025]
*
* EGRE 245, Fall 2025 Instructor: Dr. Mark Schwitzerlett
*
* Pledge: I have neither given nor received unauthorized aid on this program.
*
* Description: [For this program we are sorting out three different lists using
* students' name, age, and year. We use different structures to create the lists.]
*
* Input: [no user input]
*
* Output: [The output should be the list of students sorted in three different 
* lists.]
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS  20
#define FILENAME      "Mathematicians.txt"


struct student {
	char first[40];
	char last[40];
	int year;
	int age;
};


int read_students(struct student list[], int max); //reading the records from file
void print_line(void);
void print_student(const struct student *s);
int cmp_last(const void *pa, const void *pb);

//comparing by first and last name.
int  cmp_first(const void *pa, const void *pb); 
void apply(struct student list[], int n,
           void (*fp)(const struct student *s));
void isolder(const struct student *s);  //Print out if the age is lower than 20

int main(void)
{
    //arrays for the first and last names
    struct student raw[MAX_STUDENTS];
	struct student byFirst[MAX_STUDENTS]; 
	struct student byLast[MAX_STUDENTS];    
	int n, i;

	n = read_students(raw, MAX_STUDENTS);    
	if (n <= 0) {                         
		printf("Error. Couldn't read file\n");
		return 1;
	}
	for (i = 0; i < n; i++) {
		byFirst[i] = raw[i];  
		byLast[i]  = raw[i];  
	}
	printf("lab #10 - Mahki Holmes, Ayla Xo, William Betancourt\n\n");
	
	printf("Raw records:\n");
	print_line();
	for (i = 0; i < n; i++) {
		print_student(&raw[i]);
	}
	printf("\n");
// Sorting them out by first name
	qsort(byFirst, n, sizeof(struct student), cmp_first);

	printf("Sorted by first name:\n");
	print_line();
	for (i = 0; i < n; i++) {
		print_student(&byFirst[i]);
	}

	printf("\n");
// Sorting them out by last name 
	qsort(byLast, n, sizeof(struct student), cmp_last);


	printf("Sorted by last name:\n");
	print_line();
	for (i = 0; i < n; i++) {
		print_student(&byLast[i]);
	}
	printf("\n");

	printf("People older than 20:\n");
	print_line();
	apply(raw, n, isolder);

	return 0;
}
//reading the student records from file
int read_students(struct student list[], int max)
{
	FILE *fp;
	int count = 0;

	fp = fopen(FILENAME, "r");
	if (fp == NULL) {
		perror("Error opening file");
		return 0;
	}
	while (count < max &&
	        fscanf(fp, " \"%[^\"]\" , \"%[^\"]\" , %d , %d ,",
	               list[count].first,
	               list[count].last,
	               &list[count].year,
	               &list[count].age) == 4) {
		count++;
	}
	fclose(fp);
	return count;
}

void print_line(void)
{
	printf("----------------------------------------\n");
}
// printing student records
void print_student(const struct student *s)
{
	printf("%-20s %-20s %2d %3d\n",
	       s->first, s->last, s->year, s->age);
}
// comparing two students by their first names'
int cmp_first(const void *pa, const void *pb)
{
	const struct student *a = (const struct student *)pa;
	const struct student *b = (const struct student *)pb;
	return strcmp(a->first, b->first);
}
// comparing two students by their last names' 
int cmp_last(const void *pa, const void *pb)
{
	const struct student *a = (const struct student *)pa;
	const struct student *b = (const struct student *)pb;
	return strcmp(a->last, b->last);
}

void apply(struct student list[], int n,
           void (*fp)(const struct student *s))
{
	int i;
	for (i = 0; i < n; i++) {
		fp(&list[i]);
	}
}
//print the students that have an age above 20
void isolder(const struct student *s)
{
	if (s->age > 20) {
		print_student(s);
	}
}