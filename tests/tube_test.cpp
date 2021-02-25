// this tells catch to provide a main()
// only do this in one cpp file
#include "../externals/catch2/catch.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include "tube.h"

//************* static member variable ****************************

TEST_CASE(
    "Static member variable is defined and set as expected: kPi = 3.14159",
    "[shipping_item],[static]") {
  REQUIRE(Tube::kPi == 3.14159);
}

//**** Tube Getting Started: setters, getters, constructors *********

TEST_CASE(
    "Default constructor sets address name to unknown, weight to 2, length to "
    "12, is delivered to false, circumference to 12.",
    "[shipping_item],[start]") {
  Tube tube;
  Address address = tube.get_address();

  REQUIRE(address.name == "unknown");
  REQUIRE(fabs(tube.get_weight() - 2) < .001);
  REQUIRE(fabs(tube.get_length() - 12) < .001);
  REQUIRE(tube.get_delivered() == false);
  REQUIRE(fabs(tube.get_circumference() - 12) < .001);
}

TEST_CASE(
    "Non-default constructor for Tube sets all values to values sent when they "
    "are all within allowed ranges.",
    "[shipping_item],[start]") {
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  Tube tube(address, 4.3, 12.19, 8.2);

  REQUIRE(tube.get_address().name == "Howdy");
  REQUIRE(tube.get_address().street_address == "17 West Center");
  REQUIRE(tube.get_address().city == "Wilson");
  REQUIRE(tube.get_address().state == "NC");
  REQUIRE(tube.get_address().zip == "23127");

  REQUIRE(fabs(tube.get_weight() - 4.3) < .001);
  REQUIRE(fabs(tube.get_length() - 12.19) < .001);
  REQUIRE(tube.get_delivered() == false);
  REQUIRE(fabs(tube.get_circumference() - 8.2) < .001);
}

