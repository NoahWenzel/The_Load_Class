// this tells catch to provide a main()
// only do this in one cpp file
#include "../externals/catch2/catch.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include "flat.h"

//**** Flat Getting Started: setters, getters, constructors *********

TEST_CASE(
    "Default constructor sets address name to unknown, weight to 2, length to "
    "12, is delivered to false, height to 8, and thickness to .25.",
    "[shipping_item],[start]") {
  Flat flat;
  Address address = flat.get_address();

  REQUIRE(address.name == "unknown");
  REQUIRE(fabs(flat.get_weight() - 2) < .001);
  REQUIRE(fabs(flat.get_length() - 12) < .001);
  REQUIRE(flat.get_delivered() == false);
  REQUIRE(fabs(flat.get_height() - 8) < .001);
  REQUIRE(fabs(flat.get_thickness() - .4) < .001);
}

TEST_CASE(
    "Non-default constructor for Flat sets all values to values sent when they "
    "are all within allowed ranges.",
    "[shipping_item],[start]") {
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  Flat flat(address, 4.3, 12.19, 8.2, .38);

  REQUIRE(flat.get_address().name == "Howdy");
  REQUIRE(flat.get_address().street_address == "17 West Center");
  REQUIRE(flat.get_address().city == "Wilson");
  REQUIRE(flat.get_address().state == "NC");
  REQUIRE(flat.get_address().zip == "23127");

  REQUIRE(fabs(flat.get_weight() - 4.3) < .001);
  REQUIRE(fabs(flat.get_length() - 12.19) < .001);

  // if (flat.delivered()) {
  //   REQUIRE("true" == "true");
  // } else {
  //   REQUIRE("false" == "true");
  // }

  REQUIRE(flat.get_delivered() == false);
  REQUIRE(fabs(flat.get_height() - 8.2) < .001);
  REQUIRE(fabs(flat.get_thickness() - .38) < .001);
}

TEST_CASE(
    "Non-default constructor throws exception when weight is "
    "less than 0",
    "[shipping_item],[flat],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Flat flat(address, -1, 11, 9, .3);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Non-default constructor throws exception when weight is "
    "greater than 70",
    "[shipping_item],[flat],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Flat flat(address, 71, 11, 9, .3);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Non-default constructor throws exception when length is "
    "less than .007",
    "[shipping_item],[flat],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Flat flat(address, 8, .005, 9, .3);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Non-default constructor throws exception when length is "
    "greater than 15",
    "[shipping_item],[flat],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Flat flat(address, 8, 15.2, 9, .3);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Non-default constructor throws exception when height is "
    "less than .007",
    "[shipping_item],[flat],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Flat flat(address, 8, 13, .005, .3);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Non-default constructor throws exception when height is "
    "greater than 12",
    "[shipping_item],[flat],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Flat flat(address, 8, 13, 12.2, .3);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Non-default constructor throws exception when thickness is "
    "less than .007",
    "[shipping_item],[flat],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Flat flat(address, 8, 13, 7.2, .006);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Non-default constructor throws exception when thickness is "
    "greater than .75",
    "[shipping_item],[flat],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Flat flat(address, 8, 13, 7.2, .78);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Address setter sets address to values in parameter Address when used with "
    "a Flat object",
    "[shipping_item],[flat],[start]") {
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  Flat flat;
  flat.set_address(address);

  REQUIRE(address.name == "Howdy");
  REQUIRE(address.street_address == "17 West Center");
  REQUIRE(address.city == "Wilson");
  REQUIRE(address.state == "NC");
  REQUIRE(address.zip == "23127");
}

TEST_CASE(
    "Weight setter sets weight to value in parameter when used with a Flat "
    "object",
    "[shipping_item],[flat],[start]") {
  Flat flat;
  flat.set_weight(12.93);

  REQUIRE(fabs(flat.get_weight() - 12.93) < .001);
}

TEST_CASE(
    "Weight setter throws exception when weight value is less than 0 when used "
    "with a Flat object",
    "[shipping_item],[flat],[start]") {
  Flat flat;

  REQUIRE_THROWS_AS(flat.set_weight(-.1), std::out_of_range);
}

TEST_CASE(
    "Delivered setter sets delivered to true when parameter is true when used "
    "with a Flat object",
    "[shipping_item],[flat],[start]") {
  Flat flat;
  flat.set_delivered(true);

  REQUIRE(flat.get_delivered() == true);
}

TEST_CASE(
    "Delivered setter sets delivered to false when parameter is false when "
    "used with a Flat object",
    "[shipping_item],[flat],[start]") {
  Flat flat;
  flat.set_delivered(false);

  REQUIRE(flat.get_delivered() == false);
}

//******************** setters ********************************************
TEST_CASE(
    "set_length method sets length to value sent when used with a Flat object",
    "[flat],[setters]") {
  Flat flat;
  flat.set_length(11.3);

  REQUIRE(fabs(flat.get_length() - 11.3) < .001);
}

