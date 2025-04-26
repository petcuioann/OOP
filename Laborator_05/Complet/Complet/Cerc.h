#pragma once

class Cerc {
private:
    double raza;

public:
    Cerc(double r = 0);
    ~Cerc();

    double getRaza() const;
    void setRaza(double r);
};
