// LeetCode 1352
#include <iostream>
#include <vector>
#include <set>

using std::cout, std::endl, std::vector, std::set;

namespace Solution {
    class ProductOfNumbers {
        public:
            ProductOfNumbers();
            void add(int num);
            int getProduct(int k);
        
        private:
            int predictOverflow(int start, int end);

            vector<int> productSums;
            set<int> zeros;
            set<int> overflow;
    };

    ProductOfNumbers::ProductOfNumbers() {}

    void ProductOfNumbers::add(int num) {
        if (productSums.size() == 0) {
            if (num == 0) {
                zeros.insert(0);
                productSums.push_back(1);
            } else {
                productSums.push_back(num);
            }
            return;
        }

        int index = productSums.size()-1;
        if (num == 0) {
            productSums.push_back(productSums[index]);
            zeros.insert(index+1);
            return;
        }
        
        long long product = (long long)productSums[index] * (long long)num;
        if (product > INT_MAX) {
            productSums.push_back(num);
            overflow.insert(index+1);
            return;
        }

        productSums.push_back((int)product);
    }

    int ProductOfNumbers::getProduct(int k) {
        int size = productSums.size();
        int start = size - k, end = size - 1;
        
        // Find a zero
        set<int>::iterator it = zeros.upper_bound(start-1);
        if (it != zeros.end()) return 0;
        return predictOverflow(start, end);;
    }

    int ProductOfNumbers::predictOverflow(int start, int end) {
        set<int>::iterator it = overflow.upper_bound(start - 1);
        if (overflow.size() == 0 || it == overflow.end()) {
            if (start == 0) return productSums[end];
            return productSums[end] / productSums[start-1];
        }

        if (*it < start) return productSums[end] / productSums[start-1];
        if (*it == start) return productSums[end];
        return (productSums[(*it)-1] / productSums[start - 1]) * productSums[end];
    }
}

int main() {
    using namespace Solution;
    ProductOfNumbers productOfNumbers;
    productOfNumbers.add(0);
    productOfNumbers.add(0);
    productOfNumbers.add(9);
    cout << productOfNumbers.getProduct(3) << endl;
    productOfNumbers.add(8);
    productOfNumbers.add(3);
    productOfNumbers.add(8);
    cout << productOfNumbers.getProduct(5) << endl;
    cout << productOfNumbers.getProduct(4) << endl;
    cout << productOfNumbers.getProduct(6) << endl;
    productOfNumbers.add(8);        // [3,0,2]
    productOfNumbers.add(8);        // [3,0,2,5]
    return 0;
}