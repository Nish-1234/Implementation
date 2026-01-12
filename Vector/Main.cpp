#include <iostream>
#include "VectorClass.h"

int main()
{
    try
    {
        std::cout << "=== Default Constructor ===\n";
        NewVector v1;
        std::cout << "Size: " << v1.size()
                  << ", Capacity: " << v1.capacity() << "\n\n";

        std::cout << "=== push_back() ===\n";
        v1.push_back(10);
        v1.push_back(20);
        v1.push_back(30);
        v1.print();
        std::cout << "Size: " << v1.size()
                  << ", Capacity: " << v1.capacity() << "\n\n";

        std::cout << "=== operator[] (Get/Set) ===\n";
        v1[1] = 99;
        std::cout << "v1[1] = " << v1[1] << "\n";
        v1.print();
        std::cout << "\n";

        std::cout << "=== pop_back() ===\n";
        int removed = v1.pop_back();
        std::cout << "Removed element: " << removed << "\n";
        v1.print();
        std::cout << "Size: " << v1.size() << "\n\n";

        std::cout << "=== Copy Constructor ===\n";
        NewVector v2(v1);
        v2.print();
        std::cout << "\n";

        std::cout << "=== Assignment Operator ===\n";
        NewVector v3;
        v3 = v1;
        v3.print();
        std::cout << "\n";

        std::cout << "=== clear() ===\n";
        v1.clear();
        std::cout << "After clear -> Size: " << v1.size()
                  << ", Capacity: " << v1.capacity() << "\n";
        std::cout << "Is empty? " << (v1.empty() ? "Yes" : "No") << "\n\n";

        std::cout << "=== Bounds Check (Exception Test) ===\n";
        std::cout << v1[0] << "\n"; // should throw exception
    }
    catch (const std::exception &ex)
    {
        std::cout << "Exception caught: " << ex.what() << "\n";
    }

    std::cout << "\n=== Program End ===\n";
    return 0;
}
