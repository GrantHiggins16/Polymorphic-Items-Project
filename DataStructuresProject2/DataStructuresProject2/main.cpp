#include <iostream>
using namespace std;

/*
 author: grant higgins
 version: feb 7 2017
 
 A program that takes a text file representing a group of items
 and creates those items and allows for their display
 
 possibly the greatest program ever made
 
 currently set to take input from the test text file given in class
 
 note: display methods called print instead because I'm a trancendentalist (and
 I didnt read the program specs close enough)
 */

//variable indicating the current position in the bag
//also functions as a tracker of the length of the bag with
//meaningful objects
static int bagPos = 0;

/*
 class representing an item
 */
class Item
{
protected:
    int itemNumber;
    int code;
    int color;
    int brand;
    double height;
    double length;
    double width;
    double weight;
    double price;
    int type;
    
public:
    Item& operator=(const Item& item); //assignment operator
    friend ostream& operator<<(ostream& os, Item& item); //output operator
    //= operator
    Item(); //default constructor
    Item(int itemNumber, int code, int color, int brand,
         double height, double length, double width,
         double weight, double price, int type); //non-default constructor
    Item(const Item& item); //copy constructor
    virtual ~Item();//destructor for Item
    void print();//prints info about an Item
    int getItemNumber(); //returns item's number
    int getCode(); //returns the code indicating the category of the item
    double getPrice(); //returns the price of the item
    int getColor(); //returns color
    int getBrand(); //getter for brand
    double getHeight(); //getter for height
    double getLength(); //getter for length
    double getWidth(); //getter for width
    double getWeight(); //getter for weight
    int getType(); //getter for type
    
    void setItemNumber(int itemNumber); //sets itemNumber
    void setCode(int code); //sets code
    void setColor(int color);//sets color
    void setBrand(int brand);//sets brand
    void setHeight(double height);//sets height
    void setLength(double length);//sets length
    void setWidth(double width);//sets width
    void setWeight(double weight);//sets weight
    void setPrice(double price);//sets price
    void setType(int type);//sets type
    
    //todo check if we need getters and setters
};

Item& Item::operator=(const Item& item)
{
    this->setItemNumber(item.itemNumber);
    this->setCode(item.code);
    this->setColor(item.color);
    this->setBrand(item.brand);
    this->setHeight(item.height);
    this->setLength(item.length);
    this->setWidth(item.width);
    this->setWeight(item.weight);
    this->setPrice(item.price);
    this->setType(item.type);
    return *this;
}


Item::Item()
{
    //sets vars to imposible values
    itemNumber = -1;
    code = 0;
    color = 0;
    brand = 0;
    height = 0;
    length = 0;
    width = 0;
    weight = 0;
    price = 0;
    type = 0;
}

Item::Item(int itemNumber, int code, int color, int brand,
           double height, double length, double width,
           double weight, double price, int type)
{
    this->setItemNumber(itemNumber);
    this->setCode(code);
    this->setColor(color);
    this->setBrand(brand);
    this->setHeight(height);
    this->setLength(length);
    this->setWidth(width);
    this->setWeight(weight);
    this->setPrice(price);
    this->setType(type);
}

Item::Item(const Item& item)
{
    this->setItemNumber(item.itemNumber);
    this->setCode(item.code);
    this->setColor(item.color);
    this->setBrand(item.brand);
    this->setHeight(item.height);
    this->setLength(item.length);
    this->setWidth(item.width);
    this->setWeight(item.weight);
    this->setPrice(item.price);
    this->setType(item.type);
}

Item::~Item()
{
    cout << "Item destroyed" << endl;
}

void Item::print()
{
    cout << "Height: " << height << endl
    << "Length: " << length << endl
    << "Width: " << width << endl
    << "Weight: " << weight << endl
    << "Price: " << price << endl;
    //dont print type because it will be
    //printed in each individual class'
    //print statement
}

int Item::getItemNumber()
{
    return itemNumber;
}

int Item::getCode()
{
    return code;
}

