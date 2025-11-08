#include "InputHelpers.h"
#include "Array.h"
#include <iostream>

int main() {
    Array<std::unique_ptr<Figure<double>>> figures;

    int choice;
    do {
        std::cout << "1. Add Polygon\n";
        std::cout << "2. Print all\n";
        std::cout << "3. Total area\n";
        std::cout << "4. Remove by index\n";
        std::cout << "5. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                auto poly = input_polygon<double>();
                if (poly) figures.push_back(std::move(poly));
                break;
            }
            case 2: print_figures_info(figures);
                break;
            case 3: std::cout << "Total area: " << total_area(figures) << std::endl;
                break;
            case 4: {
                size_t idx;
                std::cout << "Index: ";
                std::cin >> idx;
                if (idx < figures.size()) figures.remove(idx);
                else std::cout << "Invalid index!\n";
                break;
            }
            case 5: std::cout << "completion program\n";
                break;
            default: std::cout << "Uncorrect command\n";
                break;
        }
    } while (choice != 5);
    return 0;
}

