//
// Created by brick on 10/13/16.
//

#ifndef VECTORS_VECTOR_H
#define VECTORS_VECTOR_H

//^ new way: pragma once


class Vector {
public:
    float X,Y,Z; //public because we want them to be fast (not good design but quick)

    //do nothing
    Vector();

    //set all values to xyz
    Vector(float xyz);

    Vector(float x, float y, float z);

    void Print() const;

    Vector& operator=(const Vector& other);
    Vector operator+(const Vector& other);
    Vector operator-(const Vector& other);
    Vector operator/(const Vector& other);
    Vector operator/(float scale);
    Vector operator*(const Vector& other);
    Vector operator*(float scale);

    //dot product
    float operator|(const Vector& other);
    static float dotProduct(const Vector& a, const Vector& b); //called differently: d = Vector::dotProduct(a,b);
    //cross product
    Vector operator^(const Vector& other);

    bool operator==(const Vector& v) const;

    Vector operator+=(const Vector& other);

    float magnitude() const; //square root is very inefficient
    float magnitudeSquared() const;

    float operator[](int index);

private:

};


#endif //VECTORS_VECTOR_H
