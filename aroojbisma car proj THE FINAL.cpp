//preprocessor directives
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

// Structure for vehicles
//object
struct Vehicle {
    int id;
    string name;  //name of vehicle
    float rentalRate;  //rate of a car
    bool available; // true = Yes, false = No
};


//structture for customer
struct Customer {
    string name;  //name of a customer
    string contact;  //contact of customer
};

//structure for booking
struct Booking {
    int vehicleId; //carID
    string customerName;
    string status; // "Booked", "Cancelled", or "Paid"
};

// Function prototypes
//function declaration
bool adminLogin();      
//for display available cars
void displayVehicle(Vehicle vehicles[], int vehicleCount); 
//add cars
void addVehicle(Vehicle vehicles[], int &vehicleCount);          
//delete cars
void deleteVehicle(Vehicle vehicles[], int &vehicleCount);
//search cars
void searchVehicle(Vehicle vehicles[], int vehicleCount);
//update rents
void updateRentalRate(Vehicle vehicles[], int vehicleCount);
//registration
void registerCustomer(Customer customers[], int &customerCount);
//for booking
void bookVehicle(Vehicle vehicles[], int vehicleCount, Booking bookings[], int &bookingCount, Customer customers[], int customerCount);  //pass by reference
//cancel booking
void cancelBooking(Booking bookings[], int &bookingCount, Vehicle vehicles[], int vehicleCount);
//payment
void processPayment(Booking bookings[], int bookingCount, Vehicle vehicles[], int vehicleCount);
//main 
int main() 
{
    // Admin Login
    while (!adminLogin()) 
	{
        cout << "Please try logging in again.\n";
    }

    // Constants
    const int MAX_VEHICLES = 100;
    const int MAX_CUSTOMERS = 100;
    const int MAX_BOOKINGS = 100;

    // Arrays for storage
    Vehicle vehicles[MAX_VEHICLES];
    Customer customers[MAX_CUSTOMERS];
    Booking bookings[MAX_BOOKINGS];

    // Counters
    int vehicleCount = 0, customerCount = 0, bookingCount = 0;

      // Initial vehicles
    vehicles[vehicleCount++] = {1, "Toyota Corolla", 4200.5, true};
    vehicles[vehicleCount++] = {2, "Honda Civic", 5000.0, true};
    vehicles[vehicleCount++] = {3, "BMW 3 Series", 10000.0, false};
    vehicles[vehicleCount++] = {4, "Mercedes C-class", 40000.5, true};
    vehicles[vehicleCount++] = {5, "Audi A4", 50000.0, true};
    vehicles[vehicleCount++] = {6, "Ford Mustang", 10000.0, false};
    vehicles[vehicleCount++] = {7, "Hyundai Santa Fe", 4000.5, true};
    vehicles[vehicleCount++] = {8, "Tesla Model S", 50000.0, true};
    vehicles[vehicleCount++] = {9, "Kia Sorento", 10000.0, true};
    vehicles[vehicleCount++] = {10, "Jaguar E-Pace", 4000.5, false};
     
    
    int choice;   
    do {                //loop to check user input between 1to10 
        // colors
	    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	    SetConsoleTextAttribute(h,7);
        cout << "\nCar Rental System Menu:\n";
        cout << "1. Display Vehicle\n";
        cout << "2. Add Vehicle\n";
        cout << "3. Delete Vehicle\n";
        cout << "4. Search Rental Rate\n";
        cout << "5. Update Vechile\n";
        cout << "6. Register Customer \n";
        cout << "7. Book Vechile\n";
        cout << "8. Cancel Booking\n";
        cout << "9. Process Payment\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; 

        switch (choice)
		{
		    case 1:
                displayVehicle(vehicles, vehicleCount);       //display all vehicle  
				break;
            case 2:
                addVehicle(vehicles, vehicleCount);           //add vehicles
                break; 
            case 3:
                deleteVehicle(vehicles, vehicleCount);        //delete vehicles
                break;
            case 4:
                searchVehicle(vehicles, vehicleCount);        //find vehicles
                break;
            case 5:
                updateRentalRate(vehicles, vehicleCount);     //change rents
                break;
            case 6:
                registerCustomer(customers, customerCount);    //registration
                break;
            case 7:
                bookVehicle(vehicles, vehicleCount, bookings, bookingCount, customers, customerCount);                           //book vehicle
                break;
            case 8:
                cancelBooking(bookings, bookingCount, vehicles, vehicleCount);
                break;                                         //cancel booking
            case 9:
                processPayment(bookings, bookingCount, vehicles, vehicleCount);
                break;                                        //payment processing
            case 10:
                cout << "Exiting the system. Goodbye!\n";          
                break;
            default:
                cout << "Invalid choice. Please try again.\n";    //wrong choice
        }
    } while (choice != 10);    //condition check

         
    return 0;
}

