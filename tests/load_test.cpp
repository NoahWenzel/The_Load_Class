// this tells catch to provide a main()
// only do this in one cpp file
#include "../externals/catch2/catch.hpp"

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "load.h"

//*************constructor, getters ********************
TEST_CASE(
    "Default constructor sets total volume to 0, total weight to 0, and "
    "count to 0",
    "[load],[start]") {
  Load load;

  REQUIRE(load.get_count() == 0);
  REQUIRE(load.get_total_volume() == 0);
  REQUIRE(load.get_total_weight() == 0);
}

//*********** other methods **************************
//*******FillLoad, DisplayNextDelivery,ItemDelivered,NotDeliverable  **********
//******* HowManyDelivered, HowManyNotDelivered **************************
TEST_CASE(
    "FillLoad creates shipping items and accumulates count, total weight, and "
    "total volume. ItemDelivered sets delivered to true and increments count. "
    "NotDeliverable increments count. HowManyDelivered and HowManyNotDelivered "
    "count items with delivered set to true and false respectively.",
    "[load],[fill_load]") {
  Load load;
  load.FillLoad("../../tests/load_test.txt");

  REQUIRE(fabs(load.get_count() - 6) < .001);
  REQUIRE(fabs(load.get_total_volume() - 16601.372442) < .1);
  REQUIRE(fabs(load.get_total_weight() - 103.58) < .001);

  std::ofstream out("../../tests/output.txt");
  load.DisplayNextDelivery(out);
  REQUIRE(load.HowManyDelivered() == 0);
  REQUIRE(load.HowManyNotDelivered() == 6);
  load.ItemDelivered();
  REQUIRE(load.HowManyDelivered() == 1);
  REQUIRE(load.HowManyNotDelivered() == 5);
  load.DisplayNextDelivery(out);
  load.NotDeliverable();
  REQUIRE(load.HowManyDelivered() == 1);
  REQUIRE(load.HowManyNotDelivered() == 5);
  load.DisplayNextDelivery(out);
  load.ItemDelivered();
  REQUIRE(load.HowManyDelivered() == 2);
  REQUIRE(load.HowManyNotDelivered() == 4);
  load.DisplayNextDelivery(out);
  load.ItemDelivered();
  REQUIRE(load.HowManyDelivered() == 3);
  REQUIRE(load.HowManyNotDelivered() == 3);
  load.DisplayNextDelivery(out);
  load.ItemDelivered();
  REQUIRE(load.HowManyDelivered() == 4);
  REQUIRE(load.HowManyNotDelivered() == 2);
  load.DisplayNextDelivery(out);
  load.ItemDelivered();
  REQUIRE(load.HowManyDelivered() == 5);
  REQUIRE(load.HowManyNotDelivered() == 1);

  out.close();

  std::ifstream in("../../tests/output.txt");
  std::string line;

  std::getline(in, line);
  REQUIRE(line == "Renee Javens");
  std::getline(in, line);
  REQUIRE(line == "281 South Main");
  std::getline(in, line);
  REQUIRE(line == "Ogden, UT 84408");
  std::getline(in, line);
  REQUIRE(line == "Carton: 42.0 lbs. 24.0 x 18.0 x 18.0");
  std::getline(in, line);
  REQUIRE(line == "Rose Harrison");
  std::getline(in, line);
  REQUIRE(line == "302 South Main");
  std::getline(in, line);
  REQUIRE(line == "Ogden, UT 84408");
  std::getline(in, line);
  REQUIRE(line == "Flat: 0.7 lbs. 12.0 x 9.0 x 0.3");
  std::getline(in, line);
  REQUIRE(line == "Jeff Allen");
  std::getline(in, line);
  REQUIRE(line == "162 South Main");
  std::getline(in, line);
  REQUIRE(line == "Ogden, UT 84408");
  std::getline(in, line);
  REQUIRE(line == "Tube: 4.7 lbs. 19.0 x 6.3");
  std::getline(in, line);
  REQUIRE(line == "Cathy Setzer");
  std::getline(in, line);
  REQUIRE(line == "320 South Main");
  std::getline(in, line);
  REQUIRE(line == "Ogden, UT 84408");
  std::getline(in, line);
  REQUIRE(line == "Flat: 2.4 lbs. 14.0 x 8.0 x 0.5");
  std::getline(in, line);
  REQUIRE(line == "Gordon Pike");
  std::getline(in, line);
  REQUIRE(line == "328 South Main");
  std::getline(in, line);
  REQUIRE(line == "Ogden, UT 84408");
  std::getline(in, line);
  REQUIRE(line == "Carton: 51.0 lbs. 32.5 x 16.2 x 16.2");
  std::getline(in, line);
  REQUIRE(line == "Jeff Allison");
  std::getline(in, line);
  REQUIRE(line == "172 South Main");
  std::getline(in, line);
  REQUIRE(line == "Ogden, UT 84408");
  std::getline(in, line);
  REQUIRE(line == "Tube: 2.8 lbs. 28.0 x 8.2");
}