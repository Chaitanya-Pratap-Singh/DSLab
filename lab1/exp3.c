#include <stdio.h>
struct employee{
    char Empid[20];
    char Name[20];
    char Designation[30];
    float basic_salary;
    float hra;
    float da;
}emp [100];

void main()
{
    int n,i;
    printf("enter the number of employees:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the name of the employee: ");
        scanf("%s",&emp[i].Name);
        printf("enter the desig of the employee: ");
        scanf("%s",&emp[i].Designation);
        printf("enter the empid of the employee: ");
        scanf("%s",&emp[i].Empid);
        printf("enter the basic salary of the employee: ");
        scanf("%f",&emp[i].basic_salary);
         emp[i].hra = emp[i].basic_salary*(45/100);
        emp[i].da = emp[i].basic_salary*(15/100);
        }
    printf("the details of employees are:");
    for(i=0;i<n;i++)
    {
        float grs;
        printf("name:         %s\n",emp[i].Name);
        printf("designation:  %s\n",emp[i].Designation);
        printf("empid:        %s\n",emp[i].Empid);
        printf("salary:       %f\n",emp[i].basic_salary);
        printf("hra:          %f\n",emp[i].hra);
        printf("da:           %f\n",emp[i].da);
        grs=emp[i].basic_salary+(((emp[i].hra)/100)*emp[i].basic_salary)+(((emp[i].da)/100)*emp[i].basic_salary);
        printf("gross salary: %f\n",grs);
        

    }


}