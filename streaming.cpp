#include <iostream>
#include <string>

class Robot {
public:
    std::string headName;
    std::string bodyName;

    Robot() = default;
    Robot(const std::string& head, const std::string& body)
        : headName(head), bodyName(body) {}

    // Friend declarations for stream operators
    friend std::ostream& operator<<(std::ostream& os, const Robot& robot);
    friend std::istream& operator>>(std::istream& is, Robot& robot);
};

// Operator for std::cout (Understanding the )
std::ostream& operator<<(std::ostream& os, const Robot& robot) {
    os << "Head: " << robot.headName << "\n";
    os << "Body: " << robot.bodyName << "\n";
    return os;
}

// Overload >> operator for input
std::istream& operator>>(std::istream& is, Robot& robot) {
    std::cout << "Enter head name: ";
    is >> robot.headName;
    std::cout << "Enter body name: ";
    is >> robot.bodyName;
    return is;
}

int main() {
    Robot r1("Alpha", "Beta");
    
    // Serialize to an output stream (e.g., std::cout)
    std::cout << "Robot r1:\n" << r1;

    // Deserialize from an input stream (e.g., std::cin)
    Robot r2;
    std::cin >> r2;
    std::cout << "Robot r2:\n" << r2;

    return 0;
}