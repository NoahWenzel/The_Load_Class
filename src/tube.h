#ifndef TUBE_H
#define TUBE_H
#include "shipping_item.h"
#include <iomanip>

class Tube: public ShippingItem{
public:
    static const double kPi;

    Tube(): ShippingItem() {
        set_circumference(12);
    }
    Tube(Address address, double weight, double length, double circumference):
        ShippingItem(address, weight, length){
        try{
            set_circumference(circumference);
        }
        catch(std::out_of_range &e){
            throw;
        }
    }
    ~Tube() {}

    double get_circumference() const{return circumference_;}

    void set_circumference(double circumference);

    double Volume() const;
    double Girth() const {return circumference_;}
    void Display(std::ostream &out) const;

private:
    double circumference_;

};

#endif