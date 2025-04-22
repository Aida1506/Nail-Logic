# Nail-Logic

"Nail Logic" is a comprehensive salon management system designed for nail salons. The application allows users to manage appointments, view available offers, and perform various other operations related to both client and manager roles. Clients can book appointments, view current offers, and manage their scheduled bookings, while managers can add or delete offers and view all appointments. The goal of the application is to streamline the process of managing salon appointments and services while providing a user-friendly interface.

Key Features:
Client Menu:
  -Appointment Management: Clients can schedule and cancel appointments.
  -View Offers: Clients can see available offers and promotions.
  -View Appointments: Clients can check their scheduled appointments.

Manager Menu:
  -Manage Offers: Managers can add, delete, and view available offers.
  -Manage Appointments: Managers can view all appointments and cancel if necessary.

Persistent Data Storage:
  -File Handling: The application reads and writes data to external text files (e.g., oferte.txt), ensuring persistent storage of offers and appointments.

Interactive User Interface:
  -Menu-Driven Interface: The application provides a clear and easy-to-navigate menu system for both clients and managers to interact with the system.

Technologies Used:
  C++ (Programming Language): The core logic of the application is implemented using C++. It leverages object-oriented principles to organize the data and functionality into classes such as Salon, Oferta, and Programare.

File Handling: The application makes use of standard file streams (ifstream and ofstream) to read and write data to text files. This allows persistent storage of offers and appointments in plain text format. The file format used for storing offers (oferte.txt) includes fields such as offer name and price, which are separated by commas.

Object-Oriented Programming (OOP): The application utilizes OOP principles to create a scalable and maintainable structure, using classes, inheritance, and encapsulation. For instance, the Oferta class handles offer-related details, while the Salon class manages the overall salon operations.

Standard C++ Library: The application uses standard C++ libraries such as <iostream>, <fstream>, <sstream>, and <vector>. These libraries provide essential functionality like input/output operations, file handling, string manipulation, and dynamic array management.

Text-Based User Interface (TUI): The application provides a simple, text-based user interface that works in the terminal. Users can navigate through different options using a menu-driven approach, with clear and colorful outputs to enhance user interaction.
