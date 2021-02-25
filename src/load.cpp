#include "load.h"
#include "flat.h"
#include "tube.h"
#include "carton.h"
#include "shipping_item.h"
#include <fstream>
#include <iostream>
#include <string>

/**
 * @brief This method is to read the data for each shipping item in the
 *       file, then add the weight of this item to the total weight, and
 *        add the volume of this item to the total volume.
 * @param filename - String that includes the path from the build folder
 *       and the file type extension.
 *      Ex. "../../load_.txt"
 */
void Load::FillLoad(std::string filename) {
    std::ifstream in(filename);
    if(in.fail()){
        std::cout << filename << " failed to open." << std::endl;
        std::cout << "Shutting Down......." << std::endl;
        return;
    }

    char type;
    Address tempAddress;
    double weight;
    double length;
    double height;
    double thickness;
    double side1;
    double side2;
    double side3;
    double circumference;
    double volume;

    while(in >> type) {
        in.ignore();
        getline(in, tempAddress.name);
        getline(in, tempAddress.street_address);
        getline(in, tempAddress.city);
        getline(in, tempAddress.state);
        getline(in, tempAddress.zip);

        if(type == 'F'){
            in >> weight;
            in >> length;
            in >> height;
            in >> thickness;
            Flat tempFlat(tempAddress, weight, length, height, thickness);
            volume = tempFlat.Volume();
            ShippingItemsVector_.push_back(new Flat(tempFlat));
        }
        else if(type == 'C'){
            in >> weight;
            in >> side1;
            in >> side2;
            in >> side3;
            Carton tempCarton(tempAddress, weight, side1, side2, side3);
            volume = tempCarton.Volume();
            ShippingItemsVector_.push_back(new Carton(tempCarton));
        }
        else if(type == 'T'){
            in >> weight;
            in >> length;
            in >> circumference;
            Tube tempTube(tempAddress, weight, length, circumference);
            volume = tempTube.Volume();
            ShippingItemsVector_.push_back(new Tube(tempTube));
        }

        ++loadSize_;
        totalWeight_ += weight;
        totalVolume_ += volume;
    }
    in.close();
}

/**
 * @breif Writes data of the current item being delivered to the
 *       given parameter.
 * @param out - An ofstream object. To specify where the data shall be
 *       written.
 */
void Load::DisplayNextDelivery(std::ofstream &out) const{
    ShippingItem* item;
    item = ShippingItemsVector_[indexBeingDelivered_];

    std::string name = item->get_address().name;
    std::string street = item->get_address().street_address;
    std::string city = item->get_address().city;
    std::string state = item->get_address().state;
    std::string zip = item->get_address().zip;


    out << name << std::endl;
    out << street << std::endl;
    out << city << ", " << state << " " << zip << std::endl;
    item->Display(out);
}

/**
 * @brief Sets the is delivered value of the current shipping item to
 *       true. Then it changes the current item to the next item in
 *       the vector.
 */
void Load::ItemDelivered(){
    ShippingItem* item;
    item = ShippingItemsVector_[indexBeingDelivered_];
    item->set_delivered(true);

    ++indexBeingDelivered_;
}

/**
 * @brief Leaves the is delivered value of the current item as false.
 *      Then it changes the current item to the next item in the
 *       vector.
 */
void Load::NotDeliverable() {
    ShippingItem* item;
    item = ShippingItemsVector_[indexBeingDelivered_];
    item->set_delivered(false);

    ++indexBeingDelivered_;
}

/**
 * @breif Loops through the shipping items and returns how many
 *       ShippingItems delivered are set to true.
 * @return Int of how many items have been delivered.
 */
int Load::HowManyDelivered() const {
    int delivered = 0;
    for(ShippingItem* item: ShippingItemsVector_){
        if(item->get_delivered() == true){
            ++delivered;
        }
    }
    return delivered;
}

/**
 * @breif Loops through the shipping items and returns how many
 *       ShippingItems delivered are set to false.
 * @return Int of how many items have not been delivered.
 */
int Load::HowManyNotDelivered() const {
    int notDelivered = 0;
    for(ShippingItem* item: ShippingItemsVector_){
        if(item->get_delivered() == false){
            ++notDelivered;
        }
    }
    return notDelivered;
}