double Item::getPrice()
{
    return price;
}

int Item::getColor()
{
    return this->color;
}

int Item::getBrand()
{
    return this->brand;
}

double Item::getHeight()
{
    return this->height;
}

double Item::getLength()
{
    return this->length;
}

double Item::getWidth()
{
    return this->length;
}

double Item::getWeight()
{
    return this->weight;
}

int Item::getType()
{
    return this->type;
}

void Item::setItemNumber(int itemNumber)
{
    this->itemNumber = itemNumber;
}
void Item::setCode(int code)
{
    this->code = code;
}

void Item::setColor(int color)
{
    this->color = color;
}

void Item::setBrand(int brand)
{
    this->brand = brand;
}

void Item::setHeight(double height)
{
    this->height = height;
}

void Item::setLength(double length)
{
    this->length = length;
}

void Item::setWidth(double width)
{
    this->width = width;
}

void Item::setWeight(double weight)
{
    this->weight = weight;
}

void Item::setPrice(double price)
{
    this->price = price;
}

void Item::setType(int type)
{
    this->type = type;
}

ostream& operator<<(ostream & os, Item & item)
{
    os << "Item number: " << item.getItemNumber() << endl;
    item.print();
    return os;
}

/*
 class representing a pen item
 */
class Pen : public Item
{
private:
    bool assortedInk;
    int packetSize;
    
public:
    Pen& operator=(const Pen& pen); //assignment operator
    friend ostream& operator<<(ostream& os, Pen& pen);//ostream operator
    Pen();//default constructor
    Pen(int itemNumber, int color, int brand,
        double height, double length, double width,
        double weight, double price, int type, bool assortedInk,
        int packetSize); //non-default constructor
    Pen(const Pen& pen); //copy constructor
    
    virtual ~Pen(); //destructor for pen
    void print();//prints info about a printer
    bool getAssortedInk(); //getter for assorted ink
    int getPacketSize(); //getter for packet size
};

Pen & Pen::operator=(const Pen & pen)
{
    this->assortedInk = pen.assortedInk;
    this->packetSize = pen.packetSize;
    this->setItemNumber(pen.itemNumber);
    this->setCode(pen.code);
    this->setColor(pen.color);
    this->setBrand(pen.brand);
    this->setHeight(pen.height);
    this->setLength(pen.length);
    this->setWidth(pen.width);
    this->setWeight(pen.weight);
    this->setPrice(pen.price);
    this->setType(pen.type);
    return *this;
}

Pen::Pen()
{
    assortedInk = false;//defaults asortedInk to false by default
    packetSize = 0;
}

Pen::Pen(int itemNumber, int color, int brand,
         double height, double length, double width,
         double weight, double price, int type, bool assortedInk,
         int packetSize)
: Item(itemNumber, 1, color, brand,
       height, length, width,
       weight, price, type)// 1 is due to object being a pen
{
    //todo find out if using superconstructor would be smarter
    this->assortedInk = assortedInk;
    this->packetSize = packetSize;
}

Pen::Pen(const Pen & pen)
: Item(pen)
{
    this->assortedInk = pen.assortedInk;
    this->packetSize = pen.packetSize;
}

Pen::~Pen()
{
    cout << "Pen destroyed" << endl;
}

//todo create print function
void Pen::print()
{
    cout << "Pen" << endl;
    switch (this->getColor())
    {
        case 1:
            cout << "Color: Red" << endl;
            break;
        case 2:
            cout << "Color: Blue" << endl;
            break;
        case 3:
            cout << "Color: Green" << endl;
            break;
        case 4:
            cout << "Color: Black" << endl;
        default:
            break;
    }
    switch (this->getBrand())
    {
        case 1:
            cout << "Brand: Pilot" << endl;
            break;
        case 2:
            cout << "Brand: Paper Mate" << endl;
            break;
        case 3:
            cout << "Brand: Uni-Ball" << endl;
            break;
        case 4:
            cout << "Brand: Sharpie" << endl;
            break;
        default:
            break;
    }
    Item::print();
    switch (this->getType())
    {
        case 1:
            cout << "Type: Ball Point" << endl;
            break;
        case 2:
            cout << "Type: Roller Ball" << endl;
            break;
        case 3:
            cout << "Type: Fountain" << endl;
            break;
        case 4:
            cout << "Type: Calligraphy" << endl;
            break;
        default:
            break;
    }
    switch (this->getAssortedInk())
    {
        case 0:
            cout << "Assorted Ink: No" << endl;
            break;
        case 1:
            cout << "Assorted Ink: Yes" << endl;
        default:
            break;
    }
    cout << "Packet Size: " << packetSize << endl;
}

