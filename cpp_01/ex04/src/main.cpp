/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:54:29 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/03/27 01:01:32 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    // Open input file
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file: " << filename << std::endl;
        return;
    }

    // Create output file
    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create output file: " << outputFilename << std::endl;
        inputFile.close();
        return;
    }

    // Process the file line by line
    std::string line;
    while (std::getline(inputFile, line)) {
        std::string newLine;
        size_t pos = 0;
        size_t found;

        // Process each occurrence of s1 in the current line
        while ((found = line.find(s1, pos)) != std::string::npos) {
            // Add the part before the match
            newLine += line.substr(pos, found - pos);
            // Add the replacement
            newLine += s2;
            // Move past the matched string
            pos = found + s1.length();
        }
        // Add the remaining part of the line
        newLine += line.substr(pos);
        
        // Write the modified line to the output file
        outputFile << newLine;
        
        // Add newline character if this isn't the end of the file
        if (!inputFile.eof()) {
            outputFile << std::endl;
        }
    }

    // Close files
    inputFile.close();
    outputFile.close();

    std::cout << "Replacement complete. Output written to " << outputFilename << std::endl;
}

int main(int argc, char* argv[]) {
    // Check argument count
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <string_to_replace> <replacement>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    // Check if s1 is empty
    if (s1.empty()) {
        std::cerr << "Error: String to replace cannot be empty" << std::endl;
        return 1;
    }

    replaceInFile(filename, s1, s2);

    return 0;
}