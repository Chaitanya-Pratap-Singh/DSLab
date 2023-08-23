#include <stdio.h>

struct employee {
    char Empid[20];
    char Name[20];
    char Designation[30];
    float basic_salary;
    float hra;
    float da;
} emp[100];

int main() {  // Use int instead of void for main
    int n, i;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter the name of the employee: ");
        scanf("%s", emp[i].Name);  // Removed the '&' before emp[i].Name
        printf("Enter the designation of the employee: ");
        scanf("%s", emp[i].Designation);  // Removed the '&' before emp[i].Designation
        printf("Enter the empid of the employee: ");
        scanf("%s", emp[i].Empid);  // Removed the '&' before emp[i].Empid
        printf("Enter the basic salary of the employee: ");
        scanf("%f", &emp[i].basic_salary);
        emp[i].hra = emp[i].basic_salary * (45.0 / 100);  // Added .0 for correct division
        emp[i].da = emp[i].basic_salary * (15.0 / 100);   // Added .0 for correct division
    }
    
    printf("The details of employees are:\n");
    for (i = 0; i < n; i++) {
        float grs;
        printf("Name:         %s\n", emp[i].Name);
        printf("Designation:  %s\n", emp[i].Designation);
        printf("Empid:        %s\n", emp[i].Empid);
        printf("Salary:       %f\n", emp[i].basic_salary);
        printf("HRA:          %f\n", emp[i].hra);
        printf("DA:           %f\n", emp[i].da);
        grs = emp[i].basic_salary + emp[i].da + emp[i].hra;
        printf("Gross Salary: %f\n", grs);
    }
    
    return 0;  // Return 0 to indicate successful execution
}
