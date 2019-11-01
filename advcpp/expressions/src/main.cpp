#include "mu_test.h"
#include <iostream>
#include "expression.h"
#include "ops.h"
#include "numbers.h"
#include "lexer.h"
#include "parser.h"
#include <sstream>

using namespace std;

UNIT(test_1)
    Expression * m = add( 
                        mul(
                                number(42),
                                number(3)
                            ),
                        mul(
                                number(16),
                                number(10)
                            )
                        );
    ASSERT_THAT(m->value()==286);
    std::cout << m->value() << '\n';
END_UNIT

UNIT(test_2)
    std::string sourceCode = "42 3 * 16 10 * +";    
    std::stringstream src(sourceCode);

    Lexer lex(src);
    vector<string> tokens = lex.lex();

    Parser parser;
    Expression const* ast =  parser.parse(tokens);
    ASSERT_THAT(ast->value()==286);
    std::cout << ast->value() << '\n';
END_UNIT

UNIT(test_3)
    std::string sourceCode = "42 3 * 16 10 * +";    
    std::stringstream src(sourceCode);

    Lexer lex(src);
    vector<string> tokens = lex.lex();

    Parser parser;
    Expression const* ast =  parser.parse(tokens);
    ASSERT_THAT(ast->value()==286);
    std::ostream& os=std::cout;
    ast->printExpression(os);
END_UNIT

UNIT(test_4)
    std::string sourceCode = "5 2 * 7 +";    
    std::stringstream src(sourceCode);

    Lexer lex(src);
    vector<string> tokens = lex.lex();

    Parser parser;
    Expression const* ast =  parser.parse(tokens);
    ASSERT_THAT(ast->value()==17);
    std::ostream& os=std::cout;
    ast->printExpression(os);
END_UNIT

UNIT(test_5)
    std::string sourceCode = "5 2 * 7 + 8";    
    std::stringstream src(sourceCode);

    Lexer lex(src);
    vector<string> tokens = lex.lex();

    Parser parser;
    Expression const* ast =  parser.parse(tokens);
    std::ostream& os=std::cout;
    ast->printExpression(os);
END_UNIT

TEST_SUITE(Hash Tests)
	TEST(test_1)
 	TEST(test_2)
 	TEST(test_3)
 	TEST(test_4)


END_SUITE