bool Pen::getAssortedInk()
{
    return this->assortedInk;
}

int Pen::getPacketSize()
{
    return this->packetSize;
}

ostream& operator<<(ostream & os, Pen & pen)
{
    os << "Item number: " << pen.getItemNumber() << endl;
    pen.print();
    return os;
}

/*
 class representing a printer item
 */
class Printer : public Item
{
private:
    bool network;
    int trayCapacity;
    
public:
    Printer& operator=(const Printer& printer);//assignment operator
    friend ostream& operator<<(ostream& os, Printer& printer); // ostream operator
    Printer(); //default constructor
    Printer(int itemNumber, int color, int brand,
            double height, double length, double width,
            double weight, double price, int type, bool network,
            int trayCapacity); //non-default constructor
    Printer(const Printer& printer); //copy constructor
    virtual ~Printer(); //destructor for printer
    void print();//prints info about a printer
    bool getNetwork(); //getter for network
    int getTrayCapacity(); //getter for network
};


Printer& Printer::operator=(const Printer & printer)
{
    this->network = printer.network;
    this->trayCapacity = printer.network;
    this->setItemNumber(printer.itemNumber);
    this->setCode(printer.code);
    this->setColor(printer.color);
    this->setBrand(printer.brand);
    this->setHeight(printer.height);
    this->setLength(printer.length);
    this->setWidth(printer.width);
    this->setWeight(printer.weight);
    this->setPrice(printer.price);
    this->setType(printer.type);
    return *this;
}




Printer::Printer()
{
    //network is initialized to false by default
    this->network = false;
    this->trayCapacity = 0;
}

Printer::Printer(int itemNumber, int color, int brand,
                 double height, double length, double width,
                 double weight, double price, int type, bool network,
                 int trayCapacity)
: Item(itemNumber, 2, color, brand,
       height, length, width,
       weight, price, type)// 2 is due to object being a printer
{
    this->network = network;
    this->trayCapacity = trayCapacity;
}

Printer::Printer(const Printer& printer)
: Item(printer)
{
    this->network = printer.network;
    this->trayCapacity = printer.network;
}

Printer::~Printer()
{
    cout << "Printer destroyed" << endl;
}

void Printer::print()
{
    cout << "Printer" << endl;
    switch (this->getColor())
    {
        case 1:
            cout << "Color: Black" << endl;
            break;
        case 2:
            cout << "Color: White" << endl;
            break;
        default:
            break;
    }
    switch (this->getBrand())
    {
        case 1:
            cout << "Brand: Dell" << endl;
            break;
        case 2:
            cout << "Brand: HP" << endl;
            break;
        case 3:
            cout << "Brand: Cannon" << endl;
            break;
        case 4:
            cout << "Brand: Brother" << endl;
        default:
            break;
    }
    Item::print();
    switch (this->getType())
    {
        case 1:
            cout << "Type: All-In-One" << endl;
            break;
        case 2:
            cout << "Type: Laser" << endl;
            break;
        case 3:
            cout << "Type: InkJet" << endl;
            break;
        default:
            break;
    }
    switch (this->getNetwork())
    {
        case 0:
            cout << "Network: No" << endl;
            break;
        case 1:
            cout << "Network: Yes" << endl;
            break;
        default:
            break;
    }
    cout << "Tray Capacity: " << this->getTrayCapacity() << endl;
}
bool Printer::getNetwork()
{
    return this->network;
}
int Printer::getTrayCapacity()
{
    return this->trayCapacity;
}

