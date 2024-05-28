/// \file CRectangle.cpp
/// \brief Implementation of the class Rectangle
///
/// This file contains the implementation of the class Rectangle.

#include<iostream>
#include "CRectangle.h"

using namespace std;

/// @brief Default constructor
Rectangle::Rectangle() {
    cout << "Rectangle - constructor - default" << endl;
    Init();
}

/// @brief Constructor with width and height
/// @param w Width of the rectangle
/// @param h Height of the rectangle

Rectangle::Rectangle(float w, float h) {
    Init();
    cout << "Rectangle - constructor" << endl;
    if (w <= 0. || h <= 0.) {
        WarningMessage("constructor: width and height should be > 0");
        SetDim(0, 0);
    }
    else {
        SetDim(w, h);
    }
}

/// @brief Constructor with width, height and format
/// @param w Width of the rectangle
/// @param h Height of the rectangle
/// @param sf Struct of type Format
Rectangle::Rectangle(float w, float h, Format sf) : Quadrilateral(sf) {
    Init();
    cout << "Rectangle - constructor with Format" << endl;
    if (w <= 0. || h <= 0.) {
        WarningMessage("constructor: width and height should be > 0");
        SetDim(0, 0);
    }
    else {
        SetDim(w, h);
    }
}

/// @brief Destructor
Rectangle::~Rectangle() {
    cout << "Rectangle - destructor" << endl;
    Reset();
}

/// @brief Copy constructor
/// @param r Reference to the object that should be copied
Rectangle::Rectangle(const Rectangle& r) {
    cout << "Rectangle - copy constructor" << endl;
    Init(r);
}

/// @brief Overload of operator =
/// @param r Reference to the object on the right side of the operator
/// @return Reference to the object on the left side of the operator
Rectangle& Rectangle::operator=(const Rectangle& r) {
    cout << "Rectangle - operator =" << endl;
    if (this != &r) {
        Quadrilateral::operator=(r);
        Init(r);
    }
    return *this;
}

/// @brief Overload of operator ==
/// @param r Reference to the object on the right side of the operator
/// @return True if the two objects have the same width and height
bool Rectangle::operator==(const Rectangle& r) {
    return (r.width == width && r.height == height);
}

/// @brief Default initialization of the object
void Rectangle::Init() {
    SetDim(0, 0);
}

/// @brief Initialization of the object as a copy of another object
/// @param r Reference to the object that should be copied
void Rectangle::Init(const Rectangle& r) {
    Init();
    SetDim(r.width, r.height);
}

/// @brief Total reset of the object
void Rectangle::Reset() {
    SetDim(0, 0);
}

/// @brief Set width of the object
/// @param w Width
void Rectangle::SetWidth(float w) {
    if (w < 0.) {
        WarningMessage("SetWidth: width should be > 0");
        return;
    }
    SetDim(w, height);
}

/// @brief Set height of the object
/// @param h Height
void Rectangle::SetHeight(float h) {
    if (h < 0.) {
        WarningMessage("SetHeight: height should be > 0");
        return;
    }
    SetDim(width, h);
}

/// @brief Get width of the object
/// @return Width
float Rectangle::GetWidth() {
    return width;
}

/// @brief Get height of the object
/// @return Height
float Rectangle::GetHeight() {
    return height;
}

/// @brief Set width and height of the object
/// @param w Width
/// @param h Height
void Rectangle::SetDim(float w, float h) {
    width = w;
    height = h;
    Quadrilateral::SetSides(w, h, w, h);
}

/// @brief Get width and height of the object
/// @param w Width
/// @param h Height
void Rectangle::GetDim(float& w, float& h) {
    w = width;
    h = height;
}

/// @brief Compute the area of the object
/// @return Area
float Rectangle::Area() {
    return (width * height);
}

/// @brief Write an error message
/// @param string Message to be printed
void Rectangle::ErrorMessage(const char* string) {
    cout << "ERROR -- Rectangle -- " << string << endl;
}

/// @brief Write a warning message
/// @param string Message to be printed
void Rectangle::WarningMessage(const char* string) {
    cout << "WARNING -- Rectangle -- " << string << endl;
}

/// @brief For debugging: print all about the object
void Rectangle::Dump() {
    cout << "--- Rectangle ---" << endl;
    cout << "Width = " << width << endl;
    cout << "Height = " << height << endl;
    Quadrilateral::Dump();
}

/// @brief Draw the rectangle
void Rectangle::Drawing() {

    cout << "Drawing Rectangle:" << endl;
    cout << "Width: " << width << ", Height: " << height << endl;
    if (shapef != nullptr) {
        cout << "Fill color: " << shapef->fill << endl;
        cout << "Outline color: " << shapef->outline << endl;
    }
    // Implementation of  Drawing Rectangle
}

 