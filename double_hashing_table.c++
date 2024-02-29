#include <vector>
#include <optional>
#include <string>
#include <iostream>


// Step 1: Define the Hash Table Entry
struct HashTableEntry {
    std::string key; // Key (student's name)
    int value;       // Value (unique ID or associated data)

    // Constructor for convenience
    HashTableEntry(const std::string& key, int value) : key(key), value(value) {}
};

// Define the Hash Table as a vector of optional HashTableEntry
const int HASH_TABLE_SIZE = 100; // Example size, adjust based on needs
std::vector<std::optional<HashTableEntry>> hashTable(HASH_TABLE_SIZE);

int h1(const std::string& key) {
    int hashValue = 0;
    for (char c : key) {
        hashValue += static_cast<int>(c);
    }
    return hashValue % HASH_TABLE_SIZE;
}

const int R = 97; // Example prime number smaller than HASH_TABLE_SIZE (which is 100)

int h2(const std::string& key) {
    int hashValue = 0;
    for (char c : key) {
        hashValue += static_cast<int>(c);
    }
    return R - (hashValue % R);
}

// Allows h1 and h2 to work together

int doubleHashing(const std::string& key, int attempt) {
    int hash1 = h1(key);
    int hash2 = h2(key);
    return (hash1 + attempt * hash2) % HASH_TABLE_SIZE;
}

bool insertEntry(const std::string& key, int value) {
    int index = h1(key);
    int attempt = 0;

    while (attempt < HASH_TABLE_SIZE) {
        int newIndex = doubleHashing(key, attempt);
        // Check if the slot is empty or contains a tombstone for deletion
        if (!hashTable[newIndex].has_value() || hashTable[newIndex]->key == key) {
            // Insert the new entry or update the existing one
            hashTable[newIndex] = HashTableEntry(key, value);
            return true; // Successfully inserted or updated
        }
        attempt++;
    }

    // If we've tried every slot and found no place to insert, the table is full
    std::cerr << "Hash table is full. Failed to insert key: " << key << std::endl;
    return false; // Indicate failure to insert
}

int main() {
    // Insert some test entries
    bool insertSuccess = insertEntry("Alice", 123);
    std::cout << "Insert Alice: " << (insertSuccess ? "Success" : "Failed") << std::endl;

    insertSuccess = insertEntry("Bob", 456);
    std::cout << "Insert Bob: " << (insertSuccess ? "Success" : "Failed") << std::endl;

    insertSuccess = insertEntry("Charlie", 789);
    std::cout << "Insert Charlie: " << (insertSuccess ? "Success" : "Failed") << std::endl;

    // Attempt to insert a duplicate key to test update functionality
    insertSuccess = insertEntry("Alice", 999);
    std::cout << "Re-insert Alice with new value: " << (insertSuccess ? "Success" : "Failed") << std::endl;

    // Optionally, print the hash table state to visually inspect the result
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        if (hashTable[i].has_value()) {
            std::cout << "Slot " << i << ": " << hashTable[i]->key << ", " << hashTable[i]->value << std::endl;
        }
    }

    return 0;
}
