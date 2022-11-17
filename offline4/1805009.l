%option noyywrap yylineno
%x str_state2
%x str_state3
%x comm_state2
%x comm_state3
%x numm_state2
%x numm_state3

%{
    #include<iostream>
    #include<stdio.h>
    #include<stdlib.h>
	#include<string.h>
	#include<string>
	#include "symboltable.cpp"
	#include "y.tab.h"
    using namespace std;
    extern YYSTYPE yylval;
    
	int line_count=1,err=0;
	string str="\"";
	string log_str="";

	extern FILE* fout;
    extern FILE* errorout;
	extern SymbolTable st;
	extern SymbolInfo temp;
%}
%%
[ \t\f\r\v]+ {}
\+|\- {
SymbolInfo *temp= new SymbolInfo(yytext,"ADDOP");
    yylval.symbolinfo=temp;
	return ADDOP;
}
[\*/%] {
SymbolInfo *temp= new SymbolInfo(yytext,"MULOP");
    yylval.symbolinfo=temp;
	return MULOP;}
\+\+ {
SymbolInfo *temp= new SymbolInfo(yytext,"INCOP");
    yylval.symbolinfo=temp;
	return INCOP;}
\-\- {
SymbolInfo *temp= new SymbolInfo(yytext,"INCOP");
    yylval.symbolinfo=temp;
	return DECOP;}
"<"|"<="|">"|">="|"=="|"!=" {
SymbolInfo *temp= new SymbolInfo(yytext,"RELOP");
    yylval.symbolinfo=temp;
return RELOP;}
= {
SymbolInfo *temp= new SymbolInfo(yytext,"ASSIGNOP");
    yylval.symbolinfo=temp;
	return ASSIGNOP;}
&&|\|\| {
SymbolInfo *temp= new SymbolInfo(yytext,"LOGICOP");
    yylval.symbolinfo=temp;
	return LOGICOP;
}
! {
SymbolInfo *temp= new SymbolInfo(yytext,"NOT");
    yylval.symbolinfo=temp;
	return NOT;
}
\( {
SymbolInfo *temp= new SymbolInfo(yytext,"LPAREN");
    yylval.symbolinfo=temp;
	return LPAREN;
}
\) {
SymbolInfo *temp= new SymbolInfo(yytext,"RPAREN");
    yylval.symbolinfo=temp;
	return RPAREN;}
\{ {
SymbolInfo *temp= new SymbolInfo(yytext,"LCURL");
    yylval.symbolinfo=temp;
	return LCURL;}
\} {
SymbolInfo *temp= new SymbolInfo(yytext,"RCURL");
    yylval.symbolinfo=temp;
	return RCURL;}
\[ {
SymbolInfo *temp= new SymbolInfo(yytext,"LTHIRD");
    yylval.symbolinfo=temp;
	return LTHIRD;}
\] {
SymbolInfo *temp= new SymbolInfo(yytext,"RTHIRD");
    yylval.symbolinfo=temp;
	return RTHIRD;}
, {
SymbolInfo *temp= new SymbolInfo(yytext,"COMMA");
    yylval.symbolinfo=temp;
	return COMMA;}
; {
SymbolInfo *temp= new SymbolInfo(yytext,"SEMICOLON");
    yylval.symbolinfo=temp;
	return SEMICOLON;}
println {
	SymbolInfo *temp= new SymbolInfo(yytext,"PRINTLN");
    yylval.symbolinfo=temp;
	return PRINTLN;
}
if {
	SymbolInfo *temp= new SymbolInfo(yytext,"IF");
    yylval.symbolinfo=temp;
	return IF;
}
for {SymbolInfo *temp= new SymbolInfo(yytext,"FOR");
    yylval.symbolinfo=temp;
	return FOR;}
do {SymbolInfo *temp= new SymbolInfo(yytext,"DO");
    yylval.symbolinfo=temp;
	return DO;}
int {SymbolInfo *temp= new SymbolInfo(yytext,"INT","int");
    yylval.symbolinfo=temp;
	return INT;
}
float {SymbolInfo *temp= new SymbolInfo(yytext,"FLOAT","float");
    yylval.symbolinfo=temp;
	return FLOAT;
}
void {SymbolInfo *temp= new SymbolInfo(yytext,"VOID","void");
    yylval.symbolinfo=temp;
	return VOID;}
