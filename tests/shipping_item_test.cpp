// this tells catch to provide a main()
// only do this in one cpp file
#include "../externals/catch2/catch.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include "carton.h"
#include "shipping_item.h"

//************** Address struct ******************************************

TEST_CASE("Address struct works when adding individual values.",
          "[shipping_item],[address]") {
  Address address;
  address.name = "Myra Butler";
  address.street_address = "192 South Water Way";
  address.city = "Ogden";
  address.state = "UT";
  address.zip = "84408";

  REQUIRE(address.name == "Myra Butler");
  REQUIRE(address.street_address == "192 South Water Way");
  REQUIRE(address.city == "Ogden");
  REQUIRE(address.state == "UT");
  REQUIRE(address.zip == "84408");
}

TEST_CASE("Address struct works when initializing values.",
          "[shipping_item],[address]") {
  Address address = {"Myra Butler", "192 South Water Way", "Ogden", "UT",
                     "84408"};

  REQUIRE(address.name == "Myra Butler");
  REQUIRE(address.street_address == "192 South Water Way");
  REQUIRE(address.city == "Ogden");
  REQUIRE(address.state == "UT");
  REQUIRE(address.zip == "84408");
}

//************* static member variables ****************************

TEST_CASE(
    "Static member variables are defined and set as expected: kMaxWeight = 70, "
    "kMaxSize = 108, kMinSize = .007.",
    "[shipping_item],[static]") {
  REQUIRE(ShippingItem::kMaxWeight == 70);
  REQUIRE(ShippingItem::kMaxSize == 108);
  REQUIRE(ShippingItem::kMinSize == .007);
}

//**** ShippingItem Getting Started: setters, getters, constructors *********

TEST_CASE(
    "Default constructor sets address name to unknown, weight to 2, length to "
    "12, and is delivered to false.",
    "[shipping_item],[start]") {
  Carton carton;
  Address address = carton.get_address();

  REQUIRE(address.name == "unknown");
  REQUIRE(fabs(carton.get_weight() - 2) < .001);
  REQUIRE(fabs(carton.get_length() - 12) < .001);
  REQUIRE(carton.get_delivered() == false);
}

TEST_CASE(
    "Non-default constructor for Carton sets address name to unknown, weight "
    "to 2, is delivered to false, and length, width, and height to values "
    "sent.",
    "[shipping_item],[start]") {
  Carton carton(22.19, 38.2, 15.1);
  Address address = carton.get_address();

  REQUIRE(address.name == "unknown");
  REQUIRE(fabs(carton.get_weight() - 2) < .001);
  REQUIRE(carton.get_delivered() == false);

  REQUIRE(fabs(carton.get_length() - 38.2) < .001);
  if (carton.get_width() < carton.get_height()) {
    REQUIRE(fabs(carton.get_width() - 15.1) < .001);
    REQUIRE(fabs(carton.get_height() - 22.19) < .001);
  } else {
    REQUIRE(fabs(carton.get_width() - 22.19) < .001);
    REQUIRE(fabs(carton.get_height() - 15.1) < .001);
  }
}

TEST_CASE(
    "Non-default constructor for Carton sets address name to unknown, weight "
    "to 2, length to 12, and is delivered to false.",
    "[shipping_item],[carton],[start]") {
  Carton carton(22.19, 38.2, 15.1);
  Address address = carton.get_address();

  REQUIRE(address.name == "unknown");
  REQUIRE(fabs(carton.get_weight() - 2) < .001);
  REQUIRE(carton.get_delivered() == false);

  REQUIRE(fabs(carton.get_length() - 38.2) < .001);
  if (carton.get_width() < carton.get_height()) {
    REQUIRE(fabs(carton.get_width() - 15.1) < .001);
    REQUIRE(fabs(carton.get_height() - 22.19) < .001);
  } else {
    REQUIRE(fabs(carton.get_width() - 22.19) < .001);
    REQUIRE(fabs(carton.get_height() - 15.1) < .001);
  }
}

