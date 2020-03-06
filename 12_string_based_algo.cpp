//============================================================================
// Name        : string_based_algorithms.cpp
// Author      : Rajasekhar Mugada
// Version     :
// Copyright   : Your copyright notice
// Description : Commonly used algorithms based on Array ADT
//		1. Count number of words in a given string
//		2. Check for palindrome : Ex NITIN
//		3. Compare given strings
//		4. Find duplicates in a given word
//		5. Anagram
//
//============================================================================

#include <iostream>
using namespace std;


class string_util
{
public:
	int count_num_words(char * str);
	bool check_palindrome(char * str);
	char compare_is_first_string_small(char * str1, char * str2);
	int count_duplicate_characters(char * str);
	char check_anagram(char * str1, char * str2);
	char check_anagram_slow(char * str1, char * str2);

private:
	void create_hashmap(char * str, int * hash);

};



/*
 * Count number of words in a given string
 * This is a basic version, where new line and validity of the string is not taken care
 */
int string_util :: count_num_words(char * str)
{
	int count = 0;

	if(str == NULL)	//invalid input
		return 0;

	int i = 0;

	while(str[i] != '\0' )
	{
		if(i > 0 && str[i] == ' ' && str[i-1] != ' ')
			count ++;
		i++;
	}

	if(str[i-1] != ' ')	//last word
		count++;

	return count;
}

/*
 * Check for palindrome: reverse sequence is same as normal sequence
 * Ex: palindrome: 12321, 1221, nitin
 * Ex: Not palindrome: 1231, nidhi
 */
bool string_util :: check_palindrome(char * str)
{
	int start = 0, end = 0;
	//move right cursor to the end
	while(str[end] != '\0')
	{
		end++;
	}
	end--;

	//check for palindrome condition
	while(start < end)
	{
		if(str[start] != str[end])
		{
			return false;
		}
		start ++;
		end --;
	}
	return true;
}

/*
 * Compare given strings
 * -check for bigger char value for a given index
 */
char string_util :: compare_is_first_string_small(char * str1, char * str2)
{
	int i = 0, j = 0;

	while(str1[i] != '\0' && str2[j] != '\0')
	{
		if(str1[i] < str2[j])
			return true;

		i++;
		j++;
	}
	if(str1[--i] == '\0')
		return true;

	return false;
}

/*
 * Create hash map for the given string
 * -not case sensitive
 *
 */
void string_util :: create_hashmap(char * str, int * hash)
{
	int i = 0;

	//initialize hash table
	for(i = 0; i<26; i++)
	{
		hash[i] = 0;
	}

	//Set number of occurrences for each character
	int ch = 0;	//ascii code of the character
	i = 0;
	while(str[i] != '\0')
	{
		//valid character
		//upper case to lower case
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			ch = str[i] - 'A';
			hash[ch]++;
		}
		else if(str[i] >= 'a' && str[i] <= 'z')
		{
			ch = str[i] - 'a';
			hash[ch]++;
		}
		i++;
	}
}

/*
 * Finding duplicates in a given string : count number of duplicate characters
 *	-Using hash table approach.
 *	-Bit operations can also be used to detect duplicates but not count
 */
int string_util :: count_duplicate_characters(char * str)
{
	int count = 0;
	int i = 0;

	//initialize hash table
	int hash[26];
	create_hashmap(str, hash);

	//count number of duplicate characters
	for(i = 0; i< 26; i++)
	{
		if(hash[i] > 1)
			count ++;
	}

	return count;
}

/*
 * Check for anagram
 * Anagram : Anagrams are words or phrases created by rearranging
 * 			the letters of another word or phrase
 * Ex: 	Dormitory = Dirty room
 * 		School master = The classroom
 * 		Conversation = Voices rant on
 * 		Listen = Silent
 * Implementation:
 * 		1. Create hash map for first string
 * 		2. For second string, decrement the first string hash map values, if a -1 is found not an anagram
 */
char string_util :: check_anagram(char * str1, char * str2)
{
	//Hash maps for both input strings should be same
	int h[26];
	create_hashmap(str1, h);

	int ch = 0;	//ascii code of the character
	int i = 0;
	while(str2[i] != '\0')
	{
		//valid character
		//upper case to lower case
		if(str2[i] >= 'A' && str2[i] <= 'Z')
		{
			ch = str2[i] - 'A';
			h[ch]--;
		}
		else if(str2[i] >= 'a' && str2[i] <= 'z')
		{
			ch = str2[i] - 'a';
			h[ch]--;
		}
		i++;

		if(h[ch] < 0)
			return false;
	}

	for(i = 0; i< 26; i++)
	{
		if(h[i] > 0)
			return false;
	}

	return true;
}
/*
 * Check for anagram
 * Anagram : Anagrams are words or phrases created by rearranging
 * 			the letters of another word or phrase
 * Ex: 	Dormitory = Dirty room
 * 		School master = The classroom
 * 		Conversation = Voices rant on
 * 		Listen = Silent
 * Implementation: Hash maps for both input strings should be same
 */
char string_util :: check_anagram_slow(char * str1, char * str2)
{
	//Hash maps for both input strings should be same
	int h1[26], h2[26];
	create_hashmap(str1, h1);
	create_hashmap(str2, h2);

	for(int i = 0; i< 26; i++)
	{
		if(h1[i] != h2[i])
			return false;
	}

	return true;
}

int main()
{
	string_util util;

	//count no. of words
	char str[] = "Hi, how are you";
	int count = util.count_num_words(str);
	cout << "Input string : " << str ;
	cout << " : Number of words : " << count;

	//check for palindrome
	char str2[] = "nitin";
	char str3[] = "nidhi";
	cout <<endl<< "Input string : " << str2;
	if(util.check_palindrome(str2) == true)
		cout << " : palindrome sequence";
	else
		cout << " : NOT a palindrome sequence.";

	cout <<endl<< "Input string : " << str3;
	if(util.check_palindrome(str3) == true)
		cout << " : palindrome sequence.";
	else
		cout << " : NOT a palindrome sequence.";


	//compare given strings
	cout <<endl<< "Input strings : " << str2 << ", " << str3;
	if(util.compare_is_first_string_small(str2, str3) == true)
		cout << " : First string is small.";
	else
		cout << " : First string is NOT small.";


	//Count duplicate characters in the given string
	char str4[] = "how are you";
	cout << endl << "Input string : " << str4 ;
	cout << " : No. of duplicate characters : " << util.count_duplicate_characters(str4);

	//Check anagram
	char str5[] = "School master";
	char str6[] = "The classroom";
	cout <<endl<< "Input strings : " << str5 << ", " << str6;
	if(util.check_anagram(str5, str6) == true)
		cout << " : Anagram";
	else
		cout << " : NOT anagram";

	return 0;
}

