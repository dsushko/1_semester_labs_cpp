#include "GTests/googlemock/include/gmock/gmock.h"
#include "GTests/googletest/include/gtest/gtest.h"
#include "everything.h"

TEST(Stack_size, Sample) {
    Stack<int> stack;
    ASSERT_EQ(stack.size(), 0);
    ASSERT_TRUE(stack.isEmpty());
    ASSERT_FALSE(stack.size() > 0);
    stack.push(1);
    stack.push(1);
    stack.push(1);
    stack.push(1);
    stack.push(1);
    stack.push(1);
    stack.push(1);
    stack.push(1);
    stack.push(1);
    stack.push(1);
    ASSERT_EQ(stack.size(), 10);
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    ASSERT_EQ(stack.size(), 5);
}
TEST(Stack_operators, Sample){
    Stack<int> stack1;
    stack1 = {1,2,3,4,5,6};
    Stack<int> stack2;
    stack2 = {1,2,3,4,5};
    ASSERT_FALSE(stack1 < stack2 );
    ASSERT_TRUE(stack1 > stack2 );
    stack2.push(6);
    ASSERT_TRUE(stack1 == stack2);
}
TEST(Stack_operators, mrakobesie){
    Stack<int> stack;
    stack << 7;
    ASSERT_EQ(stack[0], 7);
    int var;
    stack >> var;
    ASSERT_EQ(var, 7);
}
TEST(Calculator_operators, memory){
    calculator::processExpression("1+2");
    calculator::kurwa();
    ASSERT_EQ(calculator::calculateResult(), 3);
}
TEST(Calculator_operators, ExpressionChecker){
    ASSERT_TRUE(calculator::isExpressionCorrect("(7+2)/(3-5)"));
    ASSERT_TRUE(calculator::isExpressionCorrect("(((3)))"));
    ASSERT_TRUE(calculator::isExpressionCorrect("(7+2*3-5)"));
    ASSERT_TRUE(calculator::isExpressionCorrect("7+(2+3)-5"));
    ASSERT_FALSE(calculator::isExpressionCorrect("3+"));
    ASSERT_FALSE(calculator::isExpressionCorrect("((((3+3)))"));
    ASSERT_FALSE(calculator::isExpressionCorrect("3+5*"));
}
TEST(Calculator_operators,reverse_polish){
    ASSERT_EQ(calculator::kurwa("3+1/7"), "3 1 7 / +");
    ASSERT_EQ(calculator::kurwa("(3+1)/7"), "3 1 + 7 /");
    ASSERT_EQ(calculator::kurwa("(3+1)/(7-5)"), "3 1 + 7 5 - /");
}
TEST(Calculator_operators, calculate_expression){
    ASSERT_EQ(calculator::calculateResult(calculator::kurwa("2+2*2")), 6);
    ASSERT_EQ(calculator::calculateResult(calculator::kurwa("15*7-5+100*(2+5)")), 800);
    ASSERT_EQ(calculator::calculateResult(calculator::kurwa("(7+3)/(5-3)")), 5);
}


