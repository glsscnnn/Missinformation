#include "og_model.hpp"

using namespace t;

// implementation and eq. for hoax spreading
double model::hoax() {
    return this->beta * ((this->nb * (1 + this->alpha)) /
        (this->nb * (1 + this->alpha) + this->nf * (1 - this->alpha)));
}

// implementation and eq. for debunking to spread
double model::debunking() {
    return this->beta * ((this->nf * (1 - this->alpha)) / 
        (this->nb * (1 + this->alpha) + this->nf * (1 - this->alpha)));
}

void model::transition() {
    // this will step through the model in the future atm it does nothing
}