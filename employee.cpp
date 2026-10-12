// This is the model of an employee
// The employee has a name, a salary, and may have a credit card
// The credit card has a current balance, a previous balance, a credit limit, and an available credit
// The employee class has a pointer to a credit card, which is an association relationship

#include<iostream>
#include<string>

using namespace::std;

class creditCard {
    public:
    creditCard(float b, float l) : currentBalance(b), creditLimit(l) {
        previousBalance = 0.0f; // Assumes the previous balance is zero when the card is first created
        availableCredit = creditLimit - currentBalance;
    }
    float getCurrentBalance() const {return currentBalance;}
    float getPreviousBalance() const {return previousBalance;}
    float getCreditLimit() const {return creditLimit;}
    float getAvailableCredit() const {return availableCredit;}
    void makePurchase(float amount) {
        if (amount <= availableCredit) {
            currentBalance += amount;
            availableCredit -= amount;
        } else {
            cout << "Purchase exceeds available credit." << endl;
        }
    }
    void makePayment(float amount) {
        currentBalance -= amount;
        availableCredit += amount;
    }

    private:
    float currentBalance;
    float previousBalance; // Also called "Statement Balance", the balance at the end of the last billing cycle
    float creditLimit; // the most you can owe on the card
    float availableCredit; // the credit limit minus the current balance and pending charges

};

class employee {
    public:
    // Association: the employee only refers to a card it does not own, so the card
    // can exist independently, be shared, or be absent (nullptr)
    employee(string n, float s, creditCard* c = nullptr) : name(n), salary(s), card(c) {}
    string getName() const {return name;}
    float getSalary() const {return salary;}
    creditCard* getCreditCard() const {return card;}
    bool hasCreditCard() const {return card != nullptr;}
    void setCreditCard(creditCard* c) {card = c;}

    private:
    string name;
    float salary;
    creditCard* card; // non-owning; the card's lifetime is managed outside the employee
};

int main() {
    creditCard card(1000.0f, 2000.0f);
    employee marco("Marco", 50000.0f, &card);

    // Printing the employee's information
    cout << "Employee Information:" << endl;
    cout << "Name: " << marco.getName() << endl <<"Salary: " << marco.getSalary() << endl;
    cout << "Credit Card Information:" << endl;
    if (marco.hasCreditCard()) {
        cout << "The current balance of the employee's credit card is: " << marco.getCreditCard()->getCurrentBalance() << endl;
        cout << "The previous balance of the employee's credit card is: " << marco.getCreditCard()->getPreviousBalance() << endl;
        cout << "The credit limit of the employee's credit card is: " << marco.getCreditCard()->getCreditLimit() << endl;
        cout << "The available credit of the employee's credit card is: " << marco.getCreditCard()->getAvailableCredit() << endl;
    } else {
        cout << "The employee has no credit card." << endl;
    }

    return 0;
}