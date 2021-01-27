/*

* Vijay Krishnamoorthy (vzk0023)
* project1_krishnamoorthy_vzk0023.cpp

* compile using g++ -o interestcalculator project1_krishnamoorthy_vzk0023.cpp
* run using ./interestcalculator

* Me and Ian discussed how to do the output properly.

*/

#include <iostream>
#include <limits>
using namespace std;

int main()
{
    // CURRENCY FORMATTING

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    float loan = 0;
    float rate = NULL;
    float payment = 0;


    // USER INPUT

    while (loan <= 0)
    {
        cout << "Loan Amount: ";
        cin >> loan;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (loan <= 0)
        {
            cout << "Invalid Loan Amount!" << endl;
        }
    }

    bool rateCheck = false;

    while (rateCheck == false)
    {
        cout << "Interest Rate (% per year): ";
        if (cin >> rate)
        {
            if (rate < 0)
            {
                rateCheck = false;
                cout << "Invalid Interest Rate!" << endl;
            }
            else
            {
                rateCheck = true;
            }
        }
        else
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Interest Rate!" << endl;
        }
    }

    rate = rate/100;
    rate = rate/12;

    float minimumPayment = loan * rate;

    while (payment <= minimumPayment)
    {
        cout << "Monthly Payments: ";
        cin >> payment;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (payment <= minimumPayment)
        {
            cout << "Invalid Monthly Payment!" << endl;
        }
    }

    // INITIALIZE VARIABLES

    float balance = loan;
    float interest = 0;
    float totalInterest = 0;
    float principal = 0;
    int currentMonth = 0;

    cout << endl;

    // AMORTIZATION TABLE

    cout << "*****************************************************************\n"
         << "\tAmortization Table\n"
         << "*****************************************************************\n"
         << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

    // LOOP TO FILL TABLE

    while(balance > 0)
    {
        if(currentMonth == 0)
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

            // IAN LARSON HELPED ME FIGURE OUT THIS PORTION

            if (balance < 1000)
            {
                cout << currentMonth << "\t$" << balance << "\t\t$" << payment << "\t" << rate * 100 << "\t$" << interest << "\t\t$" << principal << endl;
            }
            else
            {
                cout << currentMonth << "\t$" << balance << "\t$" << payment << "\t" << rate * 100 << "\t$" << interest << "\t\t$" << principal << endl;
            }
    }

    cout <<"*******************************************************\n";
    cout <<"\nIt takes " <<currentMonth << " months to pay off "
         <<"the loan. \n"
         <<"Total interest paid is: $" << totalInterest;
   cout << endl << endl;
   return 0;
}
