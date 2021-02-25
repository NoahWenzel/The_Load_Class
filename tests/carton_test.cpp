// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "../externals/catch2/catch.hpp"

#include <cmath>
#include <iostream>
#include "carton.h"

//**** Carton Getting Started: set_measurements, constructors *****************

TEST_CASE(
    "Default constructor sets length to 12, width to 12, and height to 12.",
    "[carton],[start]") {
  Carton carton;

  REQUIRE(fabs(carton.get_length() - 12) < .001);
  REQUIRE(fabs(carton.get_width() - 12) < .001);
  REQUIRE(fabs(carton.get_height() - 12) < .001);
}

TEST_CASE(
    "Set measurements sets length to 22.3, and width and height to 5.82 and "
    "13.91 when "
    "13.91 when the largest value is first.",
    "[carton],[start]") {
  Carton carton;
  carton.set_measurements(22.3, 5.82, 13.91);

  REQUIRE(fabs(carton.get_length() - 22.3) < .001);
  if (carton.get_width() < carton.get_height()) {
    REQUIRE(fabs(carton.get_width() - 5.82) < .001);
    REQUIRE(fabs(carton.get_height() - 13.91) < .001);
  } else {
    REQUIRE(fabs(carton.get_width() - 13.91) < .001);
    REQUIRE(fabs(carton.get_height() - 5.82) < .001);
  }
}

TEST_CASE(
    "Set measurements sets length to 22.3, and width and height to 5.82 and "
    "13.91 when the largest value is second.",
    "[carton],[start]") {
  Carton carton;
  carton.set_measurements(5.82, 22.3, 13.91);

  REQUIRE(fabs(carton.get_length() - 22.3) < .001);
  if (carton.get_width() < carton.get_height()) {
    REQUIRE(fabs(carton.get_width() - 5.82) < .001);
    REQUIRE(fabs(carton.get_height() - 13.91) < .001);
  } else {
    REQUIRE(fabs(carton.get_width() - 13.91) < .001);
    REQUIRE(fabs(carton.get_height() - 5.82) < .001);
  }
}

TEST_CASE(
    "Set measurements sets length to 22.3, and width and height to 5.82 and "
    "13.91 when the largest value is third.",
    "[carton],[start]") {
  Carton carton;
  carton.set_measurements(5.82, 13.91, 22.3);

  REQUIRE(fabs(carton.get_length() - 22.3) < .001);
  if (carton.get_width() < carton.get_height()) {
    REQUIRE(fabs(carton.get_width() - 5.82) < .001);
    REQUIRE(fabs(carton.get_height() - 13.91) < .001);
  } else {
    REQUIRE(fabs(carton.get_width() - 13.91) < .001);
    REQUIRE(fabs(carton.get_height() - 5.82) < .001);
  }
}

TEST_CASE("Set measurements throws exception when first value is 0",
          "[carton],[start]") {
  Carton carton;
  REQUIRE_THROWS_AS(carton.set_measurements(0, 13.91, 22.3), std::out_of_range);
}

TEST_CASE("Set measurements throws exception when first value is less than 0",
          "[carton],[start]") {
  Carton carton;
  REQUIRE_THROWS_AS(carton.set_measurements(-2, 13.91, 22.3),
                    std::out_of_range);
}

TEST_CASE("Set measurements throws exception when second value is 0",
          "[carton],[start]") {
  Carton carton;
  REQUIRE_THROWS_AS(carton.set_measurements(13.91, 0, 22.3), std::out_of_range);
}

TEST_CASE("Set measurements throws exception when second value is less than 0",
          "[carton],[start]") {
  Carton carton;
  REQUIRE_THROWS_AS(carton.set_measurements(13.91, -3, 22.3),
                    std::out_of_range);
}

TEST_CASE("Set measurements throws exception when third value is 0",
          "[carton],[start]") {
  Carton carton;
  REQUIRE_THROWS_AS(carton.set_measurements(13.91, 22.3, 0), std::out_of_range);
}

TEST_CASE("Set measurements throws exception when third value is less than 0",
          "[carton],[start]") {
  Carton carton;
  REQUIRE_THROWS_AS(carton.set_measurements(13.91, 22.3, -1),
                    std::out_of_range);
}

