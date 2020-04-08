#pragma once

#include <iostream>
#include <cmath>

class IGeoFig {
public:
    virtual double square() = 0;

    virtual double perimeter() = 0;
};

class CVector2D {
public:
    double x, y;
};

class IPhysObject {
public:
    virtual double mass() = 0;

    virtual CVector2D position() = 0;

    virtual bool operator==(const IPhysObject &ob) const = 0;

    virtual bool operator<(const IPhysObject &ob) const = 0;
};

class IPrintable {
public:
    virtual void draw() = 0;
};

class IDialogInitable {
    virtual void initFromDialog() = 0;
};

class BaseCObject {
public:
    virtual const char *classname() = 0;

    virtual unsigned int size() = 0;
};

class Rectangle
        : public IGeoFig,
          public CVector2D,
          public IPrintable,
          public IDialogInitable,
          public BaseCObject {
private:
    CVector2D a, b, c, d;
    double a_side, b_side, c_side, d_side;
public:
    Rectangle();

    void initFromDialog() override;

    void draw() override;

    const char *classname() override;

    unsigned int size() override;

    double square() override;

    double perimeter() override;
};

class Ellipse
        : public IGeoFig,
          public CVector2D,
          public IPrintable,
          public IDialogInitable,
          public BaseCObject {
private:
    CVector2D a, b, c, d;
    double a_axis, b_axis;
public:

    Ellipse();

    void initFromDialog() override;

    void draw() override;

    const char *classname() override;

    unsigned int size() override;

    double square() override;

    double perimeter() override;
};