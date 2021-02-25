#ifndef SHIPPING_ITEM_H
#define SHIPPING_ITEM_H

#include <string>
struct Address{
    std::string name;
    std::string street_address;
    std::string city;
    std::string state;
    std::string zip;
};

class ShippingItem{
protected:
    Address address_;
    double weight_;
    double length_;
    bool delivered_;
    double height_;
public:
    static const double kMaxWeight;
    static const double kMaxSize;
    static const double kMinSize;

    ShippingItem();
    ShippingItem(Address address, double weight, double length);
    ~ShippingItem() {}

    Address get_address() const {return address_;}
    double get_weight() const {return weight_;}
    double get_length() const {return length_;}
    bool get_delivered() const {return delivered_;}
    double get_height() const {return height_;}

    void set_address(Address address) {address_ = address;}
    void set_weight(double weight);
    virtual void set_length(double length);
    void set_delivered(bool delivered) {delivered_ = delivered;}

    void MarkDelivered() {delivered_ = true;}
    virtual double Volume() const = 0;
    virtual void Display(std::ostream &out) const = 0;

};

#endif