TEST_CASE(
    "Non-default constructor sets length to 22.3, and width and height to 5.82 "
    "and 13.91 when the largest value is first.",
    "[carton],[start]") {
  Carton carton(22.3, 5.82, 13.91);

  REQUIRE(fabs(carton.get_length() - 22.3) < .001);
  if (carton.get_width() < carton.get_height()) {
    REQUIRE(fabs(carton.get_width() - 5.82) < .001);
    REQUIRE(fabs(carton.get_height() - 13.91) < .001);
  } else {
    REQUIRE(fabs(carton.get_width() - 13.91) < .001);
    REQUIRE(fabs(carton.get_height() - 5.82) < .001);
  }
}

TEST_CASE(
    "Non-default constructor sets length to 22.3, and width and height to 5.82 "
    "and 13.91 when the largest value is second.",
    "[carton],[start]") {
  Carton carton(5.82, 22.3, 13.91);

  REQUIRE(fabs(carton.get_length() - 22.3) < .001);
  if (carton.get_width() < carton.get_height()) {
    REQUIRE(fabs(carton.get_width() - 5.82) < .001);
    REQUIRE(fabs(carton.get_height() - 13.91) < .001);
  } else {
    REQUIRE(fabs(carton.get_width() - 13.91) < .001);
    REQUIRE(fabs(carton.get_height() - 5.82) < .001);
  }
}

TEST_CASE(
    "Non-default constructor sets length to 22.3, and width and height to 5.82 "
    "and 13.91 when the largest value is third.",
    "[carton],[start]") {
  Carton carton(5.82, 13.91, 22.3);

  REQUIRE(fabs(carton.get_length() - 22.3) < .001);
  if (carton.get_width() < carton.get_height()) {
    REQUIRE(fabs(carton.get_width() - 5.82) < .001);
    REQUIRE(fabs(carton.get_height() - 13.91) < .001);
  } else {
    REQUIRE(fabs(carton.get_width() - 13.91) < .001);
    REQUIRE(fabs(carton.get_height() - 5.82) < .001);
  }
}

