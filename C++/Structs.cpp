#include <iostream>
#include <string>

using namespace std;

struct person {
  int age=0;
  string name="null";
  int number=0;
};

string nameInput = "null";

int main() {
    cout << "Enter a name: ";
    cin >> nameInput;

    if (nameInput == "null") {
        cout << "You entered null, please enter a valid name.\n";
        return 1; // Exit if the input is invalid
    }

    person group[] = {
      {13, nameInput, 2},
      {22, "bob", 3}, 
      {25, "rhys", 1}
    };

    cout << group[0].age <<"\n";
    cout << group[1].name <<"\n";
    cout << group[2].number <<"\n";

    return 0;
}