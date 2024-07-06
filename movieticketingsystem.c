#include <stdio.h>
#include <string.h>

typedef struct {
    char title[50];
    char timings[3][10];
    int seatsAvailable[3];
    float price;
} Movie;

typedef struct {
    char name[20];
    Movie movies[50];
    int numMovies;
} Category;

void displayMovieCategories(Category categories[], int numCategories);
void displayMoviesByCategory(Category categories[], int numCategories, int categoryIndex);
void displayMovieDetails(Movie *movie);
void bookTickets(Movie *movie, int chosenTimingIndex, int numTickets);
void editBooking(Category categories[], int numCategories, Movie **chosenMovie, int *chosenTimingIndex, int *numTickets);

float calculateTotalPrice(Movie *movie, int numTickets);

int main() {
    Category categories[] = {
        {"Action", {
            {"Avengers: Endgame", {"10:00 AM", "2:00 PM", "6:00 PM"}, {100, 120, 80}, 120.00},
            {"Dune", {"10:30 AM", "3:30 PM", "8:30 PM"}, {120, 140, 90}, 180.00},
            {"Jumanji: Welcome to the Jungle", {"11:00 AM", "4:00 PM", "9:00 PM"}, {110, 130, 85}, 160.00},
            {"Mad Max: Fury Road", {"12:00 PM", "4:00 PM", "8:00 PM"}, {90, 110, 70}, 150.00},
            {"John Wick", {"11:30 AM", "3:30 PM", "7:30 PM"}, {95, 115, 75}, 140.00}
            }, 5},
        {"Comedy", {
            {"Knives Out", {"11:00 AM", "3:00 PM", "7:00 PM"}, {90, 110, 70}, 100.00},
            {"Crazy Rich Asians", {"10:00 AM", "2:00 PM", "7:00 PM"}, {100, 120, 75}, 140.00},
            {"Deadpool", {"9:30 AM", "1:30 PM", "6:30 PM"}, {95, 115, 70}, 120.00},
            {"The Hangover", {"12:30 PM", "4:30 PM", "8:30 PM"}, {85, 105, 65}, 130.00},
            {"Superbad", {"10:00 AM", "1:30 PM", "5:30 PM"}, {80, 100, 60}, 110.00}
            }, 5},
        {"Romantic", {
            {"The Notebook", {"9:30 AM", "1:30 PM", "5:30 PM"}, {80, 100, 60}, 150.00},
            {"P.S. I Love You", {"11:30 AM", "3:30 PM", "8:30 PM"}, {85, 105, 65}, 170.00},
            {"La La Land", {"10:00 AM", "2:00 PM", "7:00 PM"}, {90, 110, 80}, 150.00},
            {"Titanic", {"11:00 AM", "4:00 PM", "8:00 PM"}, {100, 120, 75}, 160.00},
            {"Pride and Prejudice", {"12:00 PM", "3:30 PM", "6:30 PM"}, {85, 105, 70}, 140.00}
            }, 5},
        {"Horror", {
            {"The Conjuring", {"10:30 AM", "2:30 PM", "6:30 PM"}, {95, 115, 75}, 110.00},
            {"The Exorcist", {"9:30 AM", "1:30 PM", "6:30 PM"}, {100, 120, 75}, 145.00},
            {"A Quiet Place", {"10:00 AM", "3:00 PM", "8:00 PM"}, {95, 115, 70}, 150.00},
            {"It", {"11:00 AM", "2:30 PM", "7:00 PM"}, {90, 110, 65}, 130.00},
            {"Hereditary", {"12:30 PM", "3:30 PM", "6:30 PM"}, {85, 105, 70}, 140.00}
            }, 5},
        {"Animation", {
            {"Toy Story 4", {"10:00 AM", "2:00 PM", "6:00 PM"}, {85, 105, 65}, 150.00},
            {"Frozen II", {"10:30 AM", "2:30 PM", "7:30 PM"}, {110, 130, 85}, 120.00},
            {"Moana", {"11:00 AM", "4:00 PM", "9:00 PM"}, {105, 125, 80}, 140.00},
            {"Zootopia", {"12:00 PM", "3:30 PM", "6:30 PM"}, {95, 115, 75}, 130.00},
            {"The Incredibles", {"10:30 AM", "1:30 PM", "5:30 PM"}, {90, 110, 70}, 140.00}
            }, 5},
        {"Sci-Fi", {
            {"Interstellar", {"9:00 AM", "1:00 PM", "5:00 PM"}, {90, 110, 70}, 160.00},
            {"The Matrix", {"10:00 AM", "2:00 PM", "7:00 PM"}, {100, 120, 75}, 140.00},
            {"Inception", {"10:30 AM", "3:30 PM", "8:30 PM"}, {95, 115, 80}, 170.00},
            {"Blade Runner 2049", {"11:00 AM", "4:00 PM", "8:00 PM"}, {85, 105, 65}, 150.00},
            {"Gravity", {"12:00 PM", "2:30 PM", "6:30 PM"}, {90, 110, 70}, 130.00}
            }, 5},
        {"Drama", {
            {"The Shawshank Redemption", {"10:00 AM", "2:00 PM", "6:00 PM"}, {85, 105, 65}, 120.00},
            {"Forrest Gump", {"9:30 AM", "1:30 PM", "7:30 PM"}, {100, 120, 80}, 130.00},
            {"The Godfather", {"11:00 AM", "3:00 PM", "8:00 PM"}, {110, 130, 90}, 150.00},
            {"Schindler's List", {"12:00 PM", "4:00 PM", "8:00 PM"}, {95, 115, 70}, 140.00},
            {"Fight Club", {"10:30 AM", "2:30 PM", "7:00 PM"}, {90, 110, 75}, 130.00}
            }, 5},
        {"Fantasy", {
            {"Harry Potter and the Sorcerer's Stone", {"10:00 AM", "2:00 PM", "7:00 PM"}, {95, 115, 70}, 140.00},
            {"The Lord of the Rings: The Fellowship of the Ring", {"11:00 AM", "3:00 PM", "8:00 PM"}, {100, 120, 80}, 160.00},
            {"Pan's Labyrinth", {"9:30 AM", "1:30 PM", "6:30 PM"}, {85, 105, 75}, 150.00},
            {"The Chronicles of Narnia", {"10:30 AM", "2:30 PM", "6:30 PM"}, {90, 110, 65}, 130.00},
            {"Stardust", {"11:00 AM", "3:30 PM", "7:30 PM"}, {95, 115, 70}, 120.00}
            }, 5},
        {"Thriller", {
            {"Se7en", {"10:30 AM", "2:30 PM", "7:30 PM"}, {90, 110, 70}, 130.00},
            {"The Silence of the Lambs", {"11:00 AM", "3:00 PM", "8:00 PM"}, {95, 115, 75}, 140.00},
            {"Gone Girl", {"9:30 AM", "1:30 PM", "6:30 PM"}, {100, 120, 80}, 150.00},
            {"Black Swan", {"10:00 AM", "1:30 PM", "6:00 PM"}, {85, 105, 70}, 120.00},
            {"Prisoners", {"11:30 AM", "3:30 PM", "8:00 PM"}, {95, 115, 75}, 140.00}
            }, 5},
    };
    int numCategories = sizeof(categories) / sizeof(categories[0]);

    while (1) {
        int chosenCategoryIndex;
        do {
            displayMovieCategories(categories, numCategories);
            printf("\nEnter the category number you want to see movies for (0 to exit): ");
            scanf("%d", &chosenCategoryIndex);
            if (chosenCategoryIndex == 0)
                return 0; // Exit program
            chosenCategoryIndex--;

        } while (chosenCategoryIndex < 0 || chosenCategoryIndex >= numCategories);

        int chosenMovieIndex;
        do {
            displayMoviesByCategory(categories, numCategories, chosenCategoryIndex);
            printf("\nEnter the movie number you want to book tickets for (0 to return): ");
            scanf("%d", &chosenMovieIndex);
            if (chosenMovieIndex == 0)
                break; // Return to category selection
            chosenMovieIndex--;

        } while (chosenMovieIndex < 0 || chosenMovieIndex >= categories[chosenCategoryIndex].numMovies);

        if (chosenMovieIndex < 0) continue;

        Movie *chosenMovie = &categories[chosenCategoryIndex].movies[chosenMovieIndex];

        int chosenTimingIndex, numTickets;
        do {
            displayMovieDetails(chosenMovie);
            printf("\nEnter the timing number you want to book tickets for (0 to return): ");
            scanf("%d", &chosenTimingIndex);
            if (chosenTimingIndex == 0)
                break; // Return to movie selection
            chosenTimingIndex--;

        } while (chosenTimingIndex < 0 || chosenTimingIndex >= 3);

        if (chosenTimingIndex < 0) continue;

        while (1) {
            printf("Enter the number of tickets you want to buy: ");
            scanf("%d", &numTickets);
            if (numTickets <= 0) {
                printf("Invalid number of tickets. Please enter a positive number.\n");
                continue;
            }

            if (numTickets > chosenMovie->seatsAvailable[chosenTimingIndex]) {
                printf("\nSorry, not enough seats available for the selected timing. Available seats: %d\n", chosenMovie->seatsAvailable[chosenTimingIndex]);
            } else {
                break; // Valid number of tickets
            }
        }

        // Book tickets or edit booking
        char choice;
        do {
            printf("\nDo you want to edit your booking? (Y/N): ");
            scanf(" %c", &choice);
        } while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

        if (choice == 'Y' || choice == 'y') {
            editBooking(categories, numCategories, &chosenMovie, &chosenTimingIndex, &numTickets);
        } else {
            bookTickets(chosenMovie, chosenTimingIndex, numTickets);
        }
    }

    return 0;
}

