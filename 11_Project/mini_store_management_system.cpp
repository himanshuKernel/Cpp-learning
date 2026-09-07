#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <ctime>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// -------------------- STRUCTS --------------------

struct Product{
    int productID;
    string name;
    string category;
};

struct Order{
    int orderID;
    int productID;
    int quantity;
    string customerID;
    time_t orderDate;
};

// -------------------- DISPLAY PRODUCTS --------------------

void displayProducts(const vector<Product>& products){
    cout << "\n========== ALL PRODUCTS ==========\n";

    for (const auto& product : products)
    {
        cout << "ID       : " << product.productID << endl;
        cout << "Name     : " << product.name << endl;
        cout << "Category : " << product.category << endl;
        cout << "-----------------------------\n";
    }
}

// -------------------- SEARCH PRODUCT --------------------

void searchProduct(const vector<Product>& products, int productID){
    for (const auto& product : products)
    {
        if (product.productID == productID)
        {
            cout << "\nProduct Found!\n";
            cout << "ID       : " << product.productID << endl;
            cout << "Name     : " << product.name << endl;
            cout << "Category : " << product.category << endl;
            return;
        }
    }

    cout << "\nProduct not found.\n";
}

// -------------------- DISPLAY CUSTOMERS --------------------

void displayCustomers(const unordered_map<string, string>& customerData){
    cout << "\n========== CUSTOMERS ==========\n";

    for (const auto& customer : customerData)
        cout << "Customer ID : " << customer.first<< " | Name : " << customer.second << endl;
    
}

// -------------------- DISPLAY CATEGORIES --------------------

void displayCategories(const set<string>& categories){
    cout << "\n========== CATEGORIES ==========\n";

    for (const auto& category : categories)
        cout << "- " << category << endl;
    
}

// -------------------- DISPLAY STOCK --------------------

void displayStock(const map<int, int>& productStock,const vector<Product>& products){
    cout << "\n========== PRODUCT STOCK ==========\n";

    for (const auto& product : products)
    
        cout << product.name<< " (ID: " << product.productID << ")"<< " -> " << productStock.at(product.productID)<< " units\n";
    
}

// -------------------- DISPLAY RECENT CUSTOMERS --------------------

void displayRecentCustomers(const deque<string>& recentCustomers){
    cout << "\n========== RECENT CUSTOMERS ==========\n";

    for (const auto& customer : recentCustomers)
        cout << customer << " ";
    
    cout << endl;
}
// -------------------- DISPLAY ORDERS --------------------

void displayOrders(const list<Order>& orderHistory){
    cout << "\n========== ORDER HISTORY ==========\n";

    if (orderHistory.empty()){
        cout << "No orders found.\n";
        return;
    }

    for (const auto& order : orderHistory){
        cout << "Order ID    : " << order.orderID << endl;
        cout << "Product ID  : " << order.productID << endl;
        cout << "Quantity    : " << order.quantity << endl;
        cout << "Customer ID : " << order.customerID << endl;
        cout << "-----------------------------\n";
    }
}

// -------------------- PLACE ORDER --------------------

bool placeOrder(list<Order>& orderHistory, map<int, int>& productStock, int productID,int quantity, const string& customerID){
    // Check product
    if (productStock.find(productID) == productStock.end()){
        cout << "Product does not exist.\n";
        return false;
    }

    // Check quantity
    if (quantity <= 0){
        cout << "Quantity must be greater than 0.\n";
        return false;
    }

    // Check stock
    if (productStock[productID] < quantity){
        cout << "Not enough stock available.\n";
        return false;
    }

    // Create order ID
    int orderID;

    if (orderHistory.empty())
        orderID = 1;
    else
        orderID = orderHistory.back().orderID + 1;

    Order newOrder = { orderID,productID,quantity,customerID,time(0)};

    // Add order
    orderHistory.push_back(newOrder);

    // Reduce stock
    productStock[productID] -= quantity;

    cout << "\nOrder placed successfully!\n";
    cout << "Order ID : " << orderID << endl;

    return true;
}

// -------------------- CUSTOMER ORDERS --------------------

