/**
 * Event manager will have multiple observors and multiple subjects
 * 
 * Considering four events  on facebook:
 * 1. Post liked
 * 2. Post disliked
 * 3. Post reshared
 * 4. Tagged
 * 
 * Considering two observors: 
 * 1. Mobile notification
 * 2. PC notification
 * 
 * To make the observor computationally heavy, add a pause for 20seconds on that thread
 */

#include <iostream>
#include <vector>
#include <utility>

class observor_t
{
public:
    virtual void notify(std::string &) = 0;
};

using pair = std::pair<observor_t *, bool>;
using vector_pair = std::vector<pair>;

class mobile : public observor_t
{
public:
    void notify()
    {
    }
};

class pc : public observor_t
{
public:
    void notify()
    {
    }
};

class like
{
private:
    vector_pair observors;

public:
    void subscribe(observor_t *ost)
    {
        observors.push_back(std::make_pair(ost, true));
    }
    void start()
    {
        func()
    }
};

class dislike
{
private:
    vector_pair observors;

public:
    void subscribe(observor_t *ost)
    {
        observors.push_back(std::make_pair(ost, true));
    }
    void start()
    {
    }
};

class reshare
{
private:
    vector_pair observors;

public:
    void subscribe(observor_t *ost)
    {
        observors.push_back(std::make_pair(ost, true));
    }
    void start()
    {
    }
};

class tag
{
private:
    vector_pair observors;

public:
    void subscribe(observor_t *ost)
    {
        observors.push_back(std::make_pair(ost, true));
    }
    void start()
    {
    }
};

int main()
{

    return 0;
}