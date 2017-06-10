# PA5

This program uses STL lists and hash tables to read in ID numbers from a CSV, storing ones them and their corresponding values (in this case, grades) in a vector of lists. This is essentially a hash table as the values are stored according to a hash function. Then a complete roster of IDs are read in from another CSV and checked to see if they are present in the hash table. If they are, their corresponding value is added to the complete roster.

As it is, this program inputs students based on their UIN and their grade. It reads the complete roster and fills in grades for the students that finished a specific assignment.
