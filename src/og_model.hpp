#ifndef OG_MODEL_H // guard
#define OG_MODEL_H

#define P_FORGET 0.1
#define P_VERIFY 0.05

#include <array>
#include <algorithm>
#include <cmath>
#include <random>

// alpha = constant probability of credibility
// beta = constant probability of spreading rate
// f + g = beta
// f -> hoax
// g -> debunking

namespace t { // t because of the original research paper
    class node { // this will be fixed later but atm node is not being used
        private:
            std::array<bool, 3> indc;
            /*
            [s1, s2, s3]
            s1 = i, belives the fact is true
            s2 = i, belives the fact is false
            s3 = i, belives the fact is nuetral
            */
            struct node **adj;
        public:
            node(std::array<bool, 3> i, class node **a) {
                this->indc = i;
                this->adj = a;
            }
    };
    class model {
        private:
            int nb, nf; // number of belivers adj. number of fact checkers adj.
            double alpha, beta; // constant probs for spreading and credibility
        public:
            // constructor
            model(double alpha, double beta, int nb, int nf) {
                this->nb = nb;
                this->nf = nf;
                this->alpha = alpha;
                this->beta = beta;
            }

            // hoax diffusal function
            double hoax();

            // debunking diffusal function returns the probability of fsm transition
            double debunking();

            // transition or step over units in time
            void transition();
    };
}

#endif