switch {SymbolInfo *temp= new SymbolInfo(yytext,"SWITCH");
    yylval.symbolinfo=temp;
	return SWITCH;}
default {SymbolInfo *temp= new SymbolInfo(yytext,"DEFAULT");
    yylval.symbolinfo=temp;
	return DEFAULT;}
else {SymbolInfo *temp= new SymbolInfo(yytext,"ELSE");
    yylval.symbolinfo=temp;
	return ELSE;}
while {SymbolInfo *temp= new SymbolInfo(yytext,"WHILE");
    yylval.symbolinfo=temp;
	return WHILE;
}
break {SymbolInfo *temp= new SymbolInfo(yytext,"BREAK");
    yylval.symbolinfo=temp;
	return BREAK;}
char {SymbolInfo *temp= new SymbolInfo(yytext,"CHAR");
    yylval.symbolinfo=temp;
	return CHAR;}
double {SymbolInfo *temp= new SymbolInfo(yytext,"DOUBLE","float");
    yylval.symbolinfo=temp;
	return DOUBLE;}
return {SymbolInfo *temp= new SymbolInfo(yytext,"RETURN");
    yylval.symbolinfo=temp;
	return RETURN;}
case {SymbolInfo *temp= new SymbolInfo(yytext,"CASE");
    yylval.symbolinfo=temp;
	return CASE;}
continue {SymbolInfo *temp= new SymbolInfo(yytext,"CONTINUE");
    yylval.symbolinfo=temp;
	return CONTINUE;}
[0-9]+ {
SymbolInfo *temp= new SymbolInfo(yytext,"CONST_INT","int");
    yylval.symbolinfo=temp;
	return CONST_INT;
}
([0-9]+|([0-9]*\.[0-9]+))(E[+-]?[0-9]+)? {
SymbolInfo *temp= new SymbolInfo(yytext,"CONST_FLOAT","float");
    yylval.symbolinfo=temp;
	return CONST_FLOAT;
}
([0-9]+|([0-9]*\.[0-9]+))(E[+-]?[0-9]*)[\.E][0-9\.E]* {
	
	fprintf(fout,"Error at line no %d: Ill formed number %s\n",line_count,yytext);
	fprintf(errorout,"Error at line no %d: Ill formed number %s\n",line_count,yytext);
	err++;
	}
[0-9]*\.[0-9]*\.[E0-9\.]* {
	
	fprintf(fout,"Error at line no %d: Too many decimal points %s\n",line_count,yytext);
	fprintf(errorout,"Error at line no %d: Too many decimal points %s\n",line_count,yytext);
	err++;
	}
[0-9]+[a-zA-Z_]+ {
	
	fprintf(fout,"Error at line no %d: Invalid prefix on ID or invalid suffix on Number %s\n",line_count,yytext);
	fprintf(errorout,"Error at line no %d: Invalid prefix on ID or invalid suffix on Number %s\n",line_count,yytext);
	err++;
	}
'' {
	
	fprintf(fout,"Error at line no %d: Empty character constant error %s\n",line_count,yytext);
	fprintf(errorout,"Error at line no %d: Empty character constant error %s\n",line_count,yytext);
	err++;
	}
'\\' {
	
	fprintf(fout,"Error at line no %d: Unterminated character %s\n",line_count,yytext);
	fprintf(errorout,"Error at line no %d: Unterminated character %s\n",line_count,yytext);
	err++;
}


'([^\\]|\\[nt\\'afrvb0])' {
	char ch;
	if (yytext[1]=='\\')
	{if (yytext[2]=='n')
           ch='\n';
	else if (yytext[2]=='t')
	ch='\t';
	else if (yytext[2]=='\\')
	ch='\\';
	else if (yytext[2]=='a')
	ch='\a';
	else if (yytext[2]=='f')
	ch='\f';
	else if (yytext[2]=='r')
	ch='\r';
	else if (yytext[2]=='v')
	ch='\v';
	else if (yytext[2]=='b')
	ch='\b';
	else if (yytext[2]=='0')
	ch='\0';
	else if (yytext[2]=='\'')
	ch='\'';
	}
	else
	{
		ch=yytext[1];
	}

SymbolInfo *temp= new SymbolInfo(yytext,"CONST_CHAR");
    yylval.symbolinfo=temp;
	return CONST_CHAR;


   }