ostream & operator<<(ostream & os, Printer & printer)
{
    os << "Item number: " << printer.getItemNumber() << endl;
    printer.print();
    return os;
}

/*
 class representing a safebox item
 */
class SafeBox : public Item
{
private:
    bool fireResistant;
    bool eLock;
    
public:
    SafeBox& operator=(SafeBox& safebox); //assignment operator
    friend ostream& operator<<(ostream& os, SafeBox& safebox); //ostream operator
    SafeBox(); //default constructor
    SafeBox(int itemNumber, int color, int brand,
            double height, double length, double width,
            double weight, double price, int type, bool fireResistant,
            bool eLock); //non-default constructor
    SafeBox(const SafeBox& safebox); //copy constructor
    virtual ~SafeBox(); //destructor for safebox
    void print();//prints info about Safe Box
    bool isfireResistant(); //getter for fire resistance
    bool hasELock(); //getter for elock
};

SafeBox& SafeBox::operator=(SafeBox & safebox)
{
    this->eLock = safebox.eLock;
    this->fireResistant = safebox.fireResistant;
    this->setItemNumber(safebox.itemNumber);
    this->setCode(safebox.code);
    this->setColor(safebox.color);
    this->setBrand(safebox.brand);
    this->setHeight(safebox.height);
    this->setLength(safebox.length);
    this->setWidth(safebox.width);
    this->setWeight(safebox.weight);
    this->setPrice(safebox.price);
    this->setType(safebox.type);
    return *this;
}

SafeBox::SafeBox()
{
    //fire resistance and electronic lock
    //capabilities are set to false by default
    this->fireResistant = false;
    this->eLock = eLock;
}

SafeBox::SafeBox(int itemNumber, int color, int brand,
                 double height, double length, double width,
                 double weight, double price, int type, bool fireResistant,
                 bool eLock)
: Item(itemNumber, 3, color, brand,
       height, length, width,
       weight, price, type)// 3 is due to object being a safebox
{
    this->fireResistant = fireResistant;
    this->eLock = eLock;
}

SafeBox::SafeBox(const SafeBox & safebox)
: Item(safebox)
{
    this->fireResistant = safebox.fireResistant;
    this->eLock = safebox.eLock;
}

SafeBox::~SafeBox()
{
    cout << "Safe box destroyed" << endl;
}

void SafeBox::print()
{
    cout << "Safe Box: " << endl;
    switch (this->getColor())
    {
        case 1:
            cout << "Color: Black" << endl;
            break;
        case 2:
            cout << "Color: Red" << endl;
            break;
        default:
            break;
    }
    switch (this->getBrand())
    {
        case 1:
            cout << "Brand: SentrySafe" << endl;
            break;
        case 2:
            cout << "Brand: First Alert" << endl;
            break;
        case 3:
            cout << "Brand: Honeywell" << endl;
        default:
            break;
    }
    Item::print();
    switch (this->getType())
    {
        case 1:
            cout << "Type: Water Proof" << endl;
            break;
        case 2:
            cout << "Type: Wall Mountable" << endl;
            break;
        case 3:
            cout << "Type: Desktop" << endl;
            break;
        default:
            break;
    }
    switch (this->isfireResistant())
    {
        case 0:
            cout << "Fire Resistant: No" << endl;
            break;
        case 1:
            cout << "Fire Resistant: Yes" << endl;
            break;
        default:
            break;
    }
    switch (this->hasELock())
    {
        case 0:
            cout << "Electronic Lock: No" << endl;
            break;
        case 1:
            cout << "Electronic Lock: Yes" << endl;
            break;
        default:
            break;
    }
}

bool SafeBox::isfireResistant()
{
    return this->fireResistant;
}

bool SafeBox::hasELock()
{
    return this->eLock;
}

