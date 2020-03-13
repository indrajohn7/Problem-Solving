namespace parser{
	double prim(bool);
	double term(bool);
	double expr(bool);
}

namespace lexer{
	enum Token{
		Name,Number,end,plus='+',minus='-',lp='(',rp=')',div='/'
		mul='*',print='=',assign='='
	};

	Token curr_tok;
	double number;
	string string_value;

	Token get_token();
}



namespace driver{
	
}
