# Assignment-7-CS2-60
I will have at least 2 types of hash tables that are function. and give general information regarding hash tables

Define the Hash Table Structure:

Create a structure to represent each hash table entry that includes the student's name (key) and their assigned integer (value).
Define a hash table array with 10 slots, each potentially holding a list of entries (if using separate chaining for collision resolution).
Hash Function:

Implement a hash function that takes a string (student's name) as input.
Convert the string into an integer by summing the ASCII values of the characters or any other method you prefer.
Apply modulo (%) 10 to the resulting integer to ensure the hash value falls within the 0-9 range (for the 10 slots).
Insert Function:

For inserting a new student entry, first, use the hash function to determine the slot index.
If using separate chaining, append the new entry to the list in the corresponding slot. If the slot is empty, initialize a new list.
If using open addressing, find the next available slot according to your collision resolution strategy and insert the new entry there.
Search Function:

To find a student's assigned integer, hash the student's name to find the slot index.
Search through the slot's list (for separate chaining) or probe the slots (for open addressing) to find the entry with the matching name.
Return the student's assigned integer if found.
Delete Function (Optional for Basic Implementation):

Similar to the search function, locate the student's entry.
Remove the entry from the list in its slot (for separate chaining) or mark the slot as deleted/vacant (for open addressing).
Handle Collisions (If Using Open Addressing):

Implement your chosen method (linear probing, quadratic probing, or double hashing) to resolve collisions when inserting new entries.
Main Function:

Initialize the hash table.
Add entries for the 8 students using the insert function.
Demonstrate searching for a few student entries.
(Optional) Demonstrate deleting a student entry.
