#pragma once

class Triunghi {
private:
    double a, b, c;

public:
    Triunghi(double x = 0, double y = 0, double z = 0);
    ~Triunghi();

    double getLatura1() const;
    double getLatura2() const;
    double getLatura3() const;

    void setLatura1(double x);
    void setLatura2(double y);
    void setLatura3(double z);
};
