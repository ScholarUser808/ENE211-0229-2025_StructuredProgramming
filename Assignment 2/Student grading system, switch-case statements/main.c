#include <stdio.h>

int main()
{
    int numberOfStudents;
    char registrationNumber[100];
    int marks;
    int i;
    char name[100];
    char grade;
    int category;

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

        // Convert the marks into a category. The category is then used by the switch-case statement.
        if (marks >= 70)
        {
            category = 1;
        }
        else if (marks >= 60)
        {
            category = 2;
        }
        else if (marks >= 50)
        {
            category = 3;
        }
        else if (marks >= 40)
        {
            category = 4;
        }
        else
        {
            category = 5;
        }

        // Determine the grade using switch-case.
        switch (category)
        {
            case 1:
                grade = 'A';
                break;

            case 2:
                grade = 'B';
                break;

            case 3:
                grade = 'C';
                break;

            case 4:
                grade = 'D';
                break;

            case 5:
                grade = 'F';
                break;

            default:
                grade = 'F';
                break;
        }

        // Display the student's information.
        printf("\n--------------------------------------------\n");
        printf("             STUDENT INFORMATION\n");
        printf("--------------------------------------------\n");

        printf("Registration No: %s\n", registrationNumber);
        printf("Name: %s\n", name);
        printf("Marks: %d\n", marks);
        printf("Grade: %c\n", grade);

        // Determine pass or fail using switch-case.
        switch (category)
        {
            case 1:
            case 2:
            case 3:
            case 4:
                printf("Status: Pass\n");
                break;

            case 5:
                printf("Status: Fail\n");
                break;

            default:
                printf("Status: Fail\n");
                break;
        }

        printf("--------------------------------------------\n");
    }

    printf("\nEnd of student grading system.\n");

    return 0;
}
