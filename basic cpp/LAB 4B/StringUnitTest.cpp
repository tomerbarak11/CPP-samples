//
// Dynamic String Homework Exercise phase 3
//
//
#include "mu_test.h"
#include "String.h"
#include <stdio.h>



UNIT(default_string_is_empty)
	String s;
	printf("len=%ld\n",s.length());
	ASSERT_EQUAL(s.length(), 0);
	ASSERT_EQUAL_STR(s.get(), "");
	//ASSERT_EQUAL(s.get(), "");

	String t;
	ASSERT_EQUAL(s, t);

END_UNIT

UNIT(string_can_concatenate)
	String s(" ");
	String b("The quick brown");
	String fox("fox");
	String dog("jumps over the lazy dog");

	String r(b);
	printf("r(b)=%s\n",r.get());
	ASSERT_EQUAL(r , b);
	printf("len 1 (b)=%ld\n",strlen(r.get()));

	r += s;
	printf("len 2 (b)=%ld\n",strlen(r.get()));

	r += fox;

	TRACER << r << '\n';
	ASSERT_EQUAL(r , b + s + fox);

	r += s;
	r += dog;

	TRACER << r << '\n';
	ASSERT_EQUAL(r, "The quick brown fox jumps over the lazy dog");
END_UNIT

UNIT(substring_select_chars)
	const char* cstr = "Write code that is easy to delete, not easy to extend!";
	String s(cstr);

	ASSERT_EQUAL(s.length(), strlen(cstr));
	//ASSERT_EQUAL(s.get(), cstr);
	ASSERT_EQUAL_STR(s.get(), cstr);

	const int from = 6;
	const int len = 4;
	String code = s(from, len);
	TRACER << "sentence : " << cstr << '\n';
	TRACER << "word(4,6): " << code << '\n';
	//ASSERT_EQUAL(code.get(), "code");
	ASSERT_EQUAL_STR(code.get(), "code");

	ASSERT_EQUAL(code.length(), len);


	const char* lastWord = strrchr(cstr, ' ')  + 1;
	const int lenLastWord = strlen(lastWord) ;
	String r = s(s.length() - lenLastWord, lenLastWord);

	TRACER << "last word: " << lastWord << '\n';

	ASSERT_EQUAL_INT(r.length(), lenLastWord);
	ASSERT_EQUAL_STR(r.get(), lastWord);

	String w = s(s.length() - 7, 16);
	ASSERT_EQUAL(w.length(), 7);
	//ASSERT_EQUAL(w.get(), "extend!");
	ASSERT_EQUAL_STR(w.get(), "extend!");

	//ASSERT_EQUAL(w, "extend!");
	ASSERT_EQUAL_STR(w.get(), "extend!");

END_UNIT

TEST_SUITE(String Unit Test)

	/*TEST(default_string_is_empty)
	TEST(string_can_concatenate)*/
	TEST(substring_select_chars)

END_SUITE
