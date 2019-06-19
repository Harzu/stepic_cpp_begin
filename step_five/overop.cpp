struct Rational
{
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

    int get_n() const { return numerator_; };
    int get_d() const { return denominator_; };
    
    operator double() const;

    Rational & operator += (const Rational b) {
        this->add(b);
        return *this;
    }

    Rational & operator -= (const Rational b) {
        this->sub(b);
        return *this;
    }

    Rational & operator *= (const Rational b) {
        this->mul(b);
        return *this;
    }

    Rational & operator /= (const Rational b) {
        this->div(b);
        return *this;
    }
  
    Rational operator + () const { return *this; };
    Rational operator - () const {
        Rational b;
        return b -= *this;
    };
private:
    int numerator_;
    int denominator_;
};

Rational operator + (Rational r1, const Rational r2) { return r1 += r2; }
Rational operator - (Rational r1, const Rational r2) { return r1 -= r2; }
Rational operator * (Rational r1, const Rational r2) { return r1 *= r2; }
Rational operator / (Rational r1, const Rational r2) { return r1 /= r2; }

bool operator==(const Rational & lhs, const Rational & rhs) {
    return ((int)lhs.get_n() * rhs.get_d()) == (lhs.get_d() * (int)rhs.get_n());
}

bool operator<(const Rational & lhs, const Rational & rhs) {
    return ((int)lhs.get_n() * rhs.get_d()) < (lhs.get_d() * (int)rhs.get_n());
}

bool operator!=(const Rational & lhs, const Rational & rhs) {return !(lhs == rhs); }
bool operator>(const Rational & lhs, const Rational & rhs) { return (rhs < lhs); }
bool operator<=(const Rational & lhs, const Rational & rhs) { return !(lhs > rhs); }
bool operator>=(const Rational & lhs, const Rational & rhs) { return !(lhs < rhs); }

Rational::operator double() const {
    return this->to_double();
}