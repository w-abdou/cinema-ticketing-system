# Movie Ticketing System

## Overview

The Movie Ticketing System is a console-based application written in C that allows users to view and book tickets for movies across different categories. The application manages movie categories, displays available movies, provides details for each movie, and handles ticket booking, including editing bookings and calculating total prices.

## Features

- **Display Movie Categories**: Shows a list of movie categories.
- **Display Movies by Category**: Shows movies available under a selected category.
- **Display Movie Details**: Provides detailed information about a selected movie, including show timings and ticket prices.
- **Book Tickets**: Allows users to book tickets for a selected movie and timing.
- **Edit Bookings**: Users can edit their booking details such as movie, timing, and number of tickets.
- **Calculate Total Price**: Computes the total price for the booked tickets based on the movie's price and the number of tickets.

## Code Structure

The main components of the code are:

1. **Data Structures**:
    - `Movie`: Represents a movie with attributes such as title, show timings, available seats for each timing, and ticket price.
    - `Category`: Represents a movie category containing multiple movies and the number of movies in that category.

2. **Functions**:
    - `displayMovieCategories`: Displays all available movie categories.
    - `displayMoviesByCategory`: Displays movies under a specified category.
    - `displayMovieDetails`: Shows detailed information about a specific movie.
    - `bookTickets`: Books a specified number of tickets for a selected movie and timing.
    - `editBooking`: Allows users to edit their existing booking details.
    - `calculateTotalPrice`: Calculates the total price for the booked tickets.

## How to Use

1. **Compile the Program**: Use a C compiler to compile the source code.

2. **Run the Program**: Execute the compiled program.

3. **Main Menu**: The application starts with a main menu where users can select options to view categories, book tickets, or edit bookings.

## Example

Here is a brief walkthrough of using the application:

1. **View Categories**: Select the option to display movie categories.
2. **Select Category**: Choose a category to view the movies available under it.
3. **View Movies**: Select a movie to see its details, including available show timings and ticket prices.
4. **Book Tickets**: Choose a timing and the number of tickets to book.
5. **Edit Booking**: If needed, return to the main menu and select the option to edit your booking, allowing you to change the movie, timing, or number of tickets.
6. **Calculate Price**: The total price for the tickets is automatically calculated and displayed during the booking process.

## Notes

- Ensure to provide valid inputs as prompted by the application to avoid unexpected behavior.
- The program currently contains hardcoded movie categories and movies for demonstration purposes.

## Future Enhancements

- Implement persistent storage to save and retrieve bookings.
- Add user authentication to manage personal bookings.
- Develop a graphical user interface (GUI) for a more user-friendly experience.
- Expand the movie database with more categories and movies dynamically.
