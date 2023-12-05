//============================================================================
// Name        : find2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <filesystem>
#include <iostream>
using namespace std;
namespace fs = std::filesystem;


struct StringFx {
  string toLower2(string myString) {
	  std::__cxx11::basic_string<char>::size_type nPosition;

	for (nPosition = 0; nPosition < myString.length(); nPosition++) {
	  myString[nPosition] = tolower(myString[nPosition] );
	}
	return myString;
  }

  void replaceAll(std::string& text, const std::string& searched, const std::string& replaceWith) {
    if(searched.empty())
	  return;
    size_t start_pos = 0;

    // find searched parameter in text.
    start_pos = text.find(searched, start_pos);

    // While function finds searched parameter
    while(start_pos != std::string::npos) {
      text.replace(start_pos, searched.length(), replaceWith);
      start_pos += replaceWith.length(); //updating position
      start_pos = text.find(searched, start_pos); //find next coincidence
    }
  }
  //void replaceAll() End

  void replaceSpecialChars(std::string& text) {
	this->replaceAll(text, "á", "a");
	this->replaceAll(text, "é", "e");
	this->replaceAll(text, "í", "i");
	this->replaceAll(text, "ó", "o");
	this->replaceAll(text, "ú", "u");
	this->replaceAll(text, "ñ", "n");

	this->replaceAll(text, "Á", "A");
	this->replaceAll(text, "É", "E");
	this->replaceAll(text, "Í", "I");
	this->replaceAll(text, "Ó", "O");
	this->replaceAll(text, "Ú", "U");

	return;
  }
  //void replaceSpecialChars() End
};


int main(int argc, char * argv[])
{
  //string path = fs::current_path();
  StringFx stringFx;
  string pathName;
  string pathName2;
  string currentPath = fs::current_path().string();
  string directoryEntryStr;
  unsigned short int currentPathLen = currentPath.length();

  string searched;
  size_t found;

  cout << "Arguments passed" << "\n";
  if (argc < 2) {
	cout << "Enter file name:";
    cin >> searched;
    searched = stringFx.toLower2(searched);
  } else {
	searched = argv[1];
	searched = stringFx.toLower2(searched);
  }
  stringFx.replaceSpecialChars(searched);

  /*
  for(int i = 0; i < argc; i++)
  {
    std::cout << argv[i] << "\n";
  }
  */

  cout << "Listing files with \"" << searched << "\" word inside the filename:" << "\n";
  for (auto const& dir_entry : fs::recursive_directory_iterator(fs::current_path())){

	pathName = dir_entry.path().string();
	pathName2 = pathName.substr(currentPathLen, std::string::npos);

	pathName2 = stringFx.toLower2(pathName2);

	found = pathName2.find(searched);

	if (found != std::string::npos) {
		directoryEntryStr = dir_entry.path().string();
		stringFx.replaceSpecialChars(directoryEntryStr);
		cout << directoryEntryStr << '\n';
	}
  }
  //cout << "Current path is " << currentPath << '\n'; // (1)
}


/*
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;
*/
//using namespace std;
//namespace fs = std::filesystem;

/*
int main(int argc, char * argv[]) {
  char* pathToWork;
  pathToWork = argv[0];

  for(int i = 0; i < argc; i++)
  {
      // argv[i] is the argument at index i
	  std::cout << argv[i] << "\n";
  }

  //cout << std::filesystem::current_path();
  // std::cout << "Current path is " << filesystem::current_path() << '\n';

  //cout << pathToWork;
  return 0;
}
*/
