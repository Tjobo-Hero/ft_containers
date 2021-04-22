/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RandomAccesIterator_test.cpp                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: timvancitters <timvancitters@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 11:03:00 by timvancitte   #+#    #+#                 */
/*   Updated: 2021/04/22 12:43:48 by timvancitte   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "catch.hpp"
#include <vector>
#include <string>

#include "../INCLUDES/ft_RandomAccessIterator.hpp"
#include "../INCLUDES/ft_Vector.hpp"

TEST_CASE( "RandomAccesIterator-tests", "[randomaccesiterator]") 
{
	ft::vector<std::string> own_vector_string;
	std::vector<std::string> real_vector_string;

	own_vector_string.push_back("my");
	real_vector_string.push_back("my");
	own_vector_string.push_back("name");
	real_vector_string.push_back("name");
	own_vector_string.push_back("is");
	real_vector_string.push_back("is");
	own_vector_string.push_back("Tim");
	real_vector_string.push_back("Tim");

	ft::vector<std::string>::iterator own_it = own_vector_string.begin();
	ft::vector<std::string>::iterator own_ite = own_vector_string.end();

	std::vector<std::string>::iterator real_it = real_vector_string.begin();
	std::vector<std::string>::iterator real_ite = real_vector_string.end();

	ft::vector<int> 	own_vector_int;
	std::vector<int>	real_vector_int;

	for (int i = 0; i < 10; ++i) own_vector_int.push_back(i);
	for (int i = 0; i < 10; ++i) real_vector_int.push_back(i);

	ft::vector<int>::iterator own_it2 = own_vector_int.begin();
	ft::vector<int>::iterator own_ite2 = own_vector_int.end();

	std::vector<int>::iterator real_it2 = real_vector_int.begin();
	std::vector<int>::iterator real_ite2 = real_vector_int.end();

	SECTION("* overload")
	{
		own_it++;
		own_it2++;

		real_it++;
		real_it2++;
		
		own_ite--;
		own_ite2--;
		real_ite--;
		real_ite2--;
		
		REQUIRE(*own_ite == *real_ite);
		REQUIRE(*own_ite2 == *real_ite2);
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
	}

	SECTION("-> overload")
	{
		++own_it;
		++real_it;
		
		--own_ite;
		--real_ite;

		REQUIRE(*own_ite->data() == *real_ite->data());
		REQUIRE(*own_it->data() == *real_it->data());
	}
	
	SECTION("[] overload")
	{
		REQUIRE(own_it[2] == real_it[2]);
		REQUIRE(own_it2[2] == real_it2[2]);
	}
	
	SECTION("Increment - prefix and postfix")
	{
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		own_it++;
		real_it++;
		own_it2++;
		real_it2++;
		REQUIRE(*own_it == *real_it);
		REQUIRE(*own_it2 == *real_it2);
		++own_it;
		++real_it;
		REQUIRE(*own_it == *real_it);
	}
	
	SECTION("Decrement - prefix and postfix")
	{
		own_ite--;
		real_ite--;
		REQUIRE(*own_ite->data() == *real_ite->data());
		--own_ite;
		--real_ite;
		REQUIRE(*own_ite == *real_ite);
	}
//     SECTION("+ overload") {
//         own_it = own_it + 2;
//         real_it = real_it + 2;
//         REQUIRE(*own_it == *real_it);
//         int res = *ft_two + *ft_two;
//         REQUIRE(res == 4);
//     }
//     SECTION("- overload") {
//         own_ite = own_ite - 3;
//         real_ite = real_ite - 3;
//         REQUIRE(*own_ite == *real_ite);
//         int res = *ft_four - *ft_two;
//         REQUIRE(res == 2);
//     }
//     SECTION("+= overload") {
//         own_it += 2;
//         real_it += 2;
//         REQUIRE(*own_it == *real_it);
//     }
//     SECTION("-= overload") {
//         own_ite -= 3;
//         real_ite -= 3;
//         REQUIRE(*own_ite == *real_ite);
//     }
//     SECTION("< overload") {
//         bool res = *ft_two < *ft_four;
//         REQUIRE(res == true);
//     }
//     SECTION("> overload") {
//         bool res = *ft_two > *ft_four;
//         REQUIRE(res == false);
//     }
//     SECTION("<= overload") {
//         bool res = *ft_four <= *ft_four;
//         REQUIRE(res == true);
//         res = *ft_two <= *ft_two;
//         REQUIRE(res == true);
//     }
//     SECTION(">= overload") {
//         bool res = *ft_two >= *ft_four;
//         REQUIRE(res == false);
//         res = *ft_two >= *ft_two;
//         REQUIRE(res == true);
//     }
//     SECTION("== operator") {
//         bool equal;
//         equal = (*own_it == *real_it);
//         REQUIRE(equal == true);
//         ++own_it;
//         equal = (*own_it == *real_it);
//         REQUIRE(equal == false);
//     }
//     SECTION("!= operator") {
//         bool unequal;
//         unequal = (*own_it != *real_it);
//         REQUIRE(unequal == false);
//         ++real_it;
//         unequal = (*own_it != *real_it);
//         REQUIRE(unequal == true);
//     }
// }

// TEST_CASE( "Const RandomAccesIterator", "[vector]") {
//     ft::vector<std::string> ft_vector;
//     std::vector<std::string> real_vector;

//     ft_vector.push_back("hallo");
//     std_vector.push_back("hallo");
//     ft_vector.push_back("world");
//     std_vector.push_back("world");
//     ft_vector.push_back("here");
//     std_vector.push_back("here");
//     ft_vector.push_back("there");
//     std_vector.push_back("there");

//     ft::vector<std::string>::const_iterator ft_it = ft_vector.begin();
//     std::vector<std::string>::const_iterator std_it = std_vector.begin();

//     ft::vector<std::string>::const_iterator ft_it_end = ft_vector.end();
//     std::vector<std::string>::const_iterator std_it_end = std_vector.end();

//     ft::vector<int> ft_vector_int;
//     ft_vector_int.push_back(2);
//     ft_vector_int.push_back(4);

//     ft::vector<int>::iterator ft_two = ft_vector_int.begin();
//     ft::vector<int>::iterator ft_four = ft_vector_int.begin() + 1;

//     SECTION("* overload") {
//         ft_it++;
//         std_it++;
//         REQUIRE(*ft_it == *std_it);
//     }
//     SECTION("-> overload") {
//         ft_it++;
//         std_it++;
//         REQUIRE(*ft_it->data() == *std_it->data());
//     }
//     SECTION("[] overload") {
//         REQUIRE(ft_it[3] == "there");
//         REQUIRE(ft_it[3] == std_it[3]);
//     }
//     SECTION("Increment - prefix and postfix") {
//         REQUIRE(*ft_it == *std_it);
//         ft_it++;
//         std_it++;
//         REQUIRE(*ft_it->data() == *std_it->data());
//         ++ft_it;
//         ++std_it;
//         REQUIRE(*ft_it == *std_it);
//     }
//     SECTION("Decrement - prefix and postfix") {
//         ft_it_end--;
//         std_it_end--;
//         REQUIRE(*ft_it_end->data() == *std_it_end->data());
//         --ft_it_end;
//         --std_it_end;
//         REQUIRE(*ft_it_end == *std_it_end);
//     }
//     SECTION("+ overload") {
//         ft_it = ft_it + 2;
//         std_it = std_it + 2;
//         REQUIRE(*ft_it == *std_it);
//         int res = *ft_two + *ft_two;
//         REQUIRE(res == 4);
//     }
//     SECTION("- overload") {
//         ft_it_end = ft_it_end - 3;
//         std_it_end = std_it_end - 3;
//         REQUIRE(*ft_it_end == *std_it_end);
//         int res = *ft_four - *ft_two;
//         REQUIRE(res == 2);
//     }
//     SECTION("+= overload") {
//         ft_it += 2;
//         std_it += 2;
//         REQUIRE(*ft_it == *std_it);
//     }
//     SECTION("-= overload") {
//         ft_it_end -= 3;
//         std_it_end -= 3;
//         REQUIRE(*ft_it_end == *std_it_end);
//     }
//     SECTION("< overload") {
//         bool res = *ft_two < *ft_four;
//         REQUIRE(res == true);
//     }
//     SECTION("> overload") {
//         bool res = *ft_two > *ft_four;
//         REQUIRE(res == false);
//     }
//     SECTION("<= overload") {
//         bool res = *ft_four <= *ft_four;
//         REQUIRE(res == true);
//         res = *ft_two <= *ft_two;
//         REQUIRE(res == true);
//     }
//     SECTION(">= overload") {
//         bool res = *ft_two >= *ft_four;
//         REQUIRE(res == false);
//         res = *ft_two >= *ft_two;
//         REQUIRE(res == true);
//     }
//     SECTION("== operator") {
//         bool equal;
//         equal = (*ft_it == *std_it);
//         REQUIRE(equal == true);
//         ++ft_it;
//         equal = (*ft_it == *std_it);
//         REQUIRE(equal == false);
//     }
//     SECTION("!= operator") {
//         bool unequal;
//         unequal = (*ft_it != *std_it);
//         REQUIRE(unequal == false);
//         ++std_it;
//         unequal = (*ft_it != *std_it);
//         REQUIRE(unequal == true);
//     }
// }

// TEST_CASE( "Rev RandomAccesIterator", "[vector]") {
//     ft::vector<std::string> ft_vector;
//     std::vector<std::string> std_vector;

//     ft_vector.push_back("hallo");
//     std_vector.push_back("hallo");
//     ft_vector.push_back("world");
//     std_vector.push_back("world");
//     ft_vector.push_back("here");
//     std_vector.push_back("here");
//     ft_vector.push_back("there");
//     std_vector.push_back("there");

//     ft::vector<std::string>::reverse_iterator ft_it = ft_vector.rbegin();
//     std::vector<std::string>::reverse_iterator std_it = std_vector.rbegin();

//     ft::vector<std::string>::reverse_iterator ft_it_end = ft_vector.rend();
//     std::vector<std::string>::reverse_iterator std_it_end = std_vector.rend();

//     ft::vector<int> ft_vector_int;
//     ft_vector_int.push_back(2);
//     ft_vector_int.push_back(4);

//     ft::vector<int>::reverse_iterator ft_two = ft_vector_int.rbegin();
//     ft::vector<int>::reverse_iterator ft_four = ft_vector_int.rbegin() + 1;

//     std::vector<int> std_vector_int;
//     std_vector_int.push_back(2);
//     std_vector_int.push_back(4);

//     std::vector<int>::reverse_iterator std_two = std_vector_int.rbegin();
//     std::vector<int>::reverse_iterator std_four = std_vector_int.rbegin() + 1;

//     SECTION("* overload") {
//         ft_it++;
//         std_it++;
//         REQUIRE(*ft_it == *std_it);
//     }
//     SECTION("-> overload") {
//         ft_it++;
//         std_it++;
//         REQUIRE(*ft_it->data() == *std_it->data());
//     }
//     SECTION("[] overload") {
//         REQUIRE(ft_it[3] == "hallo");
//         REQUIRE(ft_it[3] == std_it[3]);
//     }
//     SECTION("Increment - prefix and postfix") {
//         REQUIRE(*ft_it == *std_it);
//         ft_it++;
//         std_it++;
//         REQUIRE(*ft_it->data() == *std_it->data());
//         ++ft_it;
//         ++std_it;
//         REQUIRE(*ft_it == *std_it);
//     }
//     SECTION("Decrement - prefix and postfix") {
//         ft_it_end--;
//         std_it_end--;
//         REQUIRE(*ft_it_end->data() == *std_it_end->data());
//         --ft_it_end;
//         --std_it_end;
//         REQUIRE(*ft_it_end == *std_it_end);
//     }
//     SECTION("+ overload") {
//         ft_it = ft_it + 2;
//         std_it = std_it + 2;
//         REQUIRE(*ft_it == *std_it);
//         int res = *ft_two + *ft_two;
//         int std_res = *std_two + *std_two;
//         REQUIRE(res == std_res);
//     }
//     SECTION("- overload") {
//         ft_it_end = ft_it_end - 3;
//         std_it_end = std_it_end - 3;
//         REQUIRE(*ft_it_end == *std_it_end);
//         int res = *ft_four - *ft_two;
//         int std_res = *std_four - *std_two;
//         REQUIRE(res == std_res);
//     }
//     SECTION("+= overload") {
//         ft_it += 2;
//         std_it += 2;
//         REQUIRE(*ft_it == *std_it);
//     }
//     SECTION("-= overload") {
//         ft_it_end -= 3;
//         std_it_end -= 3;
//         REQUIRE(*ft_it_end == *std_it_end);
//     }
//     SECTION("< overload") {
//         bool res = *ft_two < *ft_four;
//         bool std_res = *std_two < *std_four;
//         REQUIRE(res == std_res);
//     }
//     SECTION("> overload") {
//         bool res = *ft_two > *ft_four;
//         bool std_res = *std_two > *std_four;
//         REQUIRE(res == std_res);
//     }
//     SECTION("<= overload") {
//         bool res = *ft_four <= *ft_four;
//         bool std_res = *std_four <= *std_four;
//         REQUIRE(res == std_res);
//         res = *ft_two <= *ft_two;
//         std_res = *std_two <= *std_two;
//         REQUIRE(res == std_res);
//     }
//     SECTION(">= overload") {
//         bool res = *ft_two >= *ft_four;
//         bool std_res = *std_two >= *std_four;
//         REQUIRE(res == std_res);
//         res = *ft_two >= *ft_two;
//         std_res = *std_two >= *std_two;;
//         REQUIRE(res == std_res);
//     }
//     SECTION("== operator") {
//         bool equal = (*ft_it == *std_it);
//         REQUIRE(equal == true);
//         ++ft_it;
//         equal = (*ft_it == *std_it);
//         REQUIRE(equal == false);
//     }
//     SECTION("!= operator") {
//         bool unequal = (*ft_it != *std_it);
//         REQUIRE(unequal == false);
//         ++std_it;
//         unequal = (*ft_it != *std_it);
//         REQUIRE(unequal == true);
//     }
// }

// TEST_CASE( "Const Rev RandomAccesIterator", "[vector]") {
//     ft::vector<std::string> ft_vector;
//     std::vector<std::string> std_vector;

//     ft_vector.push_back("hallo");
//     std_vector.push_back("hallo");
//     ft_vector.push_back("world");
//     std_vector.push_back("world");
//     ft_vector.push_back("here");
//     std_vector.push_back("here");
//     ft_vector.push_back("there");
//     std_vector.push_back("there");

//     ft::vector<std::string>::const_reverse_iterator ft_it = ft_vector.rbegin();
//     std::vector<std::string>::const_reverse_iterator std_it = std_vector.rbegin();

//     ft::vector<std::string>::const_reverse_iterator ft_it_end = ft_vector.rend();
//     std::vector<std::string>::const_reverse_iterator std_it_end = std_vector.rend();

//     ft::vector<int> ft_vector_int;
//     ft_vector_int.push_back(2);
//     ft_vector_int.push_back(4);

//     ft::vector<int>::const_reverse_iterator ft_two = ft_vector_int.rbegin();
//     ft::vector<int>::const_reverse_iterator ft_four = ft_vector_int.rbegin() + 1;

//     std::vector<int> std_vector_int;
//     std_vector_int.push_back(2);
//     std_vector_int.push_back(4);

//     std::vector<int>::const_reverse_iterator std_two = std_vector_int.rbegin();
//     std::vector<int>::const_reverse_iterator std_four = std_vector_int.rbegin() + 1;

//     SECTION("* overload") {
//         ft_it++;
//         std_it++;
//         REQUIRE(*ft_it == *std_it);
//     }
//     SECTION("-> overload") {
//         ft_it++;
//         std_it++;
//         REQUIRE(*ft_it->data() == *std_it->data());
//     }
//     SECTION("[] overload") {
//         REQUIRE(ft_it[3] == "hallo");
//         REQUIRE(ft_it[3] == std_it[3]);
//     }
//     SECTION("Increment - prefix and postfix") {
//         REQUIRE(*ft_it == *std_it);
//         ft_it++;
//         std_it++;
//         REQUIRE(*ft_it->data() == *std_it->data());
//         ++ft_it;
//         ++std_it;
//         REQUIRE(*ft_it == *std_it);
//     }
//     SECTION("Decrement - prefix and postfix") {
//         ft_it_end--;
//         std_it_end--;
//         REQUIRE(*ft_it_end->data() == *std_it_end->data());
//         --ft_it_end;
//         --std_it_end;
//         REQUIRE(*ft_it_end == *std_it_end);
//     }
//     SECTION("+ overload") {
//         ft_it = ft_it + 2;
//         std_it = std_it + 2;
//         REQUIRE(*ft_it == *std_it);
//         int res = *ft_two + *ft_two;
//         int std_res = *std_two + *std_two;
//         REQUIRE(res == std_res);
//     }
//     SECTION("- overload") {
//         ft_it_end = ft_it_end - 3;
//         std_it_end = std_it_end - 3;
//         REQUIRE(*ft_it_end == *std_it_end);
//         int res = *ft_four - *ft_two;
//         int std_res = *std_four - *std_two;
//         REQUIRE(res == std_res);
//     }
//     SECTION("+= overload") {
//         ft_it += 2;
//         std_it += 2;
//         REQUIRE(*ft_it == *std_it);
//     }
//     SECTION("-= overload") {
//         ft_it_end -= 3;
//         std_it_end -= 3;
//         REQUIRE(*ft_it_end == *std_it_end);
//     }
//     SECTION("< overload") {
//         bool res = *ft_two < *ft_four;
//         bool std_res = *std_two < *std_four;
//         REQUIRE(res == std_res);
//     }
//     SECTION("> overload") {
//         bool res = *ft_two > *ft_four;
//         bool std_res = *std_two > *std_four;
//         REQUIRE(res == std_res);
//     }
//     SECTION("<= overload") {
//         bool res = *ft_four <= *ft_four;
//         bool std_res = *std_four <= *std_four;
//         REQUIRE(res == std_res);
//         res = *ft_two <= *ft_two;
//         std_res = *std_two <= *std_two;
//         REQUIRE(res == std_res);
//     }
//     SECTION(">= overload") {
//         bool res = *ft_two >= *ft_four;
//         bool std_res = *std_two >= *std_four;
//         REQUIRE(res == std_res);
//         res = *ft_two >= *ft_two;
//         std_res = *std_two >= *std_two;;
//         REQUIRE(res == std_res);
//     }
//     SECTION("== operator") {
//         bool equal = (*ft_it == *std_it);
//         REQUIRE(equal == true);
//         ++ft_it;
//         equal = (*ft_it == *std_it);
//         REQUIRE(equal == false);
//     }
//     SECTION("!= operator") {
//         bool unequal = (*ft_it != *std_it);
//         REQUIRE(unequal == false);
//         ++std_it;
//         unequal = (*ft_it != *std_it);
//         REQUIRE(unequal == true);
//     }
}