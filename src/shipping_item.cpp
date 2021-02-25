#include "shipping_item.h"
#include <stdexcept>
#include <iostream>

const double ShippingItem::kMaxWeight = 70;
const double ShippingItem::kMaxSize = 108;
const double ShippingItem::kMinSize = 0.007;

/**
 * @brief Default Constructor settings:
 *      address_.name = "unknown"
 *      (All other aspects of address are unassigned)
 *      weight_ = 2
 *      length_ = 12
 *      delivered_ = false
 */
ShippingItem::ShippingItem() {
    address_.name = "unknown";
    weight_ = 2;
    length_ = 12;
    delivered_ = false;
}

/**
 * @brief Non-Default Constructor of ShippingItem object
 * @param address - String to set Address
 * @param weight - double to set weight
 * @param length - double to set lenght
 */
ShippingItem::ShippingItem(Address address, double weight, double length) {
    set_address(address);
    set_weight(weight);
    set_length(length);
    set_delivered(false);
}

/**
 * @brief If the weight sent is less than 0 or greater than kMaxWeight
 *       it throws an out_of_range exception.
 * @param weight - double to set the weight of the ShippingItem
 */
void ShippingItem::set_weight(double weight) {
    if (weight < 0 || weight > kMaxWeight){
        throw std::out_of_range("Out of Range!");
        return;
    }

    weight_ = weight;
}

/**
 * @brief If the length sent is less than 0 or greater than kMaxSize or
 *          less than kMinSize it throws an out_of_range exception.
 * @param length - double to set the weight of the ShippingItem
 */
void ShippingItem::set_length(double length) {
    if (length < kMinSize || length > kMaxSize){
        throw std::out_of_range("Out of Range!");
        return;
    }

    length_ = length;
}