TEST_CASE("Non-default constructor throws exception when first value is 0",
          "[carton],[start]") {
  std::string exception_thrown;
  try {
    Carton carton(0, 13.91, 22.3);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Non-default constructor throws exception when first value is less than 0",
    "[carton],[start]") {
  std::string exception_thrown;
  try {
    Carton carton(-1, 13.91, 22.3);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE("Non-default constructor throws exception when second value is 0",
          "[carton],[start]") {
  std::string exception_thrown;
  try {
    Carton carton(13.91, 0, 22.3);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Non-default constructor throws exception when second value is less than 0",
    "[carton],[start]") {
  std::string exception_thrown;
  try {
    Carton carton(13.91, -2, 22.3);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE("Non-default constructor throws exception when third value is 0",
          "[carton],[start]") {
  std::string exception_thrown;
  try {
    Carton carton(13.91, 22.3, 0);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

TEST_CASE(
    "Non-default constructor throws exception when third value is less than 0",
    "[carton],[start]") {
  std::string exception_thrown;
  try {
    Carton carton(13.91, 22.3, -.5);
    exception_thrown = "No exception thrown";
  } catch (std::exception e) {
    exception_thrown = "Exception thrown";
  }

  REQUIRE(exception_thrown == "Exception thrown");
}

/******************** setters ********************************************/
TEST_CASE("set_length method sets length to value sent.",
          "[carton],[setters]") {
  Carton carton;
  carton.set_length(31.3);

  REQUIRE(fabs(carton.get_length() - 31.3) < .001);
}

TEST_CASE("set_length method throws exception when length sent is 0.",
          "[carton],[setters]") {
  Carton carton;

  REQUIRE_THROWS_AS(carton.set_length(0), std::out_of_range);
}

TEST_CASE("set_length method throws exception when length sent is -2.",
          "[carton],[setters]") {
  Carton carton;

  REQUIRE_THROWS_AS(carton.set_length(-2), std::out_of_range);
}

TEST_CASE(
    "set_length method throws exception when length sent is less than width or "
    "height.",
    "[carton],[setters]") {
  Carton carton(31.23, 18.5, 7.3);

  REQUIRE_THROWS_AS(carton.set_length(18.2), std::out_of_range);
}

TEST_CASE(
    "set_length method throws exception when length sent is less than width or "
    "height again.",
    "[carton],[setters]") {
  Carton carton(31.23, 18.5, 7.3);

  REQUIRE_THROWS_AS(carton.set_length(7.28), std::out_of_range);
}

TEST_CASE("set_width method sets width to value sent.", "[carton],[setters]") {
  Carton carton;
  carton.set_width(11.3);

  REQUIRE(fabs(carton.get_width() - 11.3) < .001);
}

TEST_CASE("set_width method throws exception when width sent is 0.",
          "[carton],[setters]") {
  Carton carton;

  REQUIRE_THROWS_AS(carton.set_width(0), std::out_of_range);
}

TEST_CASE("set_width method throws exception when width sent is -2.",
          "[carton],[setters]") {
  Carton carton;

  REQUIRE_THROWS_AS(carton.set_width(-2), std::out_of_range);
}

TEST_CASE(
    "set_width method throws exception when width sent is greater than length.",
    "[carton],[setters]") {
  Carton carton;

  REQUIRE_THROWS_AS(carton.set_width(12.2), std::out_of_range);
}

TEST_CASE("set_height method sets height to value sent.",
          "[carton],[setters]") {
  Carton carton;
  carton.set_height(11.3);

  REQUIRE(fabs(carton.get_height() - 11.3) < .001);
}

TEST_CASE("set_height method throws exception when height sent is 0.",
          "[carton],[setters]") {
  Carton carton;

  REQUIRE_THROWS_AS(carton.set_height(0), std::out_of_range);
}

TEST_CASE("set_height method throws exception when height sent is -2.",
          "[carton],[setters]") {
  Carton carton;

  REQUIRE_THROWS_AS(carton.set_height(-2), std::out_of_range);
}

TEST_CASE(
    "set_width method throws exception when height sent is greater than "
    "length.",
    "[carton],[setters]") {
  Carton carton;

  REQUIRE_THROWS_AS(carton.set_height(12.2), std::out_of_range);
}

/******************* Volume *****************************/

TEST_CASE("Volume method returns 1728 when default constructor is used.",
          "[carton],[volume]") {
  Carton carton;

  REQUIRE(fabs(carton.Volume() - 1728) < .001);
}

TEST_CASE("Volume method returns 12865.762 when values are 31.7, 18.2, 22.3.",
          "[carton],[volume]") {
  Carton carton(31.7, 18.2, 22.3);

  REQUIRE(fabs(carton.Volume() - 12865.762) < .001);
}

/******************* Girth *****************************/

TEST_CASE("Girth method returns 48 when default constructor is used.",
          "[carton],[girth]") {
  Carton carton;

  REQUIRE(fabs(carton.Girth() - 48) < .001);
}

TEST_CASE("Girth method returns 81 when values are 31.7, 18.2, 22.3.",
          "[carton],[girth]") {
  Carton carton(31.7, 18.2, 22.3);

  REQUIRE(fabs(carton.Girth() - 81) < .001);
}

/******************* LengthPlusGirth *****************************/

TEST_CASE("LengthPlusGirth method returns 60 when default constructor is used.",
          "[carton],[length_girth]") {
  Carton carton;

  REQUIRE(fabs(carton.LengthPlusGirth() - 60) < .001);
}

TEST_CASE(
    "LengthPlusGirth method returns 112.7 when values are 31.7, 18.2, 22.3.",
    "[carton],[length_girth]") {
  Carton carton(31.7, 18.2, 22.3);

  REQUIRE(fabs(carton.LengthPlusGirth() - 112.7) < .001);
}

/******************* << operator friend method **************************/
TEST_CASE(
    "The << operator prints Cartons as Carton length x width x height with a "
    "precision of one digit after the decimal",
    "[insertion][carton]") {
  // test size
  Carton one(22, 7, 19.38);
  Carton two(8, 20, 9.54);

  std::ofstream out("test.out");
  out << one << std::endl;
  out << two << std::endl;
  out.close();

  std::ifstream in("test.out");
  std::string line;
  getline(in, line);
  if (fabs(one.get_width() - 7.0) < .001) {
    REQUIRE("Carton 22.0 x 7.0 x 19.4" == line);
  } else {
    REQUIRE("Carton 22.0 x 19.4 x 7.0" == line);
  }

  getline(in, line);

  if (fabs(one.get_width() - 8.0) < .001) {
    REQUIRE("Carton 20.0 x 8.0 x 9.5" == line);
  } else {
    REQUIRE("Carton 20.0 x 9.5 x 8.0" == line);
  }
  getline(in, line);
  REQUIRE("" == line);
}