'.+' {
	fprintf(fout,"Error at line no %d: Multi character constant error %s\n",line_count,yytext);
	fprintf(errorout,"Error at line no %d: Multi character constant error %s\n",line_count,yytext);
	err++;
}

'[^'(\r?\n)]* {
	
	
	fprintf(fout,"Error at line no %d: Unterminated character %s\n",line_count,yytext);
	fprintf(errorout,"Error at line no %d: Unterminated character %s\n",line_count,yytext);
	err++;
	}
[a-zA-Z_][a-zA-Z0-9_]* {
SymbolInfo *temp= new SymbolInfo(yytext,"ID");
    yylval.symbolinfo=temp;
	return ID;

}
[/][/] {
	log_str+=yytext;
    BEGIN comm_state2;
}
<comm_state2>[^(\r?\n)\\]* {
	log_str+=yytext;
    BEGIN comm_state2;
}
<comm_state2>[\(\)] {
	log_str+=yytext;
    BEGIN comm_state2;
}
<comm_state2>\\ {
	log_str+=yytext;
    BEGIN  comm_state3;
}
<comm_state2>\r?\n {
	log_str.erase(log_str.size()-1);
	
	line_count=yylineno;
	log_str="";
    BEGIN INITIAL;
}
<comm_state3>\r?\n {
	log_str+=yytext;
    BEGIN comm_state2;
}
<comm_state3>\\ {
	log_str+=yytext;
    BEGIN comm_state3;
}
<comm_state3>. {
	log_str+=yytext;
    BEGIN comm_state2;
}
\/\*([^\*]|[\*]+[^\*\/])*[\*]+\/ {
	//fprintf(logout,"Line no %d: Token <COMMENT> Lexeme %s found\n",line_count,yytext);
	line_count=yylineno;}

\/\*([^\*]|[\*]+[^\*\/])*[\*]* {
	
	fprintf(fout,"Error at line no %d: Unterminated Comment %s\n",line_count,yytext);
	fprintf(errorout,"Error at line no %d: Unterminated Comment %s\n",line_count,yytext);
	err++;
    line_count=yylineno;
	}
\"[^\\\"(\r?\n)]* {
	
	log_str+=yytext;
	++yytext;
	str+=yytext;
	BEGIN str_state2;
	
	
	}
<str_state2>\" {

str+="\"";
log_str+="\"";
//fprintf(logout,"Line no %d: Token <STRING> Lexeme %s found --> <STRING, %s>\n",line_count,log_str.c_str(),str.c_str());
SymbolInfo *temp= new SymbolInfo(log_str,"STRING");
    yylval.symbolinfo=temp;
str="\"";
log_str="";
line_count=yylineno;
return STRING;
BEGIN INITIAL;
}
<str_state2>[^\\\"(\r?\n)]* {
	
	log_str+=yytext;
	str+=yytext;
	BEGIN str_state2;
}
<str_state2>\r?\n {

fprintf(fout,"Error at line no %d: Unterminated String %s\n",line_count,log_str.c_str());
fprintf(errorout,"Error at line no %d: Unterminated String %s\n",line_count,log_str.c_str());
err++;
line_count=yylineno;
str="\"";
log_str="";
BEGIN INITIAL;
}
<str_state2>\\ {
	log_str+=yytext;
	BEGIN str_state3;
}
<str_state3>\r?\n {
	log_str+=yytext;
	BEGIN str_state2;
}
<str_state3>. {
	if (yytext[0]=='n')
	str+='\n';
	else if (yytext[0]=='t')
	str+='\t';
	else if (yytext[0]=='\\')
	str+='\\';
	else if (yytext[0]=='a')
	str+='\a';
	else if (yytext[0]=='f')
	str+='\f';
	else if (yytext[0]=='r')
	str+='\r';
	else if (yytext[0]=='v')
	str+='\v';
	else if (yytext[0]=='b')
	str+='\b';
	else if (yytext[0]=='0')
	str+='\0';
	else if (yytext[0]=='\'')
	str+='\'';
	else if (strcmp(yytext,"\"")==0)
	str+=yytext;
	else
	{
		str+=yytext;
	}
	log_str+=yytext;
	BEGIN str_state2;
}
\r?\n {line_count++;}
. {
	fprintf(fout,"Error at line no %d: Unrecognized character %s\n",line_count,yytext);
	fprintf(errorout,"Error at line no %d: Unrecognized character %s\n",line_count,yytext);
	err++;
}
<<EOF>> {

return 0;}
%%