#include <sodium.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Function to generate a random ASCII string of given length
std::string random_ascii_string(size_t length) {
    std::string output;
    for (size_t i = 0; i < length; ++i) {
        output += static_cast<char>(rand() % 95 + 32); // ASCII printable characters (32-126)
    }
    return output;
}

int main() {
    if (sodium_init() < 0) {
        std::cerr << "Init failed!\n";
        return 1;
    }

    // Generate key pair
    unsigned char pk[crypto_box_PUBLICKEYBYTES];
    unsigned char sk[crypto_box_SECRETKEYBYTES];
    crypto_box_keypair(pk, sk);

    // Get input
    std::string msg;
    std::cout << "Enter message: ";
    std::getline(std::cin, msg);

    // Use random ASCII string for nonce generation (just as an example)
    std::string nonce_str = random_ascii_string(crypto_box_NONCEBYTES); // Generate random ASCII
    unsigned char nonce[crypto_box_NONCEBYTES];
    std::memcpy(nonce, nonce_str.data(), crypto_box_NONCEBYTES); // Copy to nonce array

    std::string cipher;
    std::string decrypted;

    // Resize strings
    cipher.resize(msg.size() + crypto_box_MACBYTES);
    decrypted.resize(msg.size());

    // Encrypt
    if (crypto_box_easy((unsigned char*)&cipher[0], (const unsigned char*)msg.data(), msg.size(), nonce, pk, sk) == 0) {
        // Display encrypted message directly as ASCII characters
        std::cout << "Encrypted (ASCII): ";
        for (unsigned char c : cipher) {
            std::cout << c;
        }
        std::cout << "\n";
    }

    // Decrypt
    if (crypto_box_open_easy((unsigned char*)&decrypted[0], (const unsigned char*)&cipher[0], cipher.size(), nonce, pk, sk) == 0) {
        std::cout << "Decrypted: " << decrypted << "\n";
    }
    return 0;
}