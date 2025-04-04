/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:54:29 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/04 19:06:44 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

bool replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()) {
		std::cerr << "Error: Cannot open input file: " << filename << std::endl;
		return false;
	}

	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile.is_open()) {
		std::cerr << "Error: Cannot create output file: " << outputFilename << std::endl;
		inputFile.close();
		return false;
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		
		outputFile << line;
		if (!inputFile.eof()) {
			outputFile << std::endl;
		}
	}

	inputFile.close();
	outputFile.close();
	std::cout << "Replacement complete. Result written to " << outputFilename << std::endl;
	return true;
}

int main(int argc, char* argv[]) {
	if (argc != 4) {
		std::cerr << "Manual: " << argv[0] << " <filename> <string_to_replace> <replacement>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()) {
		std::cerr << "Error: The string to replace cannot be empty" << std::endl;
		return 1;
	}

	if (!replaceInFile(filename, s1, s2)) {
		return 1;
	}
	
	return 0;
}