#include <iostream>
using namespace std;

int main()
{
    // CURRENCY FORMATTING

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    double loan = 0;
    double rate = 0;
    double payment = 0;

    // USER INPUT

    while (loan <= 0)
    {
        cout << "Loan Amount: ";
        cin >> loan;
    }

    while (rate <= 0)
    {
        cout << "Interest Rate: ";
        cin >> rate;
    }

    rate = rate/100;
    rate = rate/12;
    double minimumPayment = loan * rate;

    while (payment <= minimumPayment)
    {
        cout << "Payment: ";
        cin >> payment;
    }

    // INITIALIZE VARIABLES

    double balance = loan;
    double interest = 0;
    double totalInterest = 0;
    double principal = 0;
    int currentMonth;

    cout << endl;

    // AMORTIZATION TABLE

    cout << "*****************************************************************\n"
         << "\tAmortization Table\n"
         << "*****************************************************************\n"
         << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

         //loop to fill table
    while(balance > 0)
    {
        if(currentMonth==0)
        {
            cout<< currentMonth << "\t$" << loan;

            cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
        }
            currentMonth++;
            interest = balance * rate;
            totalInterest = totalInterest + interest;

            if (payment > balance + interest)
            {
                payment = balance + interest;
            }

            principal = payment - interest;
            balance = balance - principal;

            cout << currentMonth << "\t$" << balance << "\t\t$" << payment << "\t" << rate * 100 << "\t$" << interest << "\t\t$" << principal << endl;
    }

    cout <<"*******************************************************\n";
    cout <<"\nIt takes " <<currentMonth << " months to pay off "
         <<"the loan. \n"
         <<"Total interest paid is: $" << totalInterest;
   cout << endl << endl;
   return 0;
}
