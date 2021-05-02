#include <iostream>
#include "og_model.hpp"

int main() {
    // TEST HOAX
    t::model m(0.9, 0.5, 10, 1);
    double h = m.hoax();
    std::cout << "Hoax Probability s[0]: " << h << std::endl;

    return 0;
}