void displayMovieCategories(Category categories[], int numCategories) {
    printf("Available Movie Categories:\n");
    for (int i = 0; i < numCategories; i++) {
        printf("%d. %s\n", i + 1, categories[i].name);
    }
}

void displayMoviesByCategory(Category categories[], int numCategories, int categoryIndex) {
    printf("\nMovies in %s Category:\n", categories[categoryIndex].name);
    for (int i = 0; i < categories[categoryIndex].numMovies; i++) {
        printf("%d. %s\n", i + 1, categories[categoryIndex].movies[i].title);
    }
}

void displayMovieDetails(Movie *movie) {
    printf("    Available Timings:\n");
    for (int j = 0; j < 3; j++) {
        printf("    %d. %s - Seats Available: %d - Price: EGP %.2f\n", j + 1, movie->timings[j], movie->seatsAvailable[j], movie->price);
    }
}

void bookTickets(Movie *movie, int chosenTimingIndex, int numTickets) {
    float totalPrice = calculateTotalPrice(movie, numTickets);
    printf("\nTickets booked successfully!\n");
    printf("Movie: %s\n", movie->title);
    printf("Timing: %s\n", movie->timings[chosenTimingIndex]);
    printf("Number of Tickets: %d\n", numTickets);
    printf("Total Price: EGP %.2f\n", totalPrice);
    // Update seats availability
    movie->seatsAvailable[chosenTimingIndex] -= numTickets;
}

