#include <stdio.h>

int main()
{
    int numberOfStudents;
    char registrationNumber[100];
    int marks;
    int i;
    char name[100];
    char grade;

    printf("============================================\n");
    printf("        STUDENT GRADING SYSTEM\n");
    printf("============================================\n\n");

    // Ask the user for the number of students.
    printf("Enter number of students: ");
    scanf("%d", &numberOfStudents);

    // Loop to enter information for each student.
    for (i = 1; i <= numberOfStudents; i++)
    {
        printf("\nEnter information for student %d\n", i);

        printf("Registration number: ");
        scanf(" %99[^\n]", registrationNumber);

        printf("Name: ");
        scanf(" %99[^\n]", name);

        printf("Marks: ");
        scanf("%d", &marks);

        // Determine the grade using if-else-if-else statements.
        if (marks >= 70)
        {
            grade = 'A';
        }
        else if (marks >= 60)
        {
            grade = 'B';
        }
        else if (marks >= 50)
        {
            grade = 'C';
        }
        else if (marks >= 40)
        {
            grade = 'D';
        }
        else
        {
            grade = 'F';
        }

        // Display the student's information immediately after entering it.
        printf("\n--------------------------------------------\n");
        printf("             STUDENT INFORMATION\n");
        printf("--------------------------------------------\n");

        printf("Registration No: %s\n", registrationNumber);
        printf("Name: %s\n", name);
        printf("Marks: %d\n", marks);
        printf("Grade: %c\n", grade);

        // Determine wether the student has passed or failed.
        if (marks >= 40)
        {
            printf("Status: Pass\n");
        }
        else
        {
            printf("Status: Fail\n");
        }

        printf("--------------------------------------------\n");
    }

    printf("\nEnd of student grading system.\n");

    return 0;
}
