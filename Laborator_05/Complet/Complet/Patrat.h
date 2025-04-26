#pragma once

class Patrat {
private:
    double latura;

public:
    Patrat(double l = 0);
    ~Patrat();

    double getLatura() const;
    void setLatura(double l);
};