// Login Function
bool adminLogin() 
{
	// colors
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,12);
    string username, enterPassword, setusername= "bisma and arooj" , setPassword = "carproj001";
    for(int i=1;i<=60;i++)         //loop 
	{
		cout<<"--";
	}
	cout<<endl;                   //for next line
	cout<<"                                          WELCOME TO CAR PROJECT                                           "<<endl;
	cout<<endl;
	for(int i=1;i<=60;i++)
	{
		cout<<"--";
	
	}
    cout<<endl;
    cout << "Enter Username: ";
    getline(cin, username);
  
    

         if ( username == "arooj" || username=="bisma" || username == setusername )
         {
              cout << "Enter Password: ";
            cin >> enterPassword;
             // Clear the input buffer to avoid issues with the next input
            cin.ignore();

            if (enterPassword == setPassword  )
            {
                cout << "Logged in successfully.\n";
                return true; 
            }
            else
            {
                cout << "Incorrect password  . Try again.\n";
                return false;          //if user type wrong password
            }
         }
          else
          {
              cout << "Incorrect  username . Try again.\n";
              return false;          //if user type wrong password
          }
   
   }

// Vehicle Management Functions

//funtion definition of dispaly vehicle vehicles
void displayVehicle(Vehicle vehicles[], int vehicleCount)
{
	// colors
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,13);
    cout << "\nAvailable Vehicles:\n";
    for (int i = 0; i < vehicleCount; i++) 
	{
        cout << "ID: " << vehicles[i].id << ", Name: " << vehicles[i].name
             << ", Rate: $" << vehicles[i].rentalRate
             << ", Available: " << (vehicles[i].available ? "Yes" : "No") << endl;
    }
}

//funtion definition of add new vehicles
void addVehicle(Vehicle vehicles[], int &vehicleCount) 
{
	// colors
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,2);
    if (vehicleCount >= 100) 
	{                      
        cout << "Cannot add more vehicles. Limit reached.\n";
        return;
    }
    Vehicle newVehicle;
    cout << "Enter Vehicle ID: ";
    cin >> newVehicle.id;
    cin.ignore();           //to input again without any issue
    cout << "Enter Vehicle Name: ";
    getline(cin, newVehicle.name);    //to input full  vehicle name
    cout << "Enter Rental Rate: ";
    cin >> newVehicle.rentalRate;
    newVehicle.available = true;           //vehicle is avaliable
    vehicles[vehicleCount++] = newVehicle;
    cout << "Vehicle added successfully.\n";
}

//funtion definition of delete vehicle
void deleteVehicle(Vehicle vehicles[], int &vehicleCount) 
{
	// colors
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,5);
    int id;
    cout << "Enter Vehicle ID to delete: ";
    cin >> id;

    for (int i = 0; i < vehicleCount; i++)
    {
        if (vehicles[i].id == id) 
		{
            for (int j = i; j < vehicleCount - 1; j++) 
			{
                vehicles[j] = vehicles[j + 1];
            }
            vehicleCount--;
            cout << "Vehicle deleted successfully.\n";
            return;
        }
    }
    cout << "Vehicle not found.\n";
}

//funtion definition of searchng vehicles
void searchVehicle(Vehicle vehicles[], int vehicleCount) 
{
	// colors
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,1);
    int id;
    cout << "Enter Vehicle ID to search: ";
    cin >> id;
    
   // loop  to  check  input vehicle id 
    for (int i = 0; i < vehicleCount; i++) 
	{             //loop to check all vehicles
        if (vehicles[i].id == id)
		{
            cout << "ID: " << vehicles[i].id << ", Name: " << vehicles[i].name
                 << ", Rate: $" << vehicles[i].rentalRate
                 << ", Available: " << (vehicles[i].available ? "Yes" : "No") << endl;
            return;
        }
    }
    // if vehicle not exist in shop
    cout << "Vehicle not found.\n";
}