void displayCustomerOrders(const multimap<string, Order>& customerOrders,const string& customerID){
    cout << "\n========== CUSTOMER ORDERS ==========\n";

    auto range = customerOrders.equal_range(customerID);

    if (range.first == range.second){
        cout << "No orders found for this customer.\n";
        return;
    }

    for (auto it = range.first; it != range.second; ++it){
        cout << "Order ID   : " << it->second.orderID << endl;
        cout << "Product ID : " << it->second.productID << endl;
        cout << "Quantity   : " << it->second.quantity << endl;
        cout << "-----------------------------\n";
    }
}

// -------------------- MAIN --------------------

int main()
{
    // ---------------- VECTOR ----------------

    vector<Product> products ={
        {101, "Laptop", "Electronics"},
        {102, "SmartPhone", "Electronics"},
        {103, "Coffee Maker", "Kitchen"},
        {104, "Blender", "Kitchen"},
        {105, "Desk Lamp", "Home"}
    };


    // ---------------- DEQUE ----------------

    deque<string> recentCustomers ={
        "C001", "C002", "C003"
    };

    recentCustomers.push_back("C004");
    recentCustomers.push_front("C005");


    // ---------------- LIST ----------------

    list<Order> orderHistory;

    orderHistory.push_back({1, 101, 1, "C001", time(0)});

    orderHistory.push_back( {2, 102, 2, "C002", time(0)});

    orderHistory.push_back({3, 103, 1, "C003", time(0)});


    // ---------------- SET ----------------

    set<string> categories;

    for (const auto& product : products)
        categories.insert(product.category);
    


    // ---------------- MAP ----------------

    map<int, int> productStock ={{101, 10}, {102, 20}, {103, 15}, {104, 5}, {105, 7}};


    // ---------------- MULTIMAP ----------------

    multimap<string, Order> customerOrders;

    for (const auto& order : orderHistory){
        customerOrders.insert( {order.customerID, order});
    }


    // ---------------- UNORDERED MAP ----------------

    unordered_map<string, string> customerData ={{"C001", "Himanshu"},{"C002", "Vansh"},{"C003", "Dhananjay"},{"C004", "Nihal"},{"C005", "Roushan"}};


    // ---------------- UNORDERED SET ----------------

    unordered_set<int> uniqueProductIDs;

    for (const auto& product : products)
        uniqueProductIDs.insert(product.productID);

    // ---------------- MENU ----------------

    int choice;

    do{
        cout << "\n\n========== MINI STORE ==========\n";
        cout << "1. Display all products\n";
        cout << "2. Search product\n";
        cout << "3. Display categories\n";
        cout << "4. Display product stock\n";
        cout << "5. Display customers\n";
        cout << "6. Display recent customers\n";
        cout << "7. Display order history\n";
        cout << "8. Place new order\n";
        cout << "9. Display customer orders\n";
        cout << "10. Display unique product IDs\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                displayProducts(products);
                break;


            case 2:{
                int id;

                cout << "Enter product ID: ";
                cin >> id;

                searchProduct(products, id);

                break;
            }


            case 3:
                displayCategories(categories);
                break;


            case 4:
                displayStock(productStock, products);
                break;


            case 5:
                displayCustomers(customerData);
                break;


            case 6:
                displayRecentCustomers(recentCustomers);
                break;


            case 7:
                displayOrders(orderHistory);
                break;


            case 8:{
                int productID;
                int quantity;
                string customerID;

                cout << "Enter customer ID: ";
                cin >> customerID;

                cout << "Enter product ID: ";
                cin >> productID;

                cout << "Enter quantity: ";
                cin >> quantity;

                bool success = placeOrder(orderHistory,productStock,productID, quantity,customerID );

                // Add to customer orders only if order succeeded
                if (success){
                    customerOrders.insert({customerID, orderHistory.back()});

                    recentCustomers.push_back(customerID);

                    if (recentCustomers.size() > 5){
                        recentCustomers.pop_front();
                    }
                }

                break;
            }


            case 9:{
                string customerID;

                cout << "Enter customer ID: ";
                cin >> customerID;

                displayCustomerOrders( customerOrders,customerID  );
                 break;
            }


            case 10:{
                cout << "\n========== UNIQUE PRODUCT IDs ==========\n";

                for (const auto& id : uniqueProductIDs)
                    cout << id << " ";
                

                cout << endl;

                break;
            }


            case 0:
                cout << "\nExiting store...\n";
                break;


            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 0);


    return 0;
}