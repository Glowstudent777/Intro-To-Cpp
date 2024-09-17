/*****
 * Author: Glowstudent
 * Monthly Payments
 *****/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <locale>
#include <string>

using namespace std;

int main()
{
    float loanAmount, monthlyInterestRate, monthlyPayment, amountPaidBack, interestPaid;
    int numberOfPayments, spacing = 22, letters = 12;
    string rowOne = "Loan amount:", rowTwo = "Monthly interest rate:", rowThree = "Number of payments:", rowFour = "Monthly payment:", rowFive = "Amount paid back:", rowSix = "Interest paid:";

    cout << "Enter the loan amount: ";
    cin >> loanAmount;

    cout << "Enter the monthly interest rate (ex: 5%: 5): ";
    cin >> monthlyInterestRate;

    cout << "Enter the number of payments: ";
    cin >> numberOfPayments;

    monthlyInterestRate /= 100;
    monthlyPayment = (monthlyInterestRate * pow((monthlyInterestRate + 1), numberOfPayments)) / ((pow((monthlyInterestRate + 1), numberOfPayments)) - 1) * loanAmount;

    amountPaidBack = monthlyPayment * numberOfPayments;
    interestPaid = amountPaidBack - loanAmount;
    monthlyInterestRate *= 100;

    cout.imbue(locale(""));

    cout << "\n";
    cout << rowOne << setw(spacing - 3 - (rowOne.length() - letters)) << setprecision(2) << fixed << "$" << loanAmount << endl;
    cout << rowTwo << setw(spacing - (rowTwo.length() - letters)) << setprecision(2) << monthlyInterestRate << "%" << endl;
    cout << rowThree << setw(spacing - (rowThree.length() - letters + (to_string(numberOfPayments).length()))) << numberOfPayments << endl;
    cout << rowFour << setw(spacing - 3 - (rowFour.length() - letters)) << setprecision(2) << fixed << "$" << monthlyPayment << endl;
    cout << rowFive << setw(spacing - 3 - (rowFive.length() - letters)) << setprecision(2) << fixed << "$" << amountPaidBack << endl;
    cout << rowSix << setw(spacing - 3 - (rowSix.length() - letters)) << setprecision(2) << fixed << "$" << interestPaid << endl;

    return 0;
}