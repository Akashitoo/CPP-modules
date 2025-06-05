#ifndef CUSTOMITERATOR_HPP
# define CUSTOMITERATOR_HPP

template <typename PairIterator>

class CustomIterator
{
public:

    CustomIterator() {}
    CustomIterator(PairIterator it) : iter(it) {}

    CustomIterator& operator++()
    {
        ++iter;
        return *this;
    }

    CustomIterator operator++(int)
    {
        CustomIterator tmp = *this;
        ++(*this);
        return tmp;
    }

    bool operator==(const CustomIterator& other) const
    {
        return iter == other.iter;
    }

    bool operator!=(const CustomIterator& other) const
    {
        return !(*this == other);
    }

private:
    PairIterator iter;
};

#endif