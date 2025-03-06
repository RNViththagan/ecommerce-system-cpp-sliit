#include<iostream>
#include<string>
using namespace std;
class User
{
protected:
	string userName;
	string password;
	 int Id;
public:
	User(string userName, string password,int Id);
	~User();
};

User::User(string userName, string password,int Id)
{
	this->userName = userName;
	this->password = password;
	this->Id = Id;
}

User::~User()
{
	cout << "User deleted" << endl;
}


class Product
{
private:
	string productName;
	string productId;
	float price;
	int quantity;
public:
	Product(string productName, string productId, float price, int quantity);
	void setQuantity(int quantity);
	void setPrice(int price);
	float getPrice();
	void displayProduct();
};

Product::Product(string productName, string productId, float price, int quantity)
{
	this->productName = productName;
	this->productId = productId;
	this->price = price;
	this->quantity = quantity;
}

void Product::setQuantity(int quantity)
{
	this->quantity = quantity;
}

void Product::displayProduct()
{
	cout << "product name is :" << productName << endl;
	cout << "product Price is :" << price << endl;
	cout << "Product quantity is :" << quantity << endl;
}
float Product::getPrice()
{
	return price;

}


class wishlist
{
private:
	int wishlistId;
	Product* prd[100];
	static int procount;
public:
	wishlist();
	void savetoWishlist(Product p);
	void displayWishlist();
};
int wishlist::procount = 0;
wishlist::wishlist(int i)
{
	this->wishlistId = i;
}
void wishlist::savetoWishlist(Product p)
{
	prd[procount] = p;
	procount++;
}
void wishlist::displayWishlist()
{
	for (int a = 0; a <= procount; a++)
	{
		prd[a]->displayProduct();
	}
}
class customer :public User
{
private:
	string Name;
	wishlist* wish;
	cart* C;
	static int j;
public:
	customer();
	void dispalyCusDetails();
	void addtowishlist(Product p);
};


int customer::j = 1;
customer::customer(string Name) :User(userName, password, Id)
{
	this->Name = Name;
	wish = new wishlist(j);
	j++;
	C = new customer cart(Date,cartId,List);

}
void customer::viewProduct(Product p)
{
	p.displayProduct();
}
void customer::addtowishlist(Product p)
{
	wish->savetoWishlist(p);
}
void customer::dispalyCusDetails()
{
	cout << " Customer Name :" << Name << endl;
	cout << " User Name :" << userName << endl;
	cout << " Customer ID :" << Id << endl;
}


class Shopowner
{
private:
	string shopownerID;
	string shopId;
	Product *prd[100];
	static int count;
public:
	Shopowner(string userName,string password,string shopownerID,string shopId);
	void addProduct(string productName, string productId, float price, int quantity);
	~Shopowner();
};

Shopowner::Shopowner(string userName, string password, string shopownerID, string shopId)
{
	this->shopId = shopId;
	count= 0;
}

void Shopowner::addProduct(string productName, string productId, float price, int quantity)
{
	prd[count] = new Product(productName, productId, price, quantity);
	count++;
}


Shopowner::~Shopowner()
{
	cout << "Shopowner deleted" << endl;
	for (int i = 0; i < count; i++)
	{
		delete prd[i];
	}
}



class OrderDetails
{
private:

	int orderNo;
	float Amount;

public:
	/*OrderDetails()
	{
	}*/
	OrderDetails(Product* P, int orderNo, int Q)
	{
		this->orderNo = orderNo;
		this->Amount = P->getPrice() * Q;
	}
	float getAmount()
	{
		return this->Amount;
	}
	int getOrderNo()
	{
		return this->orderNo;
	}
};

class cart
{
private:
	static int i;
	int cartId;
	string Date;
	OrderDetails* OD[10];
	int list;
public:
	cart(char Date[], int cartId, int List);
	void addorderDetails(OrderDetails* ODetails);
	void Displaycart();
};
cart::cart(char Date, int cartId, int List)
{
	i = 0;
	this->List = List;
	this->C = C;
	this->Date = Date;
}
cart::addorderDetails(OrderDetails* ODetails)
{
	OD[i] = ODetails;
	i++;
}
void cart::Displaycart()
{
	cout << "Date :" << Date << endl;
	cout << " No of amount " << endl;
	for (int i = 0; i < this->list; i++)
	{
		cout << OD[i]->getOrderNo() << "     " << OD[i]->getAmount() << endl;
	}
}


