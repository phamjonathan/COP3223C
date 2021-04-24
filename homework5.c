// Jonathan Pham
// NID: 
// Homework 5 "homework5.c"
// COP 3223C Section 0V06, Spring 2021

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct payroll
{
    unsigned long long int internal_id;
    char first_name[50];
    char last_name[50]; 
    char department[100];  
    unsigned char dob_day;  
    unsigned char dob_month;  
    unsigned short dob_year;  
    double monthly_salary;

};

#define MAX_PAYRECS_NO 10000
struct payroll pay_recs[MAX_PAYRECS_NO];
size_t pay_recs_no;

void printDeptPayrollRecords(char* dept_name)
{
    bool dept_present=false;

    for(int i=0;i<pay_recs_no;i++)
    {

        if(strcmp(pay_recs[i].department,dept_name)==0)
        {
            dept_present=true;
            break;
        }
    }

    if(dept_present)
    {

        double total_salary=0;
        int number=0;
        printf("Employees of the %s Department",dept_name);
        printf("\nLast Name    First Name    Date of Birth   Monthly Salary");
        printf("\n---------------------------------------------------------\n");

        for(int i=0;i<pay_recs_no;i++)
        {

            if(strcmp(pay_recs[i].department,dept_name)==0)
            {
                number++;

                total_salary+=pay_recs[i].monthly_salary;
                printf("%-13s",pay_recs[i].last_name); 
                printf("%-14s",pay_recs[i].first_name);  
                printf("%d",pay_recs[i].dob_year);  
                printf("-%02d",pay_recs[i].dob_month);  
                printf("-%02d",pay_recs[i].dob_day);  
                printf("      ");
                printf("%0.2lf\n",pay_recs[i].monthly_salary);  
            }
        }

        printf("Total Number of Employees in the Department: %d\n",number);
        printf("Aggregated Salary of the Department: %0.2lf\n",total_salary);
    }

    else
        printf("Department %s has no payroll records.\n",dept_name);
}

