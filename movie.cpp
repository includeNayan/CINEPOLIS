
//Nayan Jyoti Nath 2212068
//Movie Ticket Booking System (OOPS PROJECT)


#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Ticket {
public:
    int price;

    Ticket(int pr) : price(pr) {}

    int getPrice() {
        return price;
    }
};


class Movie_Ticket : public Ticket {
public:
    int movieNo;
    string name;
    string genre;
    string timing;
    string releaseDate;
    double rating;
    int availableRegularSeats;
    int availableVIPSeats;
    int regularPrice;
    int vipPrice;

public:
    Movie_Ticket(int no, string n, string g, string t, string d, double r, int avReg, int avVIP, int regPr, int vipPr)
        : Ticket(regPr), movieNo(no), name(n), genre(g), timing(t), releaseDate(d), rating(r), availableRegularSeats(avReg), availableVIPSeats(avVIP), regularPrice(regPr), vipPrice(vipPr) {}

    int getMovieNo() const {
        return movieNo;
    }

    int getAvailableRegularSeats() const {
        return availableRegularSeats;
    }

    int getAvailableVIPSeats() const {
        return availableVIPSeats;
    }

    void display() const {
        cout << "Movie No: " << movieNo << endl;
        cout << "Name: " << name << endl;
        cout << "Genre: " << genre << endl;
        cout << "Timing: " << timing << endl;
        cout << "Release Date: " << releaseDate << endl;
        cout << "Rating: " << rating << endl;
        cout << "Available Regular Seats: " << availableRegularSeats << endl;
        cout << "Available VIP Seats: " << availableVIPSeats << endl;
        cout << "Regular Price: " << regularPrice << endl;
        cout << "VIP Price: " << vipPrice << endl;
        cout << endl;
    }
};


class Theater {
private:
    vector<Movie_Ticket> movies;

public:
    void addMovie(const Movie_Ticket &movie) {
        movies.push_back(movie);
    }

    void displayAllMovies() const {
        cout << "All Movies:" << endl;
        for (auto it : movies) {
            it.display();
        }
    }

    bool bookTicket(int movieNo, int numRegularSeats, int numVIPSeats, int totalAmount) {
        for (auto &movie : movies) {
            if (movie.getMovieNo() == movieNo) {
                int totalPrice = (movie.regularPrice * numRegularSeats) + (movie.vipPrice * numVIPSeats);

                if (totalAmount >= totalPrice) {
                    if (movie.getAvailableRegularSeats() >= numRegularSeats && movie.getAvailableVIPSeats() >= numVIPSeats) {
                        cout << "Ticket(s) booked successfully for " << movie.name << endl;
                        cout << "Total Price: Rs " << totalPrice << endl;

                        int remainingBalance = totalAmount - totalPrice;
                        cout << "Remaining Balance: Rs " << remainingBalance << endl;

                        movie.availableRegularSeats -= numRegularSeats;
                        movie.availableVIPSeats -= numVIPSeats;
                        return true;
                    }
                    else {
                        cout << "Sorry, not enough available seats for the selected type." << endl;
                        return false;
                    }
                }
                 else {
                    cout << "Insufficient funds! Total price is Rs " << totalPrice << endl;
                    return false;
                }
            }
        }

        cout << "Movie not found" << endl;
        return false;
    }
};



int main() {
    Theater theater;

    theater.addMovie(Movie_Ticket(1, "Interstellar", "Sci-Fi", "12:00 PM", "2024-04-02", 9.0, 100, 50, 10, 20));
    theater.addMovie(Movie_Ticket(2, "The Dark Knight", "Action", "3:00 PM", "2024-04-04", 8.5, 120, 60, 12, 25));
    theater.addMovie(Movie_Ticket(3, "Inception", "Sci-Fi", "6:00 PM", "2024-04-06", 8.8, 80, 40, 15, 30));

    int choice;

    do {
        cout << "\n\n\n";
        cout << "*************************************************************************************\n";
        cout << "\t\t\tWelcome to Cinepolis!\n";
        cout << "\t\t\t     MAIN MENU\n";
        cout << "*************************************************************************************\n";

        cout << "\t1. Display all movies\n";
        cout << "\t2. Book ticket\n";
        cout << "\t3. Exit\n";
        cout << "\nEnter your choice: ";

        cin >> choice;

        switch (choice) {

            case 1:
                cout << "\n\t\tDISPLAYING ALL MOVIES\n";
                theater.displayAllMovies();
                break;

            case 2: {
                int movieNo, numRegularSeats, numVIPSeats, totalAmount;
                cout << "\nEnter Movie Number: ";
                cin >> movieNo;

                if (movieNo > 3 || movieNo < 1) {
                    cout << "Invalid movie number" << endl;
                    break;
                }
                cout << "Enter Number of Regular Seats: ";
                cin >> numRegularSeats;
                cout << "Enter Number of VIP Seats: ";

                cin >> numVIPSeats;
                cout << "Enter Total Amount: Rs ";

                cin >> totalAmount;
                theater.bookTicket(movieNo, numRegularSeats, numVIPSeats, totalAmount);
                break;
            }

            case 3:
                cout << "Exiting program" << endl;
                break;

            default:
                cout << "Invalid choice. Please enter again." << endl;
                break;
        }
        
    } while (choice != 3);

    return 0;
}