TEST_CASE(
    "Non-default constructor throws exception when weight is "
    "less than 0 for the tube class",
    "[shipping_item],[tube],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Tube tube(address, -1, 11, 9);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Non-default constructor throws exception when weight is "
    "greater than 70 for the tube class",
    "[shipping_item],[tube],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Tube tube(address, 71, 11, 9);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Non-default constructor throws exception when length is "
    "less than .007 for the tube class",
    "[shipping_item],[tube],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Tube tube(address, 8, .005, 9);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Non-default constructor throws exception when length is "
    "greater than 108 for the tube class",
    "[shipping_item],[tube],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Tube tube(address, 8, 108.2, 9);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Non-default constructor throws exception when circumference is "
    "less than .007",
    "[shipping_item],[tube],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Tube tube(address, 8, 13, .005);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Non-default constructor throws exception when length + circumference is "
    "greater than 108",
    "[shipping_item],[tube],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Tube tube(address, 8, 103, 12.2);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Non-default constructor throws exception when length + circumference is "
    "greater than 108, tested again.",
    "[shipping_item],[tube],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Tube tube(address, 8, 13, 102.2);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

//******************** setters ********************************************
TEST_CASE(
    "Address setter sets address to values in parameter Address when used with "
    "a Tube object",
    "[shipping_item],[tube],[start]") {
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  Tube tube;
  tube.set_address(address);

  REQUIRE(address.name == "Howdy");
  REQUIRE(address.street_address == "17 West Center");
  REQUIRE(address.city == "Wilson");
  REQUIRE(address.state == "NC");
  REQUIRE(address.zip == "23127");
}

TEST_CASE(
    "Weight setter sets weight to value in parameter when used with a Tube "
    "object",
    "[shipping_item],[tube],[start]") {
  Tube tube;
  tube.set_weight(12.93);

  REQUIRE(fabs(tube.get_weight() - 12.93) < .001);
}

TEST_CASE(
    "Weight setter throws exception when weight value is less than 0 when used "
    "with a Tube object",
    "[shipping_item],[tube],[start]") {
  Tube tube;

  REQUIRE_THROWS_AS(tube.set_weight(-.1), std::out_of_range);
}

TEST_CASE(
    "Delivered setter sets delivered to true when parameter is true when used "
    "with a Tube object",
    "[shipping_item],[tube],[start]") {
  Tube tube;
  tube.set_delivered(true);

  REQUIRE(tube.get_delivered() == true);
}

TEST_CASE(
    "Delivered setter sets delivered to false when parameter is false when "
    "used with a Tube object",
    "[shipping_item],[tube],[start]") {
  Tube tube;
  tube.set_delivered(false);

  REQUIRE(tube.get_delivered() == false);
}

TEST_CASE(
    "set_length method sets length to value sent when used with a Tube object",
    "[tube],[setters]") {
  Tube tube;
  tube.set_length(11.3);

  REQUIRE(fabs(tube.get_length() - 11.3) < .001);
}

TEST_CASE(
    "set_length method throws exception when length sent is less than .007 for "
    "the tube class.",
    "[tube],[setters]") {
  Tube tube;

  REQUIRE_THROWS_AS(tube.set_length(.006), std::out_of_range);
}

TEST_CASE(
    "set_length method throws exception when length sent is -2 when used with "
    "a Tube object.",
    "[tube],[setters]") {
  Tube tube;

  REQUIRE_THROWS_AS(tube.set_length(-2), std::out_of_range);
}

TEST_CASE(
    "set_length method throws exception when length sent is greater than 108 "
    "for the tube class",
    "[tube],[setters]") {
  Tube tube;

  REQUIRE_THROWS_AS(tube.set_length(108.2), std::out_of_range);
}

TEST_CASE(
    "set_circumference method sets width to value sent when used with a Tube "
    "object.",
    "[tube],[setters]") {
  Tube tube;
  tube.set_circumference(9.3);

  REQUIRE(fabs(tube.get_circumference() - 9.3) < .001);
}

TEST_CASE(
    "set_circumference method throws exception when circumference sent is less "
    "than .007.",
    "[tube],[setters]") {
  Tube tube;

  REQUIRE_THROWS_AS(tube.set_circumference(.006), std::out_of_range);
}

TEST_CASE(
    "set_circumference method throws exception when height sent is -2 when "
    "used with "
    "a Tube object.",
    "[tube],[setters]") {
  Tube tube;

  REQUIRE_THROWS_AS(tube.set_circumference(-2), std::out_of_range);
}

TEST_CASE(
    "set_circumference method throws exception when length + circumference "
    "sent is greater than 108.",
    "[tube],[setters]") {
  Tube tube;

  REQUIRE_THROWS_AS(tube.set_circumference(102.2), std::out_of_range);
}

//******************* Volume *****************************

TEST_CASE("Volume method returns 137.51 when default constructor is used.",
          "[tube],[volume]") {
  Tube tube;

  REQUIRE(fabs(tube.Volume() - 137.51) < .001);
}

TEST_CASE("Volume method returns 73.84 when values are  2.4, 13.8, 8.2.",
          "[tube],[volume]") {
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  Tube tube(address, 2.4, 13.8, 8.2);

  REQUIRE(tube.get_address().name == "Howdy");
  REQUIRE(tube.get_address().street_address == "17 West Center");
  REQUIRE(tube.get_address().city == "Wilson");
  REQUIRE(tube.get_address().state == "NC");
  REQUIRE(tube.get_address().zip == "23127");

  REQUIRE(fabs(tube.get_weight() - 2.4) < .001);
  REQUIRE(fabs(tube.get_length() - 13.8) < .001);
  REQUIRE(tube.get_delivered() == false);
  REQUIRE(fabs(tube.get_circumference() - 8.2) < .001);

  REQUIRE(fabs(tube.Volume() - 73.84) < .001);
}

//******************* Girth *****************************

TEST_CASE("Girth method returns 12 when default constructor is used.",
          "[tube],[volume]") {
  Tube tube;

  REQUIRE(fabs(tube.Girth() - 12) < .001);
}

TEST_CASE("Girth method returns 8.2 when values are 2.4, 13.8, 8.2",
          "[tube],[volume]") {
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  Tube tube(address, 2.4, 13.8, 8.2);

  REQUIRE(tube.get_address().name == "Howdy");
  REQUIRE(tube.get_address().street_address == "17 West Center");
  REQUIRE(tube.get_address().city == "Wilson");
  REQUIRE(tube.get_address().state == "NC");
  REQUIRE(tube.get_address().zip == "23127");

  REQUIRE(fabs(tube.get_weight() - 2.4) < .001);
  REQUIRE(fabs(tube.get_length() - 13.8) < .001);
  REQUIRE(tube.get_delivered() == false);
  REQUIRE(fabs(tube.get_circumference() - 8.2) < .001);

  REQUIRE(fabs(tube.Girth() - 8.2) < .001);
}

//**************** Display *********************************

TEST_CASE(
    "Display writes 'Tube: 2.0 lbs. 12.0 x 12.0' for default Tube.",
    "[shipping_item],[carton],[mark_delivered]") {
  Tube tube;
  std::ofstream out("../../tests/output.txt");

  tube.Display(out);
  out.close();

  std::ifstream in("../../tests/output.txt");
  std::string line;

  std::getline(in, line);

  REQUIRE(line == "Tube: 2.0 lbs. 12.0 x 12.0");
}

TEST_CASE(
    "Display writes 'Tube: 11.4 lbs. 31.2 x 8.6' for "
    "Tube with (address, 11.36, 31.22, 8.6).",
    "[shipping_item],[carton],[mark_delivered]") {
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  Tube tube(address, 11.36, 31.22, 8.6);
  std::ofstream out("../../tests/output.txt");

  tube.Display(out);
  out.close();

  std::ifstream in("../../tests/output.txt");
  std::string line;

  std::getline(in, line);

  REQUIRE(line == "Tube: 11.4 lbs. 31.2 x 8.6");
}
