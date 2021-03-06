%{
/*
	This will scan the input.
	Note that I don't conform exclusively to his list of tokens
	I changed them slightly so that parsing would be more straightforward.
	Keywords especially have their own token type, instead of just being KEYWORD
*/

#include "y.tab.h"


%}
%%


[\n] { return NEWLINE; }

\= { return EQ; }

\#[^\n] { return COMMENT; }

\<bg\> { return BG; }

defprompt { return DEFPROMPT; }

cd { return CD;  }

run { return RUN; }

listjobs { return LISTJOBS;  }

bye { return BYE;  }
exit { return BYE; }
quit { return BYE; }

assignto { return ASSIGNTO;  }

[ \t]+ {
	return WHITESPACE;
}

\".+\" {
	int len = strlen(yytext) - 2;
	char *buff = (char*) malloc(sizeof(char) * (len+1));
	memcpy(buff, yytext+1, len);
	buff[len] = '\0';
	yylval.string = buff;
	return STRING;
}

\$[A-Z0-9a-z]+ {
	yylval.string = strdup(yytext);
	return VARIABLE;
}

[^ \$\n\t=\#]+ {
	yylval.string = strdup(yytext);
	return WORD;
}

%%

