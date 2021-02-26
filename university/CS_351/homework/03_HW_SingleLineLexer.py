# Homework 3 - Single-line Lexer (no GUI)
# King, CS 351, 02/17/2021

# ================================================================================
# Lexer for TinyPie - Type+Regex Key
# ================================================================================
# Keywords:			if, else, int, float					((if)|(else)|(int)|(float))\b
# Operators:		=, +, >, *								(=)|(\+)|(>)|(\*)
# Separators:		(, ), :, ", “, ;						(\()|(\))|(:)|(")|(“)|(;)
# Float literals:	only floats								\d+\.\d+
# Integer literals:	only integers							\d+
# Identifiers: 		letters, or letters followed by digits	\w+\d*
# String literals:	only strings (enclosed in ")			\".+\"
# ================================================================================

import re  # regular expressions library


def parse_line(line):
	# Scans the given line of code, extracting a token from the beginning of the line.
	# param line: a single line of code.
	# return: a list of strings in the form '<type, value>'.
	types = ['string', 'keyword', 'operator', 'separator', 'float', 'integer', 'identifier']
	patterns = [r'\".+\"', r'((if)|(else)|(int)|(float))\b', r'(=)|(\+)|(>)|(\*)',
				r'(\()|(\))|(:)|(;)', r'\d+\.\d+', r'\d+', r'\w+\d*']
	quotetype = 'separator'
	quotepattern = '\"'
	numpatterns = len(patterns)
	tokenlist = []

	while len(line) > 0:
		line = line.lstrip()  # removes possible leading whitespace
		match = None

		i = 0
		while (i < numpatterns) and (match is None):
			match = re.match(patterns[i], line)  # check pattern from beginning
			i += 1

		if match is not None:
			token = match.group(0)
			line = line[match.end():]  # substring from the end of current token
			if i == 1:  # 'string' case from position 0 of types
				tokenlist.append('<' + quotetype + ', ' + token[0] + '>')
				tokenlist.append('<' + types[i-1] + ', ' + token.replace(quotepattern, '') + '>')  # removes quotations
				tokenlist.append('<' + quotetype + ', ' + token[0] + '>')
			else:
				tokenlist.append('<' + types[i-1] + ', ' + token + '>')
		elif len(line) != 0:
			print("Next token in line \'" + line + "\' is invalid.")

	return tokenlist


if __name__ == '__main__':
	lines = ['int A1=5', '   float  BBB2 =1034.2 ', '   float cresult = A1 +BBB2 * BBB2',
			 'if (cresult >10):', '\tprint("  TinyPie " )', 'if(num>10.1)', 'int a = b1',
			 'int b1 = a', 'intt notkeyword', 'str="hello world! :)"']

	num = 1
	for ln in lines:
		print(str(num) + ". Testing line: \'" + ln + "\'")
		print("Output list:", parse_line(ln))
		num += 1
