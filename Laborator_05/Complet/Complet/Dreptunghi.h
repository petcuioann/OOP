#pragma once

class Dreptunghi {
private:
    double lungime, latime;

public:
    Dreptunghi(double l = 0, double L = 0);
    ~Dreptunghi();

    double getLungime() const;
    double getLatime() const;
    void setLungime(double l);
    void setLatime(double L);
};
