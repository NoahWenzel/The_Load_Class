#include "carton.h"
#include "flat.h"
#include "tube.h"
#include "load.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {


  cout << "Part 2.2: Use the Carton Class in Main.cpp\n";
  Address a1;

  // Create a Carton object using the new constructor.
  // When using this constructor, use try/catch blocks to handle
  // the exceptions.
  Carton c1;
    try{
        Carton temp(a1, 20.7, 12, 7, 23);
        c1 = temp;
    }
    catch(out_of_range &e){
        cout << e.what() << endl;
    }

  // Use the Carton object to call the getter and setter methods.
  // Print out the results to see that the methods are doing what is expected.
  // When calling the setters, use try/catch blocks to handle the exceptions.
    cout << c1.get_length() << endl;
    cout << c1.get_width() << endl;
    cout << c1.get_height() << endl;
    cout << c1.get_weight() << endl;
    cout << c1.get_delivered() << endl;

    c1.Display(cout);

    try{
        Carton temp;
        temp.set_measurements(12.3, 21.2, 17.388);
        a1.name = "What's his face...";
        temp.set_address(a1);
        temp.set_delivered(true);

        c1 = temp;
    }
    catch(out_of_range &e){
        cout << e.what() << endl;
    }

    // Use the Carton object to call the Display method to print to cout.
    c1.Display(cout);

  cout << "\nPart 3.3: Use the Flat Class in Main.cpp\n";

  // Create Flat objects using the default and non-default constructors.
  // When using the non-constructor, use try/catch blocks to handle the
  // exceptions.
    Flat f1;
    try{
        Flat temp(a1, 20.7, 12, 7, .4);
        f1 = temp;
        cout << "Delivered Status of f1 after temp: " << f1.get_delivered() << endl;
    }
    catch(out_of_range &e){
        cout << e.what() << endl;
    }

  // Use the Flat objects to call the getter and setter methods.
  // Print out the results to see how these getters and setters are working.
  // When calling the setters, use try/catch blocks to handle the exceptions.
    cout << f1.get_length() << endl;
    cout << f1.get_height() << endl;
    cout << f1.get_weight() << endl;
    cout << f1.get_delivered() << endl;

    f1.Display(cout);

    try{
        Flat temp;
        a1.name = "What's his face...";
        temp.set_address(a1);
        temp.set_delivered(true);

        f1 = temp;
    }
    catch(out_of_range &e){
        cout << e.what() << endl;
    }

  // Use the Flat objects to call the Volume and Display methods.
  // Print out the results to cout.
    cout << "The Volume of the flat: " << f1.Volume() << endl;
    cout << "Delivery Status of flat: " << f1.get_delivered() << endl;
    f1.Display(cout);


  cout << "\nPart 4.3: Use the Tube Class in Main.cpp";

  // 1. Create Tube objects using the default and non-default constructors.
  // When using the non-constructor, use try/catch blocks to handle the
  // exceptions.
    Tube t1;
    try{
        cout << "Howdy" << endl;
        Tube temp(a1, 20.7, 12, .00000001);
        t1 = temp;
    }
    catch(out_of_range &e){
        cout << e.what() << endl;
    }

  // Use the Tube objects to call the getter and setter methods.
  // Print out the results to see how these getters and setters are working.
  // When calling the setters, use try/catch blocks to handle the exceptions.
    cout << t1.get_length() << endl;
    cout << t1.get_weight() << endl;
    cout << "Circumference = " << t1.get_circumference() << endl;
    cout << t1.get_delivered() << endl;

    t1.Display(cout);

    try{
        Tube temp;
        temp.set_address(a1);
        temp.set_delivered(true);

        t1 = temp;
    }
    catch(out_of_range &e){
        cout << e.what() << endl;
    }

  // Use the Tube objects to call the Volume, Girth and Display methods.
  // Print out the results to cout.
    cout << "Volume of t1 = " << t1.Volume() << endl;
    cout << "Girth of t1 = " << t1.Girth() << endl;
    t1.Display(cout);


  cout << "\nPart 5.3: Use the Load Class in Main.cpp" << endl;
  // 1. Create a Load object.
    Load l1;
    string file = "../../load_1.txt";
    ofstream out("Output.txt");

  // 2. Use the Load object to call the getter methods.
  // Print out the results to see how these getters are working.
  // Do this right after the Load object is created and after it
  // is filled from the file.
    cout << "Before:" << endl;
    cout << l1.get_count() << endl;
    cout << l1.get_total_volume() << endl;
    cout << l1.get_total_weight() << endl;

  //3. Use the Load object to call the FillLoad method.
    l1.FillLoad(file);
  // Then call the DisplayNextDelivery, ItemDelivered, NotDeliverable,
  // HowManyDelivered, and HowManyNotDelivered methods multiple times
  // to see how these work when making deliveries.
    l1.DisplayNextDelivery(out);
    l1.ItemDelivered();
    l1.NotDeliverable();
    cout << "How many delivered: " << l1.HowManyDelivered() << endl;
    cout << "How many not delivered: " << l1.HowManyNotDelivered() << endl;
    l1.DisplayNextDelivery(out);
    l1.ItemDelivered();
    l1.NotDeliverable();
    cout << "How many delivered: " << l1.HowManyDelivered() << endl;
    cout << "How many not delivered: " << l1.HowManyNotDelivered() << endl;
    l1.DisplayNextDelivery(out);
    l1.ItemDelivered();
    cout << "How many delivered: " << l1.HowManyDelivered() << endl;
    cout << "How many not delivered: " << l1.HowManyNotDelivered() << endl;

    return 0;
}