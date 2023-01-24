Question : Write a simple program to demonstrate the use and declaration of structure;
==========================================================================================
  
Algorithm:

---> Declare a structure named "student"
---> Declare a variable of type "student"
---> Input details of student
---> Print details of student

This program demonstrates the basic use of structures in C by declaring a structure called "student" with three members: an integer "id",
a character array "name", and a floating-point "grade". A variable of type "student" is then declared and its members are assigned values by the user before 
being printed out;


Code Below :::
-----------------------------------------------------------------------------------------
  
  
#include <stdio.h>

// Declare a structure named "student"
struct student {
    int id;
    char name[50];
    float grade;
};

int main() {
    // Declare a variable of type "student"
    struct student s1;

    // Input details of student
    printf("Enter student ID: ");
    scanf("%d", &s1.id);
    printf("Enter student name: ");
    scanf("%s", s1.name);
    printf("Enter student grade: ");
    scanf("%f", &s1.grade);

    // Print details of student
    printf("\nStudent ID: %d\n", s1.id);
    printf("Student name: %s\n", s1.name);
    printf("Student grade: %.2f\n", s1.grade);

    return 0;
}
