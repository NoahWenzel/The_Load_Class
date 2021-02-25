#include "carton.h"

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

// define the static members
const double Carton::kMinLength = 6;
const double Carton::kMinWidth = 3;
const double Carton::kMinHeight = .25;


// constructors and destructor
/**
 * @brief Construct a new Carton:: Carton object
 * Sets length to 12, width to 12, and height to 12
 *
 */
Carton::Carton() { set_measurements(12, 12, 12); }

/**
 * @brief Construct a new Carton:: Carton object. Sets the measurements to
 * the values sent. Sets length to the longest side.
 *
 * @param side1 - one dimension of the carton
 * @param side2 - one dimension of the carton
 * @param side3 - one dimension of the carton
 * @throw std::out_of_range exception if any side is zero or less
 */
Carton::Carton(double side1, double side2, double side3) {
  try {
    set_measurements(side1, side2, side3);
  } catch (out_of_range e) {
    throw;
  }
}


// setters
/**
 * @brief - sets the value of length. Require length to be greater than zero
 * and the longest side.
 *
 * @param length - the value of the new length
 * @throw std::out_of_range exception if parameter length is zero or less or
 * if it is shorter than width or height.
 */
void Carton::set_length(double length) {
  if (length < kMinSize) {
    throw out_of_range("Length must be greater than zero");
  }
  if (length < width_ || length < height_) {
    throw out_of_range("Length must be the longest measurement");
  }

  length_ = length;
}

/**
 * @brief - sets the value of width
 *
 * @param width - the value of the new width
 * @throw std::out_of_range exception if parameter width is zero or less or
 * if it is longer than length.
 */
void Carton::set_width(double width) {
  if (width < kMinSize) {
    throw out_of_range("Width must be greater than zero");
  }
  if (width > length_) {
    throw out_of_range("Width must be shorter or equal to length");
  }

  width_ = width;
}

/**
 * @brief - sets the value of height
 *
 * @param height - the value of the new height
 * @throw std::out_of_range exception if parameter height is zero or less or
 * if it is longer than length.
 */
void Carton::set_height(double height) {
  if (height < kMinSize) {
    throw out_of_range("Height must be greater than zero");
  }
  if (height > length_) {
    throw out_of_range("Height must be shorter or equal to length");
  }

  height_ = height;
}

/**
 * @brief Sets the length, width and height of the Carton. Makes sure all
 * dimensions are greater than zero. Sets the length to the longest side.
 *
 * @param side1 - one dimension of the carton
 * @param side2 - one dimension of the carton
 * @param side3 - one dimension of the carton
 * @throw std::out_of_range exception if any side is zero or less
 */
void Carton::set_measurements(double side1, double side2, double side3) {
  if (side1 <= kMinSize || side2 <= kMinSize || side3 <= kMinSize) {
    throw out_of_range("All measurements must be greater than zero");
  }

  if (side1 >= side2 && side1 >= side3) {
    length_ = side1;
    width_ = side2;
    height_ = side3;
  } else if (side2 >= side1 && side2 >= side3) {
    length_ = side2;
    width_ = side3;
    height_ = side1;
  } else {
    length_ = side3;
    width_ = side1;
    height_ = side2;
  }
}

// other methods
/**
 * @brief - returns the volume of the carton
 *
 * @return double - the volume
 */
double Carton::Volume() const { return length_ * width_ * height_; }
/**
 * @brief - computes and returns the girth of the carton
 *
 * @return double - the girth
 */
double Carton::Girth() const { return width_ * 2 + height_ * 2; }
/**
 * @brief - computes and returns length plus girth
 *
 * @return double - length plus girth
 */
double Carton::LengthPlusGirth() const { return length_ + Girth(); }

/**
 * @brief - determines if a carton is the right size for shipping. Uses maximum
 * length plus girth of 108. Uses minimum dimensions of 6 x 3 x .25.
 *
 * @return true - when the carton is within allowed ranges
 * @return false - when the carton is too big or too small to be shipped
 */
bool Carton::SizedToShip() const {
  // check if too small
  if (length_ < kMinLength) {
    return false;
  }
  if (height_ <= width_) {
    if (height_ < kMinHeight) {
      return false;
    }
    if (width_ < kMinWidth) {
      return false;
    }
  } else {
    if (width_ < kMinHeight) {
      return false;
    }
    if (height_ < kMinWidth) {
      return false;
    }
  }

  // check if too big
  if (LengthPlusGirth() > kMaxSize) {
    return false;
  }

  // size to ship
  return true;
}
/**
 * @brief - writes the carton data, length, width and height, to the output
 * stream
 *
 * @param out - an output stream
 */
void Carton::WriteData(std::ostream& out) const {
  out << length_ << " " << width_ << " " << height_ << endl;
}
/**
 * @brief - writes carton information in a sentence to the output stream
 *
 * @param out - an output stream
 */
void Carton::WriteCarton(std::ostream& out) const {
  out << "A carton with length " << length_ << ", width " << width_
      << ", and height " << height_ << "." << endl;
}


/**
 * @brief outputs Carton data to the ostream in format:
 * Carton length x width x height
 * with a precision of one digit after the decimal
 *
 * @param out - output stream to write data
 * @param carton - Carton object
 * @return std::ostream& - output stream to allowing chaining output
 */
std::ostream& operator<<(std::ostream& out, const Carton& carton) {
  out << setprecision(1) << fixed;
  out << "Carton " << carton.get_length() << " x " << carton.get_width() << " x "
      << carton.get_height();
  return out;
}

/**
 * @brief Displays the Carton objects weight and dimensions
 * @param out - ostream object for data to be printed.
 */
void Carton::Display(std::ostream &out) const {
    out << setprecision(1) << fixed << "Carton: " << weight_ <<
        " lbs. " << length_ << " x " << width_ << " x " << height_ << endl;
}