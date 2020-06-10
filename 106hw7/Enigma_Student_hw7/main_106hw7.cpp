#include <conio.h>
#include "Enigma.h"

int main()
{
	srand((unsigned int)time(0));

	Enigma_Files Rotor_start_file;
	Enigma_Files Rotor_arrow_file;
	Enigma_Files original_message_file;
	Enigma_Files encoded_message_file;

	std::cout << "s1234567's version" << std::endl;
	//std::cout << "s1234567's version" << std::endl; //<-- replace it by your student ID
	std::cout << "Read original message: \"original_data.txt\"" << std::endl;
	original_message_file.Read_file("original_data.txt");

	std::cout << "Read arrows position of [Rotor]: \"Rotor_arrow_web.txt\"" << std::endl;
	Rotor_arrow_file.Read_file("Rotor_arrow_web.txt");//(hw8, part2 only)

	std::cout << "Read start position of [Rotor]: \"Rotor_start_web.txt\"" << std::endl;
	Rotor_start_file.Read_file("Rotor_start_web.txt");//(hw8, part2 only)

	std::cout << "Read [Rotor III]: \"Rotor_III_web.txt\"" << std::endl;
	Rotor Rotor_III("Rotor_III_web.txt", Rotor_start_file[0], Rotor_arrow_file[0]);
	// Rotor_start_file[0] means the first character in the file.

	std::cout << "Read [Reflector]: \"Reflector_web.txt\"" << std::endl;
	Reflector reflector("Reflector_web.txt");

	Rotor_III.Link(reflector);

	std::cout << "*Original message: " << std::endl << original_message_file.Data() << std::endl;

	//use a chain reaction to encode all characters in the original_message_file[]
	for (size_t i = 0; i < original_message_file.Length(); i++)
		encoded_message_file.Push(Rotor_III.Input_signal(original_message_file[i]));

	std::cout << "(Output encoded data to \"encoded_data.txt\")" << std::endl;
	encoded_message_file.Write_file("encoded_data.txt");

	std::cout << "*Eecoded message: " << std::endl << encoded_message_file.Data() << std::endl;

	std::cout << "*Decode it back..." << std::endl;
	Rotor_III.Reset(); //(hw7)
	//reset the enigma to decode encoded information back to original data
	//(make a chain reaction to reset all encoder)

	for (size_t i = 0; i < encoded_message_file.Length(); i++)
		std::cout << Rotor_III.Input_signal(encoded_message_file[i]);
	std::cout << std::endl;

	std::cout << "Press any key to exit...";
	std::getchar();
	return EXIT_SUCCESS;
}