ostream & operator<<(ostream & os, SafeBox & safebox)
{
    os << "Item number: " << safebox.itemNumber << endl;
    safebox.print();
    return os;
}


//class representing a bag of items
class Bag
{
protected:
    Item **myItems;
    int numItems;
public:
    friend ostream& operator<<(ostream& os, Bag& bag);//output operator
    Bag& operator=(Bag& bag);//assignment operator
    Bag();//default constructor
    Bag(Item item); //non-default constructor
    Bag(const Bag& bag); //copy constructor
    virtual ~Bag(); //destructor
    void addItem(Item *item);//add item to the bag
    void deleteItems(int itemNumber);//delete items from the bag
    Item** getMyItems(); //getter for myItems
    int getNumItems(); //getter for num items
};

Bag::~Bag()
{
    delete[] myItems;
}
Bag::Bag(const Bag& bag)
{
    this->myItems = bag.myItems;
    this->numItems = bag.numItems;
}
Item** Bag::getMyItems()
{
    return myItems;
}

int Bag::getNumItems()
{
    return numItems;
}

Bag& Bag::operator=(Bag& bag)
{
    this->myItems = bag.getMyItems();
    this->numItems = bag.getNumItems();
    return *this;
}

Bag::Bag()
{
    myItems = new Item *[1];
    numItems = 0;
}

Bag::Bag(Item item)
{
    myItems = new Item *[1];
    numItems = 1;
    Item *toAdd = new Item(item);
    myItems[0] = toAdd;
    delete toAdd;
}

void Bag::addItem(Item *item)
{
    Item** temp = myItems;
    numItems++;
    myItems = new Item *[numItems];
    for (int i = 0; i < numItems - 1; i++)
    {
        myItems[i] = temp[i];
        temp[i] = NULL;
    }
    delete[] temp;
    myItems[numItems - 1] = item;
}

void Bag::deleteItems(int itemNumber)
{
    for (int i = 0; i < numItems; i++)
    {
        int itemNumberToCheck = myItems[i]->getItemNumber();
        if (itemNumber == itemNumberToCheck)
        {
            Item** temp = myItems;
            numItems--;
            myItems = new Item *[numItems];
            //creates myItems with all but the item to delete
            for (int j = 0; j < i; j++)
            {
                myItems[j] = temp[j];
                temp[j] = NULL;
            }
            for (int j = i; j < numItems; j++)
            {
                myItems[j] = temp[j + 1];
                temp[j + 1] = NULL;
            }
            delete[] temp;
            //to make sure all possible indecies are checked
            i--;
        }
    }
}
//below you will find my abandoned hopes and dreams
//please join me in a moment of silence



///*
//creates specified items and adds them to bag
//*/
//template<typename T1>
//void addItems(Item* bag, int& quantity, T1 item)
//{
//	for (int i = 0; i < quantity; i++)
//	{
//		bag[bagPos] = item;
//		bagPos++;
//	}
//}
//
//template <typename T1>//templates for types of special traits of different items
//void addItems(Item* bag, int& quantity, int& code, int& color, int& brand, double& height,
//	double& length, double& width, double& weight, double& price,
//	int& type, bool& specialTrait0, T1& specialTrait1)
//{
//	//creates the correct object
//	switch (code)
//	{
//	case 1:
//		//pen
//		//todo change special traits so you can put them in pen constructor
//		for (int i = 0; i < quantity; i++)
//		{
//			bag[bagPos] = Pen(color, brand, height, length, width,
//				weight, price, type, specialTrait0, specialTrait1);
//			bagPos++;
//		}
//		break;
//	case 2:
//		//printer
//		for (int i = 0; i < quantity; i++)
//		{
//			bag[bagPos] = Printer(color, brand, height, length, width,
//				weight, price, type, specialTrait0, specialTrait1);
//			bagPos++;
//		}
//		break;
//	case 3:
//		//safebox
//		for (int i = 0; i < quantity; i++)
//		{
//			bag[bagPos] = SafeBox(color, brand, height, length, width,
//				weight, price, type, specialTrait0, specialTrait1);
//			bagPos++;
//		}
//		break;
//	default:
//		cout << "you messed up. line 105. type is invalid" << endl;
//		break;
//	}
//}