TEST_CASE(
    "set_length method throws exception when length sent is less than .007.",
    "[flat],[setters]") {
  Flat flat;

  REQUIRE_THROWS_AS(flat.set_length(.006), std::out_of_range);
}

TEST_CASE(
    "set_length method throws exception when length sent is -2 when used with "
    "a Flat object.",
    "[flat],[setters]") {
  Flat flat;

  REQUIRE_THROWS_AS(flat.set_length(-2), std::out_of_range);
}

TEST_CASE(
    "set_length method throws exception when length sent is greater than 15",
    "[flat],[setters]") {
  Flat flat;

  REQUIRE_THROWS_AS(flat.set_length(15.2), std::out_of_range);
}

TEST_CASE(
    "set_height method sets width to value sent when used with a Flat object.",
    "[flat],[setters]") {
  Flat flat;
  flat.set_height(9.3);

  REQUIRE(fabs(flat.get_height() - 9.3) < .001);
}

TEST_CASE(
    "set_height method throws exception when height sent is less than .007.",
    "[flat],[setters]") {
  Flat flat;

  REQUIRE_THROWS_AS(flat.set_height(.006), std::out_of_range);
}

TEST_CASE(
    "set_height method throws exception when height sent is -2 when used with "
    "a Flat object.",
    "[flat],[setters]") {
  Flat flat;

  REQUIRE_THROWS_AS(flat.set_height(-2), std::out_of_range);
}

TEST_CASE(
    "set_height method throws exception when height sent is greater than 12.",
    "[flat],[setters]") {
  Flat flat;

  REQUIRE_THROWS_AS(flat.set_height(12.2), std::out_of_range);
}

TEST_CASE("set_thickness method sets thickness to value sent.",
          "[flat],[setters]") {
  Flat flat;
  flat.set_thickness(.3);

  REQUIRE(fabs(flat.get_thickness() - .3) < .001);
}

TEST_CASE(
    "set_thickness method throws exception when thickness sent is less than "
    ".007.",
    "[flat],[setters]") {
  Flat flat;

  REQUIRE_THROWS_AS(flat.set_thickness(0.006), std::out_of_range);
}

TEST_CASE("set_thickness method throws exception when height sent is -2.",
          "[flat],[setters]") {
  Flat flat;

  REQUIRE_THROWS_AS(flat.set_thickness(-2), std::out_of_range);
}

TEST_CASE(
    "set_thickness method throws exception when thickness sent is greater than "
    ".75.",
    "[flat],[setters]") {
  Flat flat;

  REQUIRE_THROWS_AS(flat.set_thickness(.78), std::out_of_range);
}

//******************* Volume *****************************

TEST_CASE("Volume method returns 38.4 when default constructor is used.",
          "[flat],[volume]") {
  Flat flat;

  REQUIRE(fabs(flat.Volume() - 38.4) < .001);
}

TEST_CASE("Volume method returns 71.2908 when values are  2.4, 13.8, 8.2, .63.",
          "[flat],[volume]") {
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  Flat flat(address, 2.4, 13.8, 8.2, .63);

  REQUIRE(flat.get_address().name == "Howdy");
  REQUIRE(flat.get_address().street_address == "17 West Center");
  REQUIRE(flat.get_address().city == "Wilson");
  REQUIRE(flat.get_address().state == "NC");
  REQUIRE(flat.get_address().zip == "23127");

  REQUIRE(fabs(flat.get_weight() - 2.4) < .001);
  REQUIRE(fabs(flat.get_length() - 13.8) < .001);
  REQUIRE(flat.get_delivered() == false);
  REQUIRE(fabs(flat.get_height() - 8.2) < .001);
  REQUIRE(fabs(flat.get_thickness() - .63) < .001);

  REQUIRE(fabs(flat.Volume() - 71.2908) < .001);
}

//**************** Display *********************************

TEST_CASE("Display writes 'Flat: 2.0 lbs. 12.0 x 8.0 x 0.4' for default Flat.",
          "[shipping_item],[carton],[mark_delivered]") {
  Flat flat;
  std::ofstream out("../../tests/output.txt");

  flat.Display(out);
  out.close();

  std::ifstream in("../../tests/output.txt");
  std::string line;

  std::getline(in, line);

  REQUIRE(line == "Flat: 2.0 lbs. 12.0 x 8.0 x 0.4");
}

TEST_CASE(
    "Display writes 'Flat: 4.2 lbs. 13.0 x 8.6 x 0.5' for "
    "Flat with (address, 4.2, 13, 8.6, .5).",
    "[shipping_item],[carton],[mark_delivered]") {
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  Flat flat(address, 4.2, 13, 8.6, .5);
  std::ofstream out("../../tests/output.txt");

  flat.Display(out);
  out.close();

  std::ifstream in("../../tests/output.txt");
  std::string line;

  std::getline(in, line);

  REQUIRE(line == "Flat: 4.2 lbs. 13.0 x 8.6 x 0.5");
}
