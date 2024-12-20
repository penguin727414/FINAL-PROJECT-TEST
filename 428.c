#include <stdio.h>

int main() {
    int paycode;  
    double weeklyPay = 0;  
    int working = 1;  

    
    while (working) {
        printf("\nEnter employee's paycode (1=Manager, 2=Hourly Worker, 3=Commission Worker, 4=Pieceworker, -1 to end): ");
        scanf("%d", &paycode);

        if (paycode == -1) {
            printf("End of payroll input.\n");
            break;
        }

        switch (paycode) {
            case 1: 
                printf("Enter weekly salary for the manager: ");
                scanf("%lf", &weeklyPay);
                printf("Manager's weekly pay is: $%.2lf\n", weeklyPay);
                break;

            case 2: { 
                double hourlyWage, hoursWorked;
                printf("Enter hourly wage: ");
                scanf("%lf", &hourlyWage);
                printf("Enter hours worked: ");
                scanf("%lf", &hoursWorked);

                if (hoursWorked <= 40) {
                    weeklyPay = hourlyWage * hoursWorked;
                } else {
                    weeklyPay = hourlyWage * 40 + 1.5 * hourlyWage * (hoursWorked - 40);
                }
                printf("Hourly worker's weekly pay is: $%.2lf\n", weeklyPay);
                break;
            }

            case 3: { 
                double sales;
                printf("Enter gross weekly sales: ");
                scanf("%lf", &sales);
                weeklyPay = 250 + 0.057 * sales;
                printf("Commission worker's weekly pay is: $%.2lf\n", weeklyPay);
                break;
            }

            case 4: { 
                int piecesProduced;
                double wagePerPiece;
                printf("Enter number of pieces produced: ");
                scanf("%d", &piecesProduced);
                printf("Enter wage per piece: ");
                scanf("%lf", &wagePerPiece);
                weeklyPay = piecesProduced * wagePerPiece;
                printf("Pieceworker's weekly pay is: $%.2lf\n", weeklyPay);
                break;
            }

            default:
                printf("Invalid paycode. Please enter a valid paycode (1, 2, 3, 4 or -1 to end).\n");
        }
    }

    return 0;
}
