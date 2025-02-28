#ifndef ECRATIONAL_H
#define ECRATIONAL_H

template <class T>
class ECRational
{
public:
    ECRational();
    ECRational(const T &numeratorIn, const T &denominatorIn);
    ECRational(const T &numeratorIn);
    ECRational(const ECRational &ratIn);
    ECRational &operator=(const ECRational &ratIn);

    ECRational operator+(const ECRational &ratIn) const;
    ECRational operator-(const ECRational &ratIn) const;
    ECRational operator*(const ECRational &ratIn) const;
    ECRational operator/(const ECRational &ratIn) const;

    friend ECRational operator+(const T &lhs, const ECRational &rhs) {
        return ECRational(lhs * rhs.denominator + rhs.numerator, rhs.denominator);
    }

    friend ECRational operator+(const ECRational &lhs, const T &rhs) {
        return ECRational(lhs.numerator + rhs * lhs.denominator, lhs.denominator);
    }

    friend ECRational operator-(const T &lhs, const ECRational &rhs) {
        return ECRational(lhs * rhs.denominator - rhs.numerator, rhs.denominator);
    }

    friend ECRational operator-(const ECRational &lhs, const T &rhs) {
        return ECRational(lhs.numerator - rhs * lhs.denominator, lhs.denominator);
    }

    friend ECRational operator*(const T &lhs, const ECRational &rhs) {
        return ECRational(lhs * rhs.numerator, rhs.denominator);
    }

    friend ECRational operator*(const ECRational &lhs, const T &rhs) {
        return ECRational(lhs.numerator * rhs, lhs.denominator);
    }

    friend ECRational operator/(const T &lhs, const ECRational &rhs) {
        return ECRational(lhs * rhs.denominator, rhs.numerator);
    }

    friend ECRational operator/(const ECRational &lhs, const T &rhs) {
        return ECRational(lhs.numerator, lhs.denominator * rhs);
    }

    const T &GetNumerator() const;
    const T &GetDenominator() const;

private:
    T numerator;
    T denominator;
};

// Implementation in the header

template <class T>
ECRational<T>::ECRational() : numerator(T()), denominator(T(1)) {}

template <class T>
ECRational<T>::ECRational(const T &numeratorIn, const T &denominatorIn)
    : numerator(numeratorIn), denominator(denominatorIn) {}

template <class T>
ECRational<T>::ECRational(const T &numeratorIn)
    : numerator(numeratorIn), denominator(1) {}

template <class T>
ECRational<T>::ECRational(const ECRational &ratIn)
    : numerator(ratIn.numerator), denominator(ratIn.denominator) {}

template <class T>
ECRational<T> &ECRational<T>::operator=(const ECRational &ratIn)
{
    if (this != &ratIn)
    {
        numerator = ratIn.numerator;
        denominator = ratIn.denominator;
    }
    return *this;
}

template <class T>
ECRational<T> ECRational<T>::operator+(const ECRational &ratIn) const
{
    return ECRational(numerator * ratIn.denominator + ratIn.numerator * denominator, denominator * ratIn.denominator);
}

template <class T>
ECRational<T> ECRational<T>::operator-(const ECRational &ratIn) const
{
    return ECRational(numerator * ratIn.denominator - ratIn.numerator * denominator, denominator * ratIn.denominator);
}

template <class T>
ECRational<T> ECRational<T>::operator*(const ECRational &ratIn) const
{
    return ECRational(numerator * ratIn.numerator, denominator * ratIn.denominator);
}

template <class T>
ECRational<T> ECRational<T>::operator/(const ECRational &ratIn) const
{
    return ECRational(numerator * ratIn.denominator, denominator * ratIn.numerator);
}


template <class T>
const T &ECRational<T>::GetNumerator() const
{
    return numerator;
}

template <class T>
const T &ECRational<T>::GetDenominator() const
{
    return denominator;
}

#endif /* ECRATIONAL_H */
