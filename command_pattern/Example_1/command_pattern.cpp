#include <string>
#include <vector>
#include <iostream>

class Stock
{
public :
    Stock() = delete;
    Stock(const std::string name, int quantity)
        : _name{name} , _quantity{quantity}
    {

    }
    void buy()
    {
        std::cout << "User " << _name << " bought stock of size " << _quantity << '\n';
    }
    void sell()
    {
        std::cout << "User " << _name << " sold stock of size " << _quantity << '\n';
    }
private :
    std::string _name ;
    int _quantity;
};

class Order
{
public :
    Order() = default;
    Order(Stock* stock)
        : theStock {stock}
    {
        
    }
    virtual void execute() = 0;
protected :
    Stock* theStock;
};

class BuyStock : public Order
{
public :
    BuyStock(Stock* stock)
        : Order {stock}
    {
        
    }
    virtual void execute() override
    {
        theStock->buy();
    }
};

class SellStock : public Order
{
public :
    SellStock(Stock* stock)
        : Order {stock}
    {

    }
    virtual void execute() override
    {
        theStock->sell();
    }
};

class Broker 
{
public :
    Broker() = default;
    void takeOrder(Order* order)
    {
        orders.emplace_back(order);
    }
    void placeOrders()
    {
        for(Order* order : orders)
        {
            order->execute();
        }
        orders.clear();
    }
private :
    std::vector<Order*> orders;
};

int main()
{
    Stock* abcStock = new Stock("Nayem", 30);

    BuyStock* buyStockOrder = new BuyStock(abcStock);
    SellStock* sellStockOrder = new SellStock(abcStock);

    Broker* broker = new Broker();
    broker->takeOrder(buyStockOrder);
    broker->takeOrder(sellStockOrder);

    broker->placeOrders();
}