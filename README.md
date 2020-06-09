# Matching-Market
C++ implementation for computing market-clearing prices and VCG prices in a matching market.
# How to use it
1. Add ```matching_market.cpp``` as a library in your ```CMakeLists.txt```, and link it to your executable
1. Include ```matching_market.h``` in your code
1. A example usage can be found in main.cpp
# Input format
    Number of Buyers
    Valuation Matrix
For example:

    3
    12 4 2
    8 7 6
    7 5 2
# Reference
The algorithm for finding the market-clearing prices can be found here:
https://www.cs.cornell.edu/home/kleinber/networks-book/networks-book-ch10.pdf


And for VCG prices, the following algorithm is used:

![formula](https://render.githubusercontent.com/render/math?math=p_i(j)=V^I_{B-j}-V^{I-i}_{B-j})

where

+ ![formula](https://render.githubusercontent.com/render/math?math=p_i(j)) is item i's VCG price for buyer j, aka. the harm he causes to other buyers in possession of item i
+ ![formula](https://render.githubusercontent.com/render/math?math=V^I_{B-j}) is the maximum total valuation with buyer j excluded
+ ![formula](https://render.githubusercontent.com/render/math?math=V^{I-i}_{B-j}) is the maximum total valuation with item i and buyer j excluded

more details can be found in chapter 10,15 from the book ```Networks, Crowds, and Markets``` by David Easley 