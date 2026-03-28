#pragma once

#include <iostream>
#include <memory>
#include <cstdio>
#include <string_view>
#include <filesystem>
#include <cstdio>
#include <cstdarg>

// Example of how to use the RAII pattern to manage a file resource safely in C++20.
struct FileDeleter {
    void operator()(FILE* fp) const {
        if (fp) {
            std::cout << "[RAII] Closing file handle...";
            fclose(fp);
        }
    }
};

class SafeFile {
    private:
        std::unique_ptr<FILE, FileDeleter> file_handle; // Manages the FILE* resource with a custom deleter
        std::unique_ptr<char[]> buffer; // Buffer for formatted output, managed with a unique_ptr for automatic cleanup -> calls delete[] when going out of scope

    public: 
        explicit SafeFile(const std::filesystem::path& filepath) {
    
            FILE* fp = fopen(filepath.string().c_str(), "w");
            if (!fp) throw std::runtime_error("Failed to open file");

            file_handle.reset(fp);
            buffer = std::make_unique<char[]>(1024);
            std::cout << "[RAII] file opened and buffer allocated.\n";
        }

        void write(std::string_view text){
            if (file_handle) {
                fputs(text.data(), file_handle.get());
            };
        }

        void write_formatted(const char* format, ...){
            if (!file_handle || !buffer) return;

            va_list args;
            va_start(args, format);

            // Use the buffer as a workspace for the formatted string
            // vsnprintf ensures we don't overflow our 1024-byte limit
            int result = vsnprintf(buffer.get(), 1024, format, args);

            if (result > 0) {
                fputs(buffer.get(), file_handle.get());
            } else {
                std::cerr << "Formatting error occurred.\n";
            }   
            va_end(args);
        }
       
};