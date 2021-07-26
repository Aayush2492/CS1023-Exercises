/**
 * 
 * Subject branches into three threads and executes the update function in each observor
 * then all three threads are joined in the start function itself before returning to the
 * main function.
 * 
 */

#include <iostream>
#include <list>
#include <string>
#include <thread>
#include <vector>
#include <utility>
#include <chrono>
#include <memory>

class observor_t
{
public:
    virtual void update(std::string &) = 0;
};

using pair = std::pair<std::shared_ptr<observor_t>, bool>;
using vector_pair = std::vector<pair>;

class print_string : public observor_t
{
public:
    void update(std::string &s)
    {
        std::cout << s << std::endl;
    }
};

class print_freq : public observor_t
{
public:
    void update(std::string &s)
    {
        //Freq function
        //Print Frequency

        std::cout << "Print Frequency" << std::endl;
    }
};

class write_string : public observor_t
{
public:
    void update(std::string &s)
    {
        //File writing function

        std::cout << "Written to file" << std::endl;
    }
};

class readert
{
private:
    std::string s;
    vector_pair observors;

public:
    void subscribe(std::shared_ptr<observor_t> os)
    {
        observors.push_back(std::make_pair(os, true));
    }

    void unsubscribe(unsigned index)
    {
        observors[index].second = false;
    }
    void getString(std::string &_s)
    {
        s = _s;
    }

    void start()
    {
        if (observors[0].second == true)
            observors[0].first->update(s);

        auto f1 = [&]()
        {
            if (observors[1].second == true)
            {
                observors[1].first->update(s);
            }
        };
        std::thread thr1(f1);

        auto f2 = [&]()
        {
            if (observors[2].second == true)
            {
                observors[2].first->update(s);
            }
        };
        std::thread thr2(f2);

        thr1.join();
        thr2.join();
    }
};

int main()
{
    readert rt;
    std::string sentence = "This statement is false";
    rt.getString(sentence);

    std::shared_ptr<observor_t> p1 = std::make_shared<print_string>();
    std::shared_ptr<observor_t> p2 = std::make_shared<print_freq>();
    std::shared_ptr<observor_t> p3 = std::make_shared<write_string>();

    rt.subscribe(p1);
    rt.subscribe(p2);
    rt.subscribe(p3);

    rt.start();

    return 0;
}