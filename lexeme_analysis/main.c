#include <stdio.h>
#include <ctype.h>
// 함수 선언들
void addChar();
void getChar();
void getNonBlank();
int lex();
int lookup(char ch);

// 재귀-하강 파싱
void expr();
void term();
void factor();

// 문자 유형들
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

// 토큰 코드들
#define INT_LIT 10
#define INDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26


int charClass;
char lexeme[100];
char nextChar;
int lexLen;
int token;
int nextToken;
FILE *in_fp, *fopen();

int main() {
    if((in_fp = fopen("/Users/byungwook/Documents/Project/C/data_structure/lexeme_analysis/front.in", "r")) == NULL){
        printf("ERROR - cannont open front.in \n");
    } else {
        getChar();
        do {
            lex();
//            expr();   // 재귀-하강 파싱을 이용하려면 주석 해제
        } while (nextToken != EOF);
    }
    return 0;
}

int lookup(char ch){
    switch (ch) {
        case '(':
            addChar();
            nextToken = LEFT_PAREN;
            break;
        case ')':
            addChar();
            nextToken = RIGHT_PAREN;
            break;
        case '+':
            addChar();
            nextToken = ADD_OP;
            break;
        case '-':
            addChar();
            nextToken = SUB_OP;
            break;
        case '*':
            addChar();
            nextToken = MULT_OP;
            break;
        case '/':
            addChar();
            nextToken = DIV_OP;
            break;
        default:
            addChar();
            nextToken = EOF;
            break;
    }
    return nextToken;
}

// nextChar 을 lexeme에 추가하는 함수.
void addChar(){
    if(lexLen <= 98) {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = 0;
    } else {
        printf("Error - lexeme is too long\n");
    }
}

// 입력으로부터 다음 번째 문자를 가져와서 그 문자 유형을 결정하는 함수
void getChar(){
    if((nextChar = getc(in_fp)) != EOF){
        if(isalpha(nextChar)){
            charClass = LETTER;
        } else if (isdigit(nextChar)){
            charClass = DIGIT;
        } else {
            charClass = UNKNOWN;
        }
    } else {
        charClass = EOF;
    }
}

// 비 공백 문자를 반환할 때까지 getChar를 호출하는 함수
// 공백을 제거하는 역할
void getNonBlank(){
    while(isspace(nextChar)){
        getChar();
    }
}

// 산술 식을 위한 단순 어휘 분석기
// lexeme을 넣는다.
int lex() {
    lexLen = 0;
    getNonBlank();
    switch (charClass) {
        case LETTER:
            addChar();
            getChar();
            while(charClass == LETTER || charClass == DIGIT){
                addChar();
                getChar();
            }
            nextToken = INDENT;
            break;
        case DIGIT:
            addChar();
            getChar();
            while(charClass == DIGIT){
                addChar();
                getChar();
            }
            nextToken = INT_LIT;
            break;
        case UNKNOWN:
            lookup(nextChar);
            getChar();
            break;
        case EOF:
            nextToken = EOF;
            lexeme[0] = 'E';
            lexeme[1] = 'O';
            lexeme[2] = 'F';
            lexeme[3] = 0;
            break;
    }
    printf("Next token is: %d, Next lexeme is %s\n", nextToken, lexeme);
}

// <expr> -> <term>  {( + | - ) <term>}
// <term> -> <factor> {( * | / ) <factor>}
// <factor> -> id | int_constant | (<expr>)

// 재귀-하강 파싱
void expr(){
    printf("Enter <expr>\n");

    term();

    while(nextToken == ADD_OP || nextToken == SUB_OP){
        lex();
        term();
    }
    printf("Exit <expr>\n");
}

void term(){
    printf("Enter <term>\n");

    factor();

    while(nextToken == MULT_OP || nextToken == DIV_OP){
        lex();
        factor();
    }

    printf("Exit <term>\n");
}

void factor(){
    printf("Enter <factor>\n");

    if(nextToken == INDENT || nextToken == INT_LIT){
        lex();
    } else {
        if(nextToken == LEFT_PAREN){
            lex();
            expr();
            if(nextToken == RIGHT_PAREN){
                lex();
            } else {
                printf("Error!!\n");
            }
        } else {
            printf("Error!!\n");
        }
    }
}