//function definition of update rents
void updateRentalRate(Vehicle vehicles[], int vehicleCount)
{
	// colors
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,4);
    int id;
    float newRate;
    cout << "Enter Vehicle ID to update rate: ";
    cin >> id;

    for (int i = 0; i < vehicleCount; i++)
	{
        if (vehicles[i].id == id) 
		{                     //i used to check all vehicles
            cout << "Enter new rental rate: ";
            cin >> newRate;
            vehicles[i].rentalRate = newRate;
            cout << "Rental rate updated successfully.\n";
            return;
        }
    }
    //if input id doesn't match with any  id
    cout << "Vehicle not found.\n";
}

// Booking Management Functions
//function definiton of registration
void registerCustomer(Customer customers[], int &customerCount) 
{
	// colors
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,5);
    if (customerCount >= 100) 
	{
        cout << "Cannot register more customers. Limit reached.\n";
        return;
    }
    Customer newCustomer;
    cin.ignore();
    cout << "Enter Customer Name: ";
    getline(cin, newCustomer.name);
    cout << "Enter Contact Information: ";
    getline(cin, newCustomer.contact);
    customers[customerCount++] = newCustomer;
    cout << "Customer registered successfully.\n";
}

//function definition of booking vehicle
void bookVehicle(Vehicle vehicles[], int vehicleCount, Booking bookings[], int &bookingCount, Customer customers[], int customerCount) 
{
	// colors
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,1);
    if (bookingCount >= 100) 
	{
        cout << "Cannot process more bookings. Limit reached.\n";
        return;
    }
    int vehicleId;
    string customerName;

    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, customerName);

    bool customerFound = false;
    for (int i = 0; i < customerCount; i++) 
	{
        if (customers[i].name == customerName) 
		{
            customerFound = true;
            break;
        }
    }
    if (!customerFound) 
	{
        cout << "Customer not found. Please register first.\n";
        
        return;
    }

    cout << "Enter Vehicle ID to book: ";
    cin >> vehicleId;

    for (int i = 0; i < vehicleCount; i++) 
	{
        if (vehicles[i].id == vehicleId && vehicles[i].available) 
		{
            vehicles[i].available = false;
            bookings[bookingCount++] = {vehicleId, customerName, "Booked"};
            cout << "\t Vehicle booked successfully.\n";
            cout<< " \t REMEMBER : The booking can not be cancelled after payment." << endl;
            return;
        }
    }
    cout << "Vehicle not available or ID not found.\n";
}


//funtion defintion of cancel booking
void cancelBooking(Booking bookings[], int &bookingCount, Vehicle vehicles[], int vehicleCount) 
{
	// colors
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,5);
    int vehicleId;
    cout << "Enter Vehicle ID to cancel booking: ";
    cin >> vehicleId;

    for (int i = 0; i < bookingCount; i++) 
	{
        if (bookings[i].vehicleId == vehicleId && bookings[i].status == "Booked") 
		{
            bookings[i].status = "Cancelled";
            for (int j = 0; j < vehicleCount; j++) 
			{
                if (vehicles[j].id == vehicleId) 
				{
                	
                    vehicles[j].available = true;
                    break;
                }
            }
            cout << "Booking cancelled successfully.\n";
            return;
        }
    }
    cout << "Booking not found.\n";
    cout<< "Remember: The booking can not be cancelled after payment." << endl;
}


//funtion definition of payment processing
void processPayment(Booking bookings[], int bookingCount, Vehicle vehicles[], int vehicleCount) 
{
	// colors
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,14);
    int vehicleId;
    cout << "Enter Vehicle ID for payment: ";
    cin >> vehicleId;

    for (int i = 0; i < bookingCount; i++) 
	{
        if (bookings[i].vehicleId == vehicleId && bookings[i].status == "Booked") 
		{
            for (int j = 0; j < vehicleCount; j++) 
			{
                if (vehicles[j].id == vehicleId) 
				{
                    cout << "Rental Rate: $" << vehicles[j].rentalRate << endl;
                    cout << "Payment successful.";
                    cout<<"Booking completed.";
                    bookings[i].status = "Paid";
                    return;
                }
            }
        }
    }
    cout << "Booking not found for payment.\n";
}