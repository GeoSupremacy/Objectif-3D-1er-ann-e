#include <iostream>
#include <algorithm>
#include <cctype>

#pragma region Correction
std::string reverse_words(std::string s)
{
	auto is_space = [](unsigned char c) { return std::isspace(c); };

	auto word_start = s.begin();
	while ((word_start = std::find_if_not(word_start, s.end(), is_space)) != s.end()) {
		auto word_end = std::find_if(word_start, s.end(), is_space);
		std::reverse(word_start, word_end);
		word_start = word_end;
	}

	return s;
}
#pragma endregion Correction
std::string ReverseWords(std::string _string) {

	char _character = ' ';
	std::string  _newString = "";
	std::string  _eachWord = "";

	for (size_t i = 0; i < _string.length(); i++)
	{
		_character = _string[i];
		
		if (' ' == _string[i])
		{
			int n = _eachWord.length();

			for (size_t i = 0; i < n / 2; i++)
				std::swap(_eachWord[i], _eachWord[n - i - 1]);

			_newString += _eachWord + " ";
			_eachWord = "";
			
		}
		else if (_string[_string.length() - 1] == _string[i])
		{
			_eachWord += _character;
			int n = _eachWord.length();

			for (size_t i = 0; i < n / 2; i++)
				std::swap(_eachWord[i], _eachWord[n - i - 1]);

			_newString += _eachWord;
			_eachWord = "";
		}
		else
			_eachWord += _character;
		
	}
	return _newString;
}

int main()
{
  std::cout<<ReverseWords("The cat in the hat")<<std::endl;
  std::cout<< reverse_words("The cat in the hat");

   //"ehT tac ni eht tah"
}

#pragma region Comment
/*
* Reverse que les mots entre espace
*/
#pragma endregion Comment