#include <iostream>
#include "classes.h"
#include "templateClasses.h"
using namespace std;
int main()
{
    //Custom set tests
    CustomSet customSet(0, 10, "abcd");
    CardinalitySet cardinalitySet(0, 10, "abcd");
    customSet.addElement(0);
    customSet.addElement(3);
    customSet.addElement(5);
    customSet.addElement(8);
    customSet.addElement(9);
    customSet.addElement('b');
    customSet.addElement('c');
    cout << "Custom set tests: " << endl;
    cout << customSet.isIncluded(3) << endl;
    cout << customSet.isIncluded('b') << endl;
    cout << customSet.isIncluded('e') << endl;
    cout << customSet.isIncluded('1') << endl;
    customSet.printAll();
    cout << "Cardinality: " << cardinalitySet.getCardinality() << endl << endl;
    //Template set tests
    TCustomSet<TElement> tCustomSet(0, 10, "abcd");
    TCardinalitySet tCardinalitySet(0, 10, "abcd");
    tCustomSet.addElement(0);
    tCustomSet.addElement(3);
    tCustomSet.addElement(5);
    tCustomSet.addElement(8);
    tCustomSet.addElement(9);
    tCustomSet.addElement('b');
    tCustomSet.addElement('c');
    cout << "Template set tests: " << endl;
    cout << tCustomSet.isIncluded(3) << endl;
    cout << tCustomSet.isIncluded('b') << endl;
    cout << tCustomSet.isIncluded('e') << endl;
    cout << tCustomSet.isIncluded('1') << endl;
    tCustomSet.printAll();
    cout << "Cardinality: " << tCardinalitySet.getCardinality() << endl;
    return 0;
}
