#include "flat.h"
#include <iomanip>

/**
 * @brief Sets the length member to the value sent. If the length
 *      sent is less than kMinSize or greater than 15 it throws an
 *      out_of_range exception.
 * @param length - double to set the length of a Flat object.
 */
void Flat::set_length(double length) {
    if(length < kMinSize || length > 15){
        throw std::out_of_range("Length is out of range!");
    }
    length_ = length;
}

/**
 * @brief Sets the height member to the value sent. If the height
 *      sent is less than kMinSize or greater than 12 it throws an
 *      out_of_range exception.
 * @param height - double to set the height of a Flat object.
 */
void Flat::set_height(double height) {
    if(height < kMinSize || height > 12){
        throw std::out_of_range("Height is out of range!");
    }
    height_ = height;
}

/**
 * @brief Sets the thickness member to the value sent. If the
 *      thickness sent is less than kMinSize or greater than 0.75 it
 *      throws an out_of_range exception.
 * @param thickness - double to set the thickness of a Flat object.
 */
void Flat::set_thickness(double thickness) {
    if(thickness < kMinSize || thickness > 0.75){
        throw std::out_of_range("Thickness is out of range!");
    }
    thickness_ = thickness;
}

/**
 * @brief Calculates the total volume of the package by length *
 *      width * height.
 * @return A double which is the total volume of the package.
 */
double Flat::Volume() const {
    return length_ * height_ * thickness_;
}

/**
 * @brief Displays the Flat objects weight and dimensions
 * @param out - ostream object for data to be printed.
 */
void Flat::Display(std::ostream &out) const {
    out << std::setprecision(1) << std::fixed << "Flat: " <<
    weight_ << " lbs. " << length_ << " x " << height_ << " x " << thickness_ <<
    std::endl;
}
