#include <iostream>
#include <vector>
#include <stack>
class visitor;
class plus;
class leaf;
class minus;

class Component
{
public:
    virtual void accept(visitor *v) = 0;
    virtual void push(Component *) = 0;
    virtual ~Component(){};
};

class visitor
{
protected:
    int result = 0;

public:
    virtual void visit(plus *) = 0;
    virtual void visit(leaf *) = 0;
    virtual void visit(minus *) = 0;

    virtual ~visitor(){};
};

class leaf : public Component
{
private:
    int val;

public:
    leaf(int val_)
    {
        val = val_;
    }

    int getValue()
    {
        return val;
    }
    void push(Component *comp) override
    {
    }
    void accept(visitor *v) override
    {
        v->visit(this);
    }
};

class plus : public Component
{
public:
    std::vector<Component *> operands;

    std::vector<Component *> getOperands()
    {
        return (operands);
    }
    void push(Component *comp) override
    {
        operands.push_back(comp);
    }

    void accept(visitor *v) override
    {
        v->visit(this);
    }
};

class minus : public Component
{
public:
    std::vector<Component *> operands;

    std::vector<Component *> getOperands()
    {
        return (operands);
    }
    void push(Component *comp) override
    {
        operands.push_back(comp);
    }

    void accept(visitor *v) override
    {
        v->visit(this);
    }
};

class print : public visitor
{
public:
    /*void visit(Component *comp) override
    {
        if (dynamic_cast<plus *>(comp))
        {
            visit(dynamic_cast<plus *>(comp));
        }
        else if (dynamic_cast<leaf *>(comp))
        {
            visit(dynamic_cast<leaf *>(comp));
        }
        else if (dynamic_cast<minus *>(comp))
        {
            visit(dynamic_cast<minus *>(comp));
        }
    }*/

    void visit(plus *p) override
    {
        std::vector<Component *> operands = p->getOperands();
        operands[0]->accept(this);
        std::cout << "+";
        operands[1]->accept(this);
    }

    void visit(leaf *p) override
    {
        int i = p->getValue();
        std::cout << i;
    }

    void visit(minus *p) override
    {
        std::vector<Component *> operands = p->getOperands();
        operands[0]->accept(this);
        std::cout << "-";
        operands[1]->accept(this);
    }
};

class evaluate : public visitor
{
private:
    std::stack<int> vals;
    int flag = 1;

public:
    int getResult()
    {
        return (vals.top());
    }

    /*void visit(Component *comp) override
    {
        if (dynamic_cast<plus *>(comp))
        {
            visit(dynamic_cast<plus *>(comp));
        }
        else if (dynamic_cast<leaf *>(comp))
        {
            visit(dynamic_cast<leaf *>(comp));
        }
        else if (dynamic_cast<minus *>(comp))
        {
            visit(dynamic_cast<minus *>(comp));
        }
    }*/

    void visit(plus *p) override
    {
        std::vector<Component *> operands = p->getOperands();
        operands[0]->accept(this);
        flag = 1;
        operands[1]->accept(this);
        int op1 = vals.top();
        vals.pop();
        int op2 = vals.top();
        vals.pop();
        vals.push(op1 + op2);
    }

    void visit(leaf *p) override
    {
        int i = p->getValue();
        vals.push(flag * i);
    }

    void visit(minus *p) override
    {
        std::vector<Component *> operands = p->getOperands();
        operands[0]->accept(this);
        flag = -1;
        operands[1]->accept(this);
        int op1 = vals.top();
        vals.pop();
        int op2 = vals.top();
        vals.pop();
        vals.push(op2 + op1);
    }
};

int main()
{
    Component *cont0 = new plus();
    Component *cont1 = new plus();
    Component *cont2 = new plus();

    Component *cont3 = new minus();

    cont0->push(new leaf(6));
    cont0->push(new leaf(7));

    cont1->push(new leaf(5));
    cont1->push(cont0);

    cont2->push(new leaf(4));
    cont2->push(cont1);

    cont3->push(new leaf(10));
    cont3->push(cont2);

    print pr;
    cont3->accept(&pr);
    evaluate eval;
    cont3->accept(&eval);

    // evaluate *e = dynamic_cast<evaluate *>(v); //casting to get acess to getResult()
    std::cout << "\nAns: " << eval.getResult() << std::endl;

    return 0;
}