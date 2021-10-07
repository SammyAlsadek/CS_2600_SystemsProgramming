#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void)
{
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char *phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    //Example not found
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID 1045 is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    //Example not found and found for searchEmployeeByPhone
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-234-2134");
    if (matchPtr != NULL)
        printf("Employee phone 909-234-2134 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone 909-234-2134 is NOT found in the record\n");

    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-2134");
    if (matchPtr != NULL)
        printf("Employee phone 909-555-2134 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone 909-555-2134 is NOT found in the record\n");

    //Example not found and found for searchEmployeeBySalary
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 100.00);
    if (matchPtr != NULL)
        printf("Employee salary 100.00 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary 100.00 is NOT found in the record\n");

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.32);
    if (matchPtr != NULL)
        printf("Employee salary 8.32 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary 8.32 is NOT found in the record\n");

    return EXIT_SUCCESS;
}