struct StringFx {
  string toLower2(string myString) {
	  std::__cxx11::basic_string<char>::size_type nPosition;

	for (nPosition = 0; nPosition < myString.length(); nPosition++) {
	  myString[nPosition] = tolower(myString[nPosition] );
	}
	return myString;
  }
};