TEST_CASE(
    "Second non-default constructor throws exception when first side value is "
    ".006",
    "[shipping_item],[carton],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Carton carton(address, 8, .006, 13.91, 22.3);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Second non-default constructor throws exception when first side value is "
    "negative",
    "[shipping_item],[carton],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Carton carton(address, 8, -.5, 13.91, 22.3);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Second non-default constructor throws exception when second side value is "
    ".006",
    "[shipping_item],[carton],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Carton carton(address, 8, 13.91, .006, 22.3);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Second non-default constructor throws exception when second side value is "
    "less than negative",
    "[shipping_item],[carton],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Carton carton(address, 8, 13.91, -2, 22.3);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Second non-default constructor throws exception when third side value is "
    ".006",
    "[shipping_item],[carton],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Carton carton(address, 8, 13.91, 22.3, .006);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Second non-default constructor throws exception when third side value is "
    "negative",
    "[shipping_item],[carton],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Carton carton(address, 8, 13.91, 22.3, -.2);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Second non-default constructor throws exception when weight value is "
    "negative",
    "[shipping_item],[carton],[start]") {
  std::string exception_thrown;
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  try {
    Carton carton(address, -.2, 8.2, 13.91, 22.3);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE("Address setter sets address to values in parameter Address",
          "[shipping_item],[carton],[start]") {
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  Carton carton;
  carton.set_address(address);

  REQUIRE(address.name == "Howdy");
  REQUIRE(address.street_address == "17 West Center");
  REQUIRE(address.city == "Wilson");
  REQUIRE(address.state == "NC");
  REQUIRE(address.zip == "23127");
}

TEST_CASE("Weight setter sets weight to value in parameter",
          "[shipping_item],[carton],[start]") {
  Carton carton;
  carton.set_weight(12.93);

  REQUIRE(fabs(carton.get_weight() - 12.93) < .001);
}

TEST_CASE("Weight setter throws exception when weight value is less than 0",
          "[shipping_item],[carton],[start]") {
  Carton carton;

  REQUIRE_THROWS_AS(carton.set_weight(-.1), std::out_of_range);
}

TEST_CASE("Delivered setter sets delivered to true when parameter is true",
          "[shipping_item],[carton],[start]") {
  Carton carton;
  carton.set_delivered(true);

  REQUIRE(carton.get_delivered() == true);
}

TEST_CASE("Delivered setter sets delivered to false when parameter is false",
          "[shipping_item],[carton],[start]") {
  Carton carton;
  carton.set_delivered(false);

  REQUIRE(carton.get_delivered() == false);
}

//****************  MarkDelivered *********************************
TEST_CASE(
    "MarkDelivered sets delivered to true when delivered was previously set to "
    "true",
    "[shipping_item],[carton],[mark_delivered]") {
  Carton carton;
  carton.set_delivered(true);
  carton.MarkDelivered();

  REQUIRE(carton.get_delivered() == true);
}

TEST_CASE(
    "MarkDelivered sets delivered to true when delivered was previously set to "
    "false",
    "[shipping_item],[carton],[mark_delivered]") {
  Carton carton;
  carton.set_delivered(false);
  carton.MarkDelivered();

  REQUIRE(carton.get_delivered() == true);
}

//**************** Display *********************************

TEST_CASE(
    "Display writes 'Carton: 2.0 lbs. 12.0 x 12.0 x 12.0' for default Carton.",
    "[shipping_item],[carton],[mark_delivered]") {
  Carton carton;
  std::ofstream out("../../tests/output.txt");

  carton.Display(out);
  out.close();

  std::ifstream in("../../tests/output.txt");
  std::string line;

  std::getline(in, line);

  REQUIRE(line == "Carton: 2.0 lbs. 12.0 x 12.0 x 12.0");
}

TEST_CASE(
    "Display writes Carton: 41.4 lbs. 31.2 x 8.6 x 8.6 for default"
    "Carton.",
    "[shipping_item],[carton],[mark_delivered]") {
  Address address = {"Howdy", "17 West Center", "Wilson", "NC", "23127"};
  Carton carton(address, 41.36, 31.22, 8.6, 8.62);
  std::ofstream out("../../tests/output.txt");

  carton.Display(out);
  out.close();

  std::ifstream in("../../tests/output.txt");
  std::string line;

  std::getline(in, line);

  REQUIRE(line == "Carton: 41.4 lbs. 31.2 x 8.6 x 8.6");
}

//***************** setters are updated to kMinSize ****************
TEST_CASE("set_length method sets length to value sent now.",
          "[carton],[setters]") {
  Carton carton;
  carton.set_length(31.3);

  REQUIRE(fabs(carton.get_length() - 31.3) < .001);
}

TEST_CASE("set_length method throws exception when length sent is 0.006.",
          "[carton],[setters]") {
  Carton carton;

  REQUIRE_THROWS_AS(carton.set_length(0.006), std::out_of_range);
}

TEST_CASE("set_width method sets width to value sent now.",
          "[carton],[setters]") {
  Carton carton;
  carton.set_width(11.3);

  REQUIRE(fabs(carton.get_width() - 11.3) < .001);
}

TEST_CASE("set_width method throws exception when width sent is 0.006.",
          "[carton],[setters]") {
  Carton carton;

  REQUIRE_THROWS_AS(carton.set_width(0.006), std::out_of_range);
}

TEST_CASE("set_height method sets height to value sent now.",
          "[carton],[setters]") {
  Carton carton;
  carton.set_height(11.3);

  REQUIRE(fabs(carton.get_height() - 11.3) < .001);
}

TEST_CASE("set_height method throws exception when height sent is 0.006.",
          "[carton],[setters]") {
  Carton carton;

  REQUIRE_THROWS_AS(carton.set_height(0.006), std::out_of_range);
}

TEST_CASE("Set measurements throws exception when first value is 0.006",
          "[carton],[start]") {
  Carton carton;
  REQUIRE_THROWS_AS(carton.set_measurements(0.006, 13.91, 22.3),
                    std::out_of_range);
}

TEST_CASE("Set measurements throws exception when second value is 0.006",
          "[carton],[start]") {
  Carton carton;
  REQUIRE_THROWS_AS(carton.set_measurements(13.91, 0.006, 22.3),
                    std::out_of_range);
}

TEST_CASE("Set measurements throws exception when third value is 0.006",
          "[carton],[start]") {
  Carton carton;
  REQUIRE_THROWS_AS(carton.set_measurements(13.91, 22.3, 0.006),
                    std::out_of_range);
}
