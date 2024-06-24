#include <iostream>
#include <cmath> 
#include <vector> 
#include <stdio.h> 
// #include <filesystem>
#include <iostream>
#include <cmath> 
#include <vector> 
#include <stdio.h> 

// Function to display the contents of a vector
void display_vector(const std::vector<int>& vec)
{
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}


// Full vector is passed in 
void modify_without_reference(std::vector<int> vec)
{
    vec[2] = 5;
    std::cout << "Vector Value updated without reference" << std::endl;
}


// Original pointer modified by reference 
void modify_by_reference(std::vector<int>& vec)
{
    vec[0] = 5;
    std::cout << "Vector Value updated by reference" << std::endl;
    std::cout << "Pointer to vec[0] "<<  &vec << std::endl;
}

// De-referencing the vector to modify by value 
void modify_by_value(std::vector<int>* vec)
{
    std::cout << "Pointer value: Address location: " << vec << std::endl;
    std::cout << "Dereferenced: Index Needed: " << (*vec)[0] << std::endl;
    (*vec)[1] = 5;
    std::cout << "Vector Value updated by value" << std::endl;
}

int main()
{
    std::vector<int> A = {1, 2, 3, 4, 5};

    modify_by_value(&A);
    display_vector(A); // Display the vector to see the changes

    modify_by_reference(A);
    display_vector(A); // Display the vector to see the changes

    modify_without_reference(A);
    display_vector(A);

    return 0;
}