//
//  ECPolynomial.cpp
//  
//
//  Created by Yufeng Wu on 9/17/22.
//

#include "ECPolynomial.h"
#include <iostream>
#include <iomanip>
using namespace std;

ECPolynomial::ECPolynomial(const std::vector<double> &listCoeffsIn)
{
    polyVector = listCoeffsIn;
    while (polyVector.size() > 1 && std::abs(polyVector[polyVector.size() - 1]) < 1e-10)
    {
        polyVector.pop_back();
    }

    if (polyVector.empty()) {
        polyVector.push_back(0);
    }
}


ECPolynomial::ECPolynomial(const int &rhs)
{
    polyVector = vector<double>(rhs + 1, 0);
}

ECPolynomial::ECPolynomial(const ECPolynomial &rhs)
{
    polyVector = rhs.polyVector;
}

int ECPolynomial::GetDegree() const
{
    if (polyVector.size() == 0)
    {
        return 0;
    }
    return polyVector.size() - 1;
}

void ECPolynomial::SetCoeffAt(const int &index, const double &value)
{
    polyVector[index] = value;
}

double ECPolynomial::GetCoeff(const int &index) const
{
    return polyVector[index];
}

ECPolynomial ECPolynomial::Scale(double factor)
{
    std::vector<double> scaledVector;
    for (const double& num: polyVector)
    {
        scaledVector.push_back(num * factor);
    }
    
    while (scaledVector.size() > 1 && std::abs(scaledVector[scaledVector.size() - 1]) < 1e-10)
    {
        scaledVector.pop_back();
    }

    return ECPolynomial(scaledVector);
}

ECPolynomial ECPolynomial::operator+(const ECPolynomial &rhs) const
{
    std::vector<double> addedVector(max(polyVector.size(), rhs.polyVector.size()), 0);
    for (int i = 0; i < polyVector.size(); i++)
    {
        addedVector[i] += polyVector[i];
    }
    for (int i = 0; i < rhs.polyVector.size(); i++)
    {
        addedVector[i] += rhs.polyVector[i];
    }

    while (addedVector.size() > 1 && std::abs(addedVector[addedVector.size() - 1]) < 1e-10)
    {
        addedVector.pop_back();
    }

    return ECPolynomial(addedVector);
}

ECPolynomial ECPolynomial::operator-(const ECPolynomial &rhs) const
{
    std::vector<double> addedVector(max(polyVector.size(), rhs.polyVector.size()), 0);
    for (int i = 0; i < polyVector.size(); i++)
    {
        addedVector[i] += polyVector[i];
    }
    for (int i = 0; i < rhs.polyVector.size(); i++)
    {
        addedVector[i] -= rhs.polyVector[i];
    }

    while (addedVector.size() > 1 && std::abs(addedVector[addedVector.size() - 1]) < 1e-10)
    {
        addedVector.pop_back();
    }

    return ECPolynomial(addedVector);
}

ECPolynomial ECPolynomial::operator*(const ECPolynomial &rhs) const
{
    std::vector<double> multVector(polyVector.size() + rhs.polyVector.size() - 1, 0);

    for (int i = 0; i < polyVector.size(); ++i)
    {
        for (int j = 0; j < rhs.polyVector.size(); ++j)
        {
            multVector[i + j] += polyVector[i] * rhs.polyVector[j];
        }
    }

    while (multVector.size() > 1 && std::abs(multVector[multVector.size() - 1]) < 1e-10)
    {
        multVector.pop_back();
    }

    return ECPolynomial(multVector);
}

ECPolynomial ECPolynomial::operator/(const ECPolynomial &rhs) const
{
    // Ensure divisor is not zero
    if (rhs.polyVector.size() == 1 && std::abs(rhs.polyVector[0]) < 1e-10)
    {
        throw std::invalid_argument("Cannot divide by zero polynomial.");
    }

    ECPolynomial r(*this);
    
    ECPolynomial q(std::vector<double>(max(rhs.polyVector.size(), polyVector.size()), 0)); 

    while (!(r.polyVector.size() == 1 && std::abs(r.polyVector[0]) < 1e-10) && r.GetDegree() >= rhs.GetDegree())
    {
        vector<double> tVec(r.GetDegree() - rhs.GetDegree() + 1, 0); 
        tVec[r.GetDegree() - rhs.GetDegree()] = r.polyVector[r.GetDegree()] / rhs.polyVector[rhs.GetDegree()];
        ECPolynomial t(tVec);

        q = q + t;
        r = r - t * rhs;
    }

    while (q.polyVector.size() > 1 && std::abs(q.polyVector[q.polyVector.size() - 1]) < 1e-10)
    {
        q.polyVector.pop_back();
    }

    return q;
}


ECPolynomial ECPolynomial::operator%(const ECPolynomial &rhs) const
{
    // Ensure divisor is not zero
    if (rhs.polyVector.size() == 1 && std::abs(rhs.polyVector[0]) < 1e-10)
    {
        throw std::invalid_argument("Cannot divide by zero polynomial.");
    }

    ECPolynomial r(*this);
    
    ECPolynomial q(std::vector<double>(max(rhs.polyVector.size(), polyVector.size()), 0)); 

    while (!(r.polyVector.size() == 1 && std::abs(r.polyVector[0]) < 1e-10) && r.GetDegree() >= rhs.GetDegree())
    {
        vector<double> tVec(r.GetDegree() - rhs.GetDegree() + 1, 0); 
        tVec[r.GetDegree() - rhs.GetDegree()] = r.polyVector[r.GetDegree()] / rhs.polyVector[rhs.GetDegree()];
        ECPolynomial t(tVec);

        q = q + t;
        r = r - t * rhs;
    }

    while (r.polyVector.size() > 1 && std::abs(r.polyVector[r.polyVector.size() - 1]) < 1e-10)
    {
        r.polyVector.pop_back();
    }

    return r;
}

void ECPolynomial::Dump() const
{
    std::cout << "Deg: " << polyVector.size() - 1 << ":  ";
    for (size_t i = 0; i < polyVector.size(); ++i)
    {
        std::cout << std::setprecision(3) << polyVector[i];
        std::cout << " ";
    }
    std::cout << "\n";
}