/*
 prints summary info about all items in the bag
 */
void printBag(Item* bag[], int numItems)
{
    int numPens = 0;
    int numPrinters = 0;
    int numSafeBoxes = 0;
    double totalPrice = 0;
    double penPrice = 0;
    double printerPrice = 0;
    double safeBoxPrice = 0;
    
    //loops through all objects in bag
    //and prints using correct print function
    for (int i = 0; i < numItems; i++)
    {
        switch (bag[i]->getCode())
        {
            case 1:
                //pen
                penPrice += bag[i]->getPrice();
                numPens++;
                break;
            case 2:
                //printer
                printerPrice += bag[i]->getPrice();
                numPrinters++;
                break;
            case 3:
                //safebox
                safeBoxPrice += bag[i]->getPrice();
                numSafeBoxes++;
                break;
            default:
                break;
        }
    }
    totalPrice = penPrice + printerPrice + safeBoxPrice;
    
    cout << "Number of Pens: " << numPens << endl
    << "Price of Pens: " << penPrice << endl
    << "Number of Printers: " << numPrinters << endl
    << "Price of Printers: " << printerPrice << endl
    << "Number of Safe Boxes: " << numSafeBoxes << endl
    << "Price of Safe Boxes: " << safeBoxPrice << endl
    << "Total Price: " << totalPrice << endl;
    
}

ostream & operator<<(ostream & os, Bag & bag)
{
    printBag(bag.getMyItems(), bag.getNumItems());
    return os;
}
/*
 prints item associated with index
 */
void printItem(Item* bag[], int index)
{
    cout << "Item number " << index + 1 << ": " << endl << endl;
    switch (bag[index]->getCode())
    {
        case 1:
            //pen
            cout << *(static_cast<Pen*>(bag[index]));
            cout << endl;
            break;
        case 2:
            //printer
            cout << *(static_cast<Printer*>(bag[index]));
            cout << endl;
            break;
        case 3:
            //safebox
            cout << *(static_cast<SafeBox*>(bag[index]));
            cout << endl;
            break;
        default:
            break;
    }
}

/*
 null initializes bag
 */
void nullInitializeBag(Item* bag, int length)
{
    for (int i = 0; i < length; i++)
    {
        bag[i] = Item();
    }
}


