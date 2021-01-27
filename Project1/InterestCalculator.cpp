/*

* Vijay Krishnamoorthy (vzk0023)
* project1_krishnamoorthy_vzk0023.cpp

* compile using g++ -o interestcalculator project1_krishnamoorthy_vzk0023.cpp
* run using ./interestcalculator

* Learned C++ Fundamentals from Dr.Li's Lectures and StackOverflow.
* Learned how to use cin.clear() and cin.ignore() from StackOverflow.
* Me and Ian Larson (irl0006) verbally discussed how to do the output properly.
* Me and Ian Larson varbally discussed how to check interest rate inputs.

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
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // I learned how to use this from StackOverflow.

        if (loan <= 0)
        {
            cout << "Please Input a Positive Numeric Value!" << endl;
        }
    }

    // ME AND IAN VARBALLY DISCUSSED THIS SOLUTION TOGETHER

    bool rateCheck = false;

    while (rateCheck == false)
    {
        cout << "Interest Rate (% per year): ";
        if (cin >> rate)
        {
            if (rate < 0)
            {
                rateCheck = false;
                cout << "Please Input a Nonnegative Numeric Value!" << endl;
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
            cout << "Please Input a Nonnegative Numeric Value!" << endl;
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
            cout << "Please Input a Monthly Payment that Would Cover the Minimum Payment!" << endl;
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

            // ME AND IAN LARSON VERBALLY DISCUSSED HOW TO DO THIS

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