void SaveDeptPayrollRecordsToFile(char* dept_name,char* file_name)
{
    FILE *file;  // File pointer
    file=fopen(file_name,"w");  

    if(file==NULL)  // If file is not created
    {
        printf("Can not open file. Terminating the program");
        exit(0);  
    }

    bool dept_present=false;
    // Loop for all records
    for(int i=0;i<pay_recs_no;i++)
    {
        // If there are no records
        if(strcmp(pay_recs[i].department,dept_name)==0)
        {
            dept_present=true;  
            break;  
        }
    }

    if(dept_present)
    {
        double total_salary=0;
        int number=0;  

        fprintf(file,"Employees of the %s Department",dept_name);
        fprintf(file,"\nLast Name    First Name    Date of Birth   Monthly Salary");
        fprintf(file,"\n---------------------------------------------------------\n");
        for(int i=0;i<pay_recs_no;i++)
        {

            if(strcmp(pay_recs[i].department,dept_name)==0)
            {
                number++; 
                total_salary+=pay_recs[i].monthly_salary;  
                fprintf(file,"%-13s",pay_recs[i].last_name);  
                fprintf(file,"%-14s",pay_recs[i].first_name);  
                fprintf(file,"%d",pay_recs[i].dob_year);  
                fprintf(file,"-%02d",pay_recs[i].dob_month);  
                fprintf(file,"-%02d",pay_recs[i].dob_day); 
                fprintf(file,"      ");
                fprintf(file,"%0.2lf\n",pay_recs[i].monthly_salary); 
            }
        }

        fprintf(file,"Total Number of Employees in the Department: %d\n",number);

        fprintf(file,"Aggregated Salary of the Department: %0.2lf\n",total_salary);
    }

    else
        fprintf(file,"Department %s has no payroll records.\n",dept_name);


}
int main()
{
    pay_recs_no=10;

    pay_recs[0].internal_id=1121;   
    strcpy(pay_recs[0].first_name,"Jonathan") ;  
    strcpy(pay_recs[0].last_name,"Pham");  
    strcpy(pay_recs[0].department,"Executive");  
    pay_recs[0].dob_day=25;  
    pay_recs[0].dob_month=04;  
    pay_recs[0].dob_year=1998;  
    pay_recs[0].monthly_salary=1000000.00;  

    pay_recs[1].internal_id=1122;   
    strcpy(pay_recs[1].first_name,"Bob") ;  
    strcpy(pay_recs[1].last_name,"Jones");  
    strcpy(pay_recs[1].department,"Purchase");  
    pay_recs[1].dob_day=12;  
    pay_recs[1].dob_month=5;  
    pay_recs[1].dob_year=1832;  
    pay_recs[1].monthly_salary=50.00;  

    pay_recs[2].internal_id=1123;   
    strcpy(pay_recs[2].first_name,"Michael") ;  
    strcpy(pay_recs[2].last_name,"Angelo");  
    strcpy(pay_recs[2].department,"Security");  
    pay_recs[2].dob_day=5;  
    pay_recs[2].dob_month=8;  
    pay_recs[2].dob_year=1786;  
    pay_recs[2].monthly_salary=100.00;  

    pay_recs[3].internal_id=1124;   
    strcpy(pay_recs[3].first_name,"Rudolf") ;  
    strcpy(pay_recs[3].last_name,"Goldman");  
    strcpy(pay_recs[3].department,"Purchase");  
    pay_recs[3].dob_day=20;  
    pay_recs[3].dob_month=01;  
    pay_recs[3].dob_year=2000;  
    pay_recs[3].monthly_salary=150.00;  

    pay_recs[4].internal_id=1125;   
    strcpy(pay_recs[4].first_name,"Zephryhills") ;  
    strcpy(pay_recs[4].last_name,"Water");  
    strcpy(pay_recs[4].department,"Purchase");  
    pay_recs[4].dob_day=14;  
    pay_recs[4].dob_month=11;  
    pay_recs[4].dob_year=2002;  
    pay_recs[4].monthly_salary=200.00; 

    pay_recs[5].internal_id=1126;   
    strcpy(pay_recs[5].first_name,"Mouse") ;  
    strcpy(pay_recs[5].last_name,"Computer");  
    strcpy(pay_recs[5].department,"IT");  
    pay_recs[5].dob_day=2;  
    pay_recs[5].dob_month=4;  
    pay_recs[5].dob_year=1987;  
    pay_recs[5].monthly_salary=250.00;  

    pay_recs[6].internal_id=1127;
    strcpy(pay_recs[6].first_name,"Favio") ;
    strcpy(pay_recs[6].last_name,"LeMar");  
    strcpy(pay_recs[6].department,"Cooking");  
    pay_recs[6].dob_day=9;  
    pay_recs[6].dob_month=8;  
    pay_recs[6].dob_year=1981;  
    pay_recs[6].monthly_salary=300.00;  

    pay_recs[7].internal_id=1128;   
    strcpy(pay_recs[7].first_name,"Tissue") ;  
    strcpy(pay_recs[7].last_name,"Achoo");  
    strcpy(pay_recs[7].department,"Cleaning");  
    pay_recs[7].dob_day=27;  
    pay_recs[7].dob_month=4;  
    pay_recs[7].dob_year=1996;  
    pay_recs[7].monthly_salary=350.00;  

    pay_recs[8].internal_id=1129;   
    strcpy(pay_recs[8].first_name,"Gin") ;  
    strcpy(pay_recs[8].last_name,"Seng");  
    strcpy(pay_recs[8].department,"Health");  
    pay_recs[8].dob_day=15;  
    pay_recs[8].dob_month=12;  
    pay_recs[8].dob_year=1989;  
    pay_recs[8].monthly_salary=400.00;  

    pay_recs[9].internal_id=1130;   
    strcpy(pay_recs[9].first_name,"Chef") ;  
    strcpy(pay_recs[9].last_name,"Boyard");  
    strcpy(pay_recs[9].department,"Cooking");  
    pay_recs[9].dob_day=20;  
    pay_recs[9].dob_month=01;  
    pay_recs[9].dob_year=1998;
    pay_recs[9].monthly_salary=400.00;

    printDeptPayrollRecords("Purchase");
    printf("Enter the file name: ");
    char filename[50];
    scanf("%s",&filename);

    SaveDeptPayrollRecordsToFile("Purchase",filename);

    return 0;
}