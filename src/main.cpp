#include <iostream>
#include <string>
#include <cmath>

// general form:    ax^2+bx+c=0
// example input:   1x^2+3x+0=0

double*
solve_equation(float a, float b, float c)
{
    double* solutions = new double[2];
    
    if (a == 0) return nullptr;
 
    double d = b * b - 4 * a * c;
    if (d > 0)
    {
        solutions[0] = (-b + sqrt(d)) / (2 * a);
        solutions[1] = (-b - sqrt(d)) / (2 * a);
    }
    else if (d == 0)    solutions[0] = -b / (2 * a);
    else                solutions = nullptr;

    return solutions;
}

float*
parse_equation(const std::string eq)
{
    float* coefficients = new float[3];

    size_t first        = eq.find("x^2+");
    size_t second       = eq.find("x+");
    size_t third        = eq.find("=0"); 

    coefficients[0]     = std::stof(eq.substr(0, first));

    if (eq.substr(first + 4, second - first - 5) == "-")
        coefficients[1]     = -std::stof(eq.substr(first + 4, second - first - 4));
    else coefficients[1]    = std::stof(eq.substr(first + 4, second - first - 4));

    if (eq.substr(second + 2, third - second - 2) == "-")    
        coefficients[2]     = -std::stof(eq.substr(second + 2, third - second - 2));
    else coefficients[2]    = std::stof(eq.substr(second + 2, third - second - 2));

    return coefficients;
}

int
main()
{
    std::string in;
    std::cout << "Type a valid quadratic equation: ";
    std::getline(std::cin, in);
    float* coefficients = parse_equation(in);
    if (coefficients != nullptr)
    {
        double* solutions = solve_equation(coefficients[0], coefficients[1], coefficients[2]);
        if (solutions != nullptr)
            std::cout << "The solutions are: " << solutions[0] << " and " << solutions[1] << "." << std::endl;
        else 
            std::cout << "The equation has no solutions." << std::endl;
        delete[] solutions;
    }
    else std::cout << "The equation is not valid." << std::endl;
    delete[] coefficients;
    return 0;
}