void editBooking(Category categories[], int numCategories, Movie **chosenMovie, int *chosenTimingIndex, int *numTickets) {
    char editChoice;
    do {
        printf("\nEdit Options:\n");
        printf("1. Change category or movie\n");
        printf("2. Change timing\n");
        printf("3. Change number of tickets\n");
        printf("4. Return to main menu\n");
        printf("Enter your choice: ");
        scanf(" %c", &editChoice);

    } while (editChoice < '1' || editChoice > '4');

    switch (editChoice) {
        case '1': {
            int chosenCategoryIndex;
            do {
                displayMovieCategories(categories, numCategories);
                printf("\nEnter the category number you want to see movies for (0 to return): ");
                scanf("%d", &chosenCategoryIndex);
                if (chosenCategoryIndex == 0)
                    return; // Return to main menu
                chosenCategoryIndex--;

            } while (chosenCategoryIndex < 0 || chosenCategoryIndex >= numCategories);

            int chosenMovieIndex;
            do {
                displayMoviesByCategory(categories, numCategories, chosenCategoryIndex);
                printf("\nEnter the movie number you want to book tickets for (0 to return): ");
                scanf("%d", &chosenMovieIndex);
                if (chosenMovieIndex == 0)
                    return; // Return to main menu
                chosenMovieIndex--;

            } while (chosenMovieIndex < 0 || chosenMovieIndex >= categories[chosenCategoryIndex].numMovies);

            *chosenMovie = &categories[chosenCategoryIndex].movies[chosenMovieIndex];
            break;
        }
        case '2':
            do {
                displayMovieDetails(*chosenMovie);
                printf("\nEnter the new timing number (0 to return): ");
                scanf("%d", chosenTimingIndex);
                if (*chosenTimingIndex == 0)
                    return; // Return to main menu
                (*chosenTimingIndex)--;

            } while (*chosenTimingIndex < 0 || *chosenTimingIndex >= 3);
            break;
        case '3':
            while (1) {
                printf("\nEnter the new number of tickets: ");
                scanf("%d", numTickets);
                if (*numTickets <= 0) {
                    printf("Invalid number of tickets. Please enter a positive number.\n");
                    continue;
                }

                if (*numTickets > (*chosenMovie)->seatsAvailable[*chosenTimingIndex]) {
                    printf("\nSorry, not enough seats available for the selected timing. Available seats: %d\n", (*chosenMovie)->seatsAvailable[*chosenTimingIndex]);
                } else {
                    break; // Valid number of tickets
                }
            }
            break;
        case '4':
            return; // Return to main menu
        default:
            printf("\nInvalid choice. Continuing with current booking.\n");
            break;
    }

    // Check if enough seats available for the new booking details
    if (*numTickets > (*chosenMovie)->seatsAvailable[*chosenTimingIndex]) {
        printf("\nSorry, not enough seats available for the selected timing.\n");
        return; // Return to edit booking menu
    }

    bookTickets(*chosenMovie, *chosenTimingIndex, *numTickets);
}

float calculateTotalPrice(Movie *movie, int numTickets) {
    return movie->price * numTickets;
}
