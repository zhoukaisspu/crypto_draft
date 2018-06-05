#pragma once
#include <memory>
#include <vector>
#include <limits>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <cmath>

namespace prime{
    namespace findPrime{
        std::shared_ptr<std::vector<unsigned int>>
            sieveOfEratosthenes(unsigned int len)
        {
	        const unsigned int maxLen =
		        (250 * 1024 * 1024) / sizeof(unsigned int);
	        if (len > maxLen)
		        throw std::out_of_range("maximum length is :" +
			        std::to_string(maxLen));
	        std::shared_ptr<std::vector<unsigned int>> prePrime =
		    std::make_shared<std::vector<unsigned int>>(len - 2);
	        struct c_unique {
		        int current;
		        c_unique() { current = 1; }
		        int operator()() { return ++current; }
	        };
	        std::generate(prePrime->begin(), prePrime->end(), c_unique());
	        for (unsigned int i = 2; i <= std::sqrt(len); ++i) {
		        if ((*prePrime)[i - 2] != 0) {
			        unsigned int j = i;
			        unsigned int v = i;
			        unsigned int index = i;
			        do {
			        	index = (j * v) - 2;
				        (*prePrime)[index] = 0;
				        ++v;
			        } while (index < len);
		        }
	        }
	         return prePrime;
         }

    }
}