int main()
{
    //array of all Items
    Item* bag[1000];
    
    Pen* onePen;
    Printer* onePrinter;
    SafeBox* oneSafeBox;
    //array of chars to hold the AddItem command
    char addItemCommand[8];
    
    int userID;
    int itemNumber;
    int quantity;
    int code;
    int color;
    int brand;
    double height;
    double length;
    double width;
    double weight;
    double price;
    int type;
    bool uniqueAttribute0;
    
    bool userFound = false;
    
    int users[50];
    int numUsers = 0;
    Bag* userBag[50];
    
    for (int i = 0; i < 50; i++)
    {
        userBag[i] = new Bag();
    }
    
    while (!cin.eof()) //while end of line is not reached
    {
        cin >> addItemCommand >> userID >> itemNumber;
        
        if (addItemCommand[0] == 'D')
        {
            for (int i = 0; i < numUsers; i++)
            {
                if (users[i] == userID)
                {
                    userBag[i]->deleteItems(itemNumber);
                    cout << "Item number " << itemNumber
                    << " for user number " << userID
                    << " deleted" << endl;
                }
            }
        }
        else
        {
            cin >> quantity >> code >> color >> brand
            >> height >> length >> width >> weight >> price >> type
            >> uniqueAttribute0;
            
            switch (code)
            {
                case 1:
                    //pen
                    int uniqueAttributePen;
                    cin >> uniqueAttributePen;
                    
                    cout << addItemCommand << ", " << userID << ", "
                    << itemNumber << ", " << quantity << ", " << code << ", " << color << ", " << brand << ", "
                    << height << ", " << length << ", " << width << ", " << weight << ", " << price << ", " << type << ", "
                    << uniqueAttribute0 << ", " << uniqueAttributePen << endl;
                    
                    onePen = new Pen(itemNumber, color, brand, height, length,
                                     width, weight, price, type, uniqueAttribute0, uniqueAttributePen);
                    
                    for (int i = 0; i < numUsers; i++)
                    {
                        if (users[i] == userID)
                        {
                            for (int j = 0; j < quantity; j++)
                            {
                                userBag[i]->addItem(onePen);
                            }
                            userFound = true;
                        }
                    }
                    if (!userFound)
                    {
                        users[numUsers] = userID;
                        for (int j = 0; j < quantity; j++)
                        {
                            userBag[numUsers]->addItem(onePen);
                        }
                        numUsers++;
                    }
                    userFound = false;
                    break;
                case 2:
                    //printer
                    int uniqueAttributePrinter;
                    cin >> uniqueAttributePrinter;
                    
                    cout << addItemCommand << ", " << userID << ", "
                    << itemNumber << ", " << quantity << ", " << code << ", " << color << ", " << brand << ", "
                    << height << ", " << length << ", " << width << ", " << weight << ", " << price << ", " << type << ", "
                    << uniqueAttribute0 << ", " << uniqueAttributePrinter << endl;
                    
                    onePrinter = new Printer(itemNumber, color, brand, height, length,
                                             width, weight, price, type, uniqueAttribute0, uniqueAttributePrinter);
                    //adds correct number of printers to bag
                    for (int i = 0; i < numUsers; i++)
                    {
                        if (users[i] == userID)
                        {
                            for (int j = 0; j < quantity; j++)
                            {
                                userBag[i]->addItem(onePrinter);
                            }
                            userFound = true;
                        }
                    }
                    if (!userFound)
                    {
                        users[numUsers] = userID;
                        for (int j = 0; j < quantity; j++)
                        {
                            userBag[numUsers]->addItem(onePrinter);
                        }
                        numUsers++;
                    }
                    userFound = false;
                    break;
                case 3:
                    //safebox
                    bool uniqueAttributeSafeBox;
                    cin >> uniqueAttributeSafeBox;
                    
                    cout << addItemCommand << ", " << userID << ", "
                    << itemNumber << ", " << quantity << ", " << code << ", " << color << ", " << brand << ", "
                    << height << ", " << length << ", " << width << ", " << weight << ", " << price << ", " << type << ", "
                    << uniqueAttribute0 << ", " << uniqueAttributeSafeBox << endl;
                    
                    oneSafeBox = new SafeBox(itemNumber, color, brand, height, length,
                                             width, weight, price, type, uniqueAttribute0, uniqueAttributeSafeBox);
                    //adds correct number of safeboxes to bag
                    for (int i = 0; i < numUsers; i++)
                    {
                        if (users[i] == userID)
                        {
                            for (int j = 0; j < quantity; j++)
                            {
                                userBag[i]->addItem(oneSafeBox);
                            }
                            userFound = true;
                        }
                    }
                    if (!userFound)
                    {
                        users[numUsers] = userID;
                        for (int j = 0; j < quantity; j++)
                        {
                            userBag[numUsers]->addItem(oneSafeBox);
                        }
                        numUsers++;
                    }
                    userFound = false;
                    break;
                default:
                    cout << "you messed up. line 327. type is invalid" << endl;
                    break;
            }
            
        }
        
        
    }
    //prints specific item based on index
    for (int i = 0; i < numUsers; i++)
    {
        cout << endl;
        cout << "User number: " << users[i] << endl;
        cout << *userBag[i] << endl;
        cout << "Items in bag: " << endl << endl << endl;
        for (int j = 0; j < userBag[i]->getNumItems(); j++)
        {
            printItem((userBag[i]->getMyItems()), j);
            cout << endl;
        }
    }
    //prints summary of entire bag
}

