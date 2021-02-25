#include "tube.h"
#include <iomanip>

const double Tube::kPi = 3.14159;

/**
 * @brief Sets the circumference member to the value sent. If the circumference
 *      sent is less than kMinSize or if the length + circumference is greater
 *      than kMaxSize it throws an out_of_range exception.
 * @param circumference double of the circumference_ member of the Tube object.
 */
void Tube::set_circumference(double circumference) {
    if(circumference < kMinSize || get_length() + circumference > kMaxSize){
        throw std::out_of_range("Circumference is out of range!");
    }
    circumference_ = circumference;
}

/**
 * @brief Calculates the volume of the Tube object.
 * @return double using the equation (C * C * l) / (4 * pi).
 *      Where C = circumference
 *            l = length
 *            pi = 3.14159
 */
double Tube::Volume() const {
    double volume = (get_circumference() * get_circumference() *
            get_length()) / (4 * kPi);
    return volume;
}

/**
 * @brief Displays the Carton objects weight and dimensions
 * @param out - ostream object for data to be printed.
 */
void Tube::Display(std::ostream &out) const {
    out << std::setprecision(1) << std::fixed << "Tube: " << weight_ <<
        " lbs. " << length_ << " x " << circumference_ << std::endl;
}