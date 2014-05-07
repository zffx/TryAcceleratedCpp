#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::setprecision;
using std::string;
using std::endl;
using std::streamsize;
using std::vector;

int main()
{
    cout << "Please enter your first name" << endl;
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" <<endl;

    // ask for and read the midterm and final grades
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    // ask for the homework grades
    cout << "Enter all your homework grades,"
            "followed by end-of-file: ";

    vector<double> homework;
    typedef vector<double>::size_type vec_sz;
    double x;

    while (cin >> x) {
        homework.push_back(x);
    }
    vec_sz size = homework.size();
    if (size == 0) {
            cout << endl << "You must enter your grades.  "
                            "Please try again." << endl;
            return 1;
    }
    sort (homework.begin(), homework.end());

    vec_sz mid = size/2;
    double median;
    median = size % 2 == 0 ? (homework[mid-1] + homework[mid]) / 2
                           : homework[mid];


    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * median
         << setprecision(prec) << endl;

    return 0;
}
