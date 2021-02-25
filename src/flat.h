#ifndef FLAT_H
#define FLAT_H

#include "shipping_item.h"
#include <iomanip>

class Flat : public ShippingItem {
public:
    Flat(): ShippingItem() {
        set_height(8);
        set_thickness(0.4);
    }
    Flat(Address address, double weight, double length,
         double height, double thickness): ShippingItem(address, weight, length) {
        try{
            set_length(length);
            set_height(height);
            set_thickness(thickness);
        }
        catch(std::out_of_range e){
            throw;
        }
    }
    ~Flat() {}

    double get_thickness() const {return thickness_;}

    void set_length(double length);
    void set_height(double height);
    void set_thickness(double thickness);

    double Volume() const;
    void Display(std::ostream &out) const;

private:
    double thickness_;
};

#endif