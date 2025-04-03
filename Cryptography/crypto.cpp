#include <sodium.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>

int main() {
    // Initialize Libsodium
    if (sodium_init() < 0) {
        std::cout << "Libsodium initialization failed!" << std::endl;
        return 1;
    }

    // Generate Key Pair (for encryption)
    unsigned char public_key[crypto_box_PUBLICKEYBYTES];
    unsigned char secret_key[crypto_box_SECRETKEYBYTES];
    crypto_box_keypair(public_key, secret_key);

    std::cout << "Keys generated successfully!\n";

    // Generate a random nonce (MUST be unique for every encryption)
    unsigned char nonce[crypto_box_NONCEBYTES];
    randombytes_buf(nonce, sizeof nonce);

    // Get user input message
    std::string message;
    std::cout << "Enter the message to encrypt: ";
    std::getline(std::cin, message);

    // Convert message to unsigned char vector
    size_t message_len = message.size();
    std::vector<unsigned char> plaintext(message_len + 1); // +1 for null-terminator
    std::memcpy(plaintext.data(), message.c_str(), message_len + 1);

    // Prepare buffer for encrypted message
    std::vector<unsigned char> ciphertext(message_len + crypto_box_MACBYTES);

    // Encrypt the message (using self-public and self-secret keys for testing)
    if (crypto_box_easy(ciphertext.data(), plaintext.data(), message_len, nonce, public_key, secret_key) != 0) {
        std::cout << "Encryption failed!\n";
        return 1;
    }

    // Print Encrypted Message in Hex
    std::cout << "Encrypted Message: ";
    for (size_t i = 0; i < message_len + crypto_box_MACBYTES; i++) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)ciphertext[i];
    }
    std::cout << std::endl;

    // Decrypt the message
    std::vector<unsigned char> decrypted(message_len + 1); // +1 for null-terminator
    if (crypto_box_open_easy(decrypted.data(), ciphertext.data(), message_len + crypto_box_MACBYTES, nonce, public_key, secret_key) != 0) {
        std::cout << "Decryption failed!\n";
        return 1;
    }

    // Ensure string is null-terminated
    decrypted[message_len] = '\0';

    // Print Decrypted Message
    std::cout << "Decrypted Message: " << decrypted.data() << std::endl;

    return 0;
}