#ifndef LOAD_H
#define LOAD_H
#include "shipping_item.h"
#include <vector>

class Load{
public:
    Load():indexBeingDelivered_(0), loadSize_(0), totalWeight_(0), totalVolume_(0) {}
    ~Load() {
        for(ShippingItem* &item: ShippingItemsVector_){
            delete item;
            item = NULL;
        }
    }

    int get_count() const{return loadSize_;}
    double get_total_volume() const{return totalVolume_;}
    double get_total_weight() const{return totalWeight_;}

    void FillLoad(std::string filename);
    void DisplayNextDelivery(std::ofstream &out) const;
    void ItemDelivered();
    void NotDeliverable();
    int HowManyDelivered() const;
    int HowManyNotDelivered() const;

private:
    std::vector<ShippingItem*> ShippingItemsVector_;
    int indexBeingDelivered_;
    int loadSize_;
    double totalWeight_;
    double totalVolume_;
};

#endif