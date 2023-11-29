#include<stdio.h>

struct employeeDatabase
{
    char name[100];
    char des[100];
    int salary;
    int hra;
    int da;
    int grsalary;

};
int grossSalary(int base, int hra, int da){
    float gross = 0;
    gross =  (base + hra/100)+(base + da/100);
    return gross;
}

int main(){

    int n;
    printf("Enter number of Employees ");
    scanf("%d", &n);

    struct employeeDatabase employee[n];
    printf("Enter Name, Designation, Salary, HRA%, DA%, and Gross Salary(press enter before every entry) ");

    for(int i = 0; i < n; i++){
        printf("\nEnter Details for employee %d ",i+1);
        scanf("%s",&employee[i].name);
        scanf("%s",&employee[i].des);
        scanf("%d",&employee[i].salary);
        scanf("%d",&employee[i].hra);
        scanf("%d",&employee[i].da);
    }

    printf("Employee Information: \n");

    for(int i = 0; i < n; i++){
        
        printf("\n");
        printf("Name: %s\n",employee[i].name);
        printf("Designation: %s\n",employee[i].des);
        printf("Salary: %d\n",employee[i].salary);
        printf("HRA%: %d%\n",employee[i].hra);
        printf("DA: %d%\n",employee[i].da);
        float gross = grossSalary(employee[i].salary,employee[i].hra,employee[i].da);
        printf("Gross Salary: %f\n",gross);

    }

    return 0;
    
}