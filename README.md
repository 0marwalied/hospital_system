# Hospital Management System

This is a simple **Hospital Management System** implemented in C++. It allows managing patients in a hospital by adding new patients, printing all patients, and getting the next patient for treatment based on their specialization and status (urgent or regular).

## Features
- **Add new patient**: Add a patient to a specific specialization with their name and status (urgent or regular).
- **Print all patients**: Display all patients in the hospital, grouped by specialization and status.
- **Get next patient**: Retrieve the next patient for treatment based on their status (urgent patients are prioritized).
- **Specialization-based management**: Supports up to 20 specializations, each with a maximum of 5 patients.

## How to Use
1. **Compile the code**: Use a C++ compiler (e.g., `g++`) to compile the program:
   ```bash
   g++ -o hospital.cpp
