/* 
 * This is the model of an employee
*/

#include<iostream>
#include<string>

using namespace::std;

class employee {
    public:
    employee(string n, int s) : name(n), salary(s) {}
    string getName() const {return name;}
    int getSalary() const {return salary;}

    private:
    string name;
    int salary;
};

int main() {


    return 0;
}