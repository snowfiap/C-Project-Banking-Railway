#include <stdio.h>
#include <string.h>

#define MAX_SEATS 100

// Structure to store seat information
struct Seat {
    int seatNumber;
    char passengerName[50];
    int isBooked;
};

// Array to store seats
struct Seat seats[MAX_SEATS];

// Function to initialize seats
void initializeSeats() {
    for (int i = 0; i < MAX_SEATS; i++) {
        seats[i].seatNumber = i + 1;
        seats[i].isBooked = 0;
        strcpy(seats[i].passengerName, "");  // No passenger initially
    }
}

// Function to display available seats
void displayAvailableSeats() {
    printf("Available Seats:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (!seats[i].isBooked) {
            printf("Seat %d\n", seats[i].seatNumber);
        }
    }
}

// Function to book a seat
void bookSeat() {
    int seatNumber;
    char passengerName[50];
    printf("Enter seat number to book (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNumber);

    // Check if seat number is valid
    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }

    // Check if the seat is already booked
    if (seats[seatNumber - 1].isBooked) {
        printf("Seat %d is already booked.\n", seatNumber);
        return;
    }

    // Book the seat
    printf("Enter passenger name: ");
    scanf(" %[^\n]", passengerName);  // To read string with spaces
    seats[seatNumber - 1].isBooked = 1;
    strcpy(seats[seatNumber - 1].passengerName, passengerName);
    printf("Seat %d booked successfully for %s.\n", seatNumber, passengerName);
}

// Function to cancel a booking
void cancelBooking() {
    int seatNumber;
    printf("Enter seat number to cancel booking (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNumber);

    // Check if seat number is valid
    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }

    // Check if the seat is booked
    if (!seats[seatNumber - 1].isBooked) {
        printf("Seat %d is not currently booked.\n", seatNumber);
        return;
    }

    // Cancel the booking
    seats[seatNumber - 1].isBooked = 0;
    strcpy(seats[seatNumber - 1].passengerName, "");
    printf("Booking for seat %d has been canceled.\n", seatNumber);
}

// Function to display all booked seats
void displayBookedSeats() {
    printf("Booked Seats:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i].isBooked) {
            printf("Seat %d - %s\n", seats[i].seatNumber, seats[i].passengerName);
        }
    }
}

// Main function
int main() {
    int choice;
    initializeSeats();  // Initialize all seats as available

    do {
        printf("\n--- Railway Reservation System ---\n");
        printf("1. Display Available Seats\n");
        printf("2. Book a Seat\n");
        printf("3. Cancel Booking\n");
        printf("4. Display Booked Seats\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAvailableSeats();
                break;
            case 2:
                bookSeat();
                break;
            case 3:
                cancelBooking();
                break;
            case 4:
                displayBookedSeats();
                break;
            case 5:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}




