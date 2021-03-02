# Homework 5 - Lexer With GUI Using Python
# King, CS 351, 03/01/2021

import re  # regular expressions

import tkinter as tk
from tkinter import messagebox


class Lexer:
    # Model for a simple Lexer tokenizer.
    # see: LexerGUI.process_line

    @staticmethod  # decorator - a function returning another function; staticmethod(Lexer.parse_line())
    def tokenize_line(self, raw_line):
        # Scans the given line of code, extracting a token from the beginning of the line.
        # param raw_line: a single line of code.
        # return: a list of strings in the form '<type, value>'.
        # throws: ValueError if an invalid character is found.
        types = ['string', 'keyword', 'operator', 'separator', 'float', 'integer', 'identifier']
        patterns = [r'\".+\"', r'((if)|(else)|(int)|(float))\b', r'(=)|(\+)|(>)|(\*)', r'(\()|(\))|(:)|(;)', r'\d+\.\d+', r'\d+', r'\w+\d*']
        quote_type = 'separator'
        quote_pattern = '\"'
        num_patterns = len(patterns)
        token_list = []
        line = raw_line

        while len(line) > 0:
            line = line.lstrip()  # removes possible leading whitespace
            match = None
            i = 0
            while (i < num_patterns) and (match is None):
                match = re.match(patterns[i], line)  # check pattern from beginning
                i += 1

            if match:
                token = match.group(0)
                line = line[match.end():]  # substring from the end of current token
                if i == 1:
                    # 'string' case from position 0 of types
                    token_list.append('<' + quote_type + ', ' + token[0] + '>')
                    token_list.append('<' + types[i - 1] + ', ' + token.replace(quote_pattern, '') + '>')
                    token_list.append('<' + quote_type + ', ' + token[0] + '>')
                else:
                    token_list.append('<' + types[i - 1] + ', ' + token + '>')
            elif len(line) != 0:
                print('Lexer.tokenize_line: token in line \'' + raw_line + '\' is invalid.')
                raise ValueError('Token from input \'' + raw_line + '\' is invalid.')

        return token_list


# end of class Lexer ===================================================================================================


class LexerGUI:
    # Graphical user component for a simple Lexer tokenizer.
    # todo: synchronize scrolling (mousewheel, up/down keys) for text fields, check '\n' weirdness

    def __init__(self, root):
        # dimensions, fonts and colors =================================================================================
        rows = 3
        cols = 2
        pad = 10
        border = 3
        text_width = 70  # initial width of input/output text fields
        tk_font = ('Consolas', 11)
        color_blue = '#ABC0DF'
        color_green = '#8FB894'
        tk_relief = tk.SUNKEN

        # class variables ==============================================================================================
        self.window_title = 'Lexical Analyzer for TinyPie'
        self.line_num = 0.0  # tracks current processing line
        self.line_tag = 'current'  # tag for current line highlighting

        # main window properties =======================================================================================
        self.master = root
        self.master.title(self.window_title)
        self.master.configure(bg=color_blue)
        self.master.geometry('850x550')
        self.master.minsize(510, 550)

        # grid properties ==============================================================================================
        # set row/col weights to allow widgets to reposition upon window resizing
        for row in range(0, rows):
            for col in range(0, cols):
                self.master.grid_columnconfigure(col, weight=1)
            self.master.grid_rowconfigure(row, weight=1)

        # row 1: "Source Code Input", "Lexical Analyzed Result" labels =================================================
        self.source_label = tk.Label(self.master, bg=color_blue, text='Source Code Input:')
        self.source_label.config(font=tk_font)
        self.source_label.grid(row=0, column=0, sticky=tk.SW, padx=pad)

        self.result_label = tk.Label(self.master, bg=color_blue, text='Lexical Analyzed Result:')
        self.result_label.config(font=tk_font)
        self.result_label.grid(row=0, column=1, sticky=tk.SW, padx=pad)

        # row 2: input/output text fields ==============================================================================
        # text fields and labels representing line numbers are placed within a frame
        # sticky attribute set to span the entire grid section
        # INPUT TEXT FIELD
        # frame
        self.input_frame = tk.Frame(self.master, relief=tk_relief, bd=border, bg=color_blue)
        self.input_frame.grid(row=1, column=0, sticky=tk.NSEW, padx=pad, pady=pad)

        # scroll bar
        self.input_scroll_Y = tk.Scrollbar(self.input_frame, orient='vertical', command=self.scroll_input_frame_y)
        self.input_scroll_Y.pack(side=tk.RIGHT, fill=tk.Y)

        # text fields
        self.input_num_label = tk.Text(self.input_frame, width=2, yscrollcommand=self.input_scroll_Y.set)
        self.input_num_label.pack(side=tk.LEFT, fill=tk.Y)

        self.input_text = tk.Text(self.input_frame, padx=5, width=text_width, wrap=tk.WORD, yscrollcommand=self.input_scroll_Y.set)
        self.input_text.pack(side=tk.RIGHT, fill=tk.BOTH, expand=1)
        self.input_text.tag_add(self.line_tag, '0.0', 'end')  # initialize tag for current line highlight
        # event to call update_line_nums for readjusting line number labels
        self.input_text.bind('<Configure>', lambda event: self.update_line_nums(self.input_text, self.input_num_label))
        self.input_text.bind('<Key>', lambda event: self.update_line_nums(self.input_text, self.input_num_label))

        # OUTPUT TEXT FIELD
        # frame
        self.output_frame = tk.Frame(self.master, relief=tk_relief, bd=border, bg=color_blue)
        self.output_frame.grid(row=1, column=1, sticky=tk.NSEW, padx=pad, pady=pad)

        # scroll bar
        self.output_scroll_Y = tk.Scrollbar(self.output_frame, orient='vertical', command=self.scroll_output_frame_y)
        self.output_scroll_Y.pack(side=tk.RIGHT, fill=tk.Y)

        # text fields
        self.output_num_label = tk.Text(self.output_frame, width=2, wrap=tk.WORD, yscrollcommand=self.output_scroll_Y.set)
        self.output_num_label.pack(side=tk.LEFT, fill=tk.Y)

        self.output_text = tk.Text(self.output_frame, padx=5, width=text_width, wrap=tk.WORD, yscrollcommand=self.output_scroll_Y.set)
        self.output_text.pack(side=tk.RIGHT, fill=tk.BOTH, expand=1)
        # event to call update_line_nums for readjusting line number labels
        self.output_text.bind('<Configure>', lambda event: self.update_line_nums(self.output_text, self.output_num_label))

        # row 3: "Current Processing Line" label and text field ========================================================
        # widgets are placed within a frame to be packed into the same column
        self.current_line_frame = tk.Frame(self.master, bg=color_blue)
        self.current_line_frame.grid(row=2, column=0, sticky=tk.NE, padx=pad)

        self.current_line_label = tk.Label(self.current_line_frame, bg=color_blue, text='Current Processing Line:')
        self.current_line_label.config(font=tk_font)
        self.current_line_label.pack(side=tk.LEFT, padx=pad)

        self.current_line_text = tk.Entry(self.current_line_frame, relief=tk_relief, bd=border, width=10)
        self.current_line_text.insert(0, int(self.line_num))
        self.current_line_text.pack(side=tk.RIGHT)

        # row 4: "Next Line", "Quit" buttons ===========================================================================
        self.next_line_button = tk.Button(self.master, text='Next Line', bg=color_green, font=tk_font, bd=border, command=self.process_line)
        self.next_line_button.grid(row=3, column=0, sticky=tk.E, padx=pad, pady=pad)

        self.quit_button = tk.Button(self.master, text='Quit', bg=color_green, font=tk_font, bd=border, command=self.end_program)
        self.quit_button.grid(row=3, column=1, sticky=tk.E, padx=pad, pady=pad)

    # functions ========================================================================================================
    def scroll_input_frame_y(self, *args):
        # Moves both the input text field and its corresponding line number text field according to their shared scroll
        # bar's interaction.
        self.input_num_label.yview(*args)
        self.input_text.yview(*args)

    def scroll_output_frame_y(self, *args):
        # Moves both the output text field and its corresponding line number text field according to their shared
        # scroll bar's interaction.
        self.output_num_label.yview(*args)
        self.output_text.yview(*args)

    def update_line_nums(self, text_field, num_label):
        # Redraws the line number labels adjacent to the "Source Code Input" or "Lexical Analyzed Result" text field
        # when the size of the window is changed ('<Configure'>) or any key is entered ('<Key>').
        # param text_field: the input or output text field.
        # param num_label: a text field modeling the line numbers of a corresponding text field.
        index = 0.0
        count = text_field.count('0.0', 'end', 'lines')[0]  # count returns a tuple
        num_label.configure(state=tk.NORMAL)
        num_label.delete(0.0, tk.END)  # clear entire selection
        while index < count:
            # calculate the number of newline chars determined by the number of wraps of the current line
            num_lines = text_field.count(str(index), str(index + 1), 'displaylines')
            num_blanks = 0 if not num_lines else num_lines[0] - 1
            # append the number of newline chars and the current line number
            num_label.insert(tk.END, ('\n' * num_blanks) + str(int(index)) + '\n')
            index += 1
        num_label.configure(state=tk.DISABLED)

    def process_line(self):
        # The current line within the input text field is displayed in the output text filed, and the "current
        # processing line" text field is incremented.
        start_index = str(self.line_num + 1)  # start input from start of current line, character 0
        end_index = str(self.line_num + 1) + ' lineend'  # end input from end of current line, '\n'
        end_index_highlight = str(self.line_num + 2)  # index for highlighting the entire row
        line = self.input_text.get(start_index, end_index)
        print('LexerGUI.process_line, line:', line)

        # remove highlight from previous line, and highlight the current processed line
        self.input_text.tag_delete(self.line_tag)
        self.input_text.tag_add(self.line_tag, start_index, end_index_highlight)
        self.input_text.tag_config(self.line_tag, background='yellow')

        if self.input_text.count(end_index, 'end', 'lines'):
            # if input exists after the end of the current line,
            # use Lexer model to translate current line input into a list of tokens
            # Lexer.parse_line throws ValueError if line contains invalid characters
            try:
                token_list = Lexer.tokenize_line(self, line)
                line = '' if not token_list else str(token_list)  # if list is empty, set output to a blank line
            except ValueError as ve:
                line = ''  # bad input- a blank line to be output to text field
                messagebox.showerror(self.window_title, ve)

            self.update_line_nums(self.output_text, self.output_num_label)  # update line number next to output field
            self.output_text.insert(tk.END, line + '\n')  # print tokens to output field
            self.current_line_text.delete(0, tk.END)
            self.current_line_text.insert(0, int(self.line_num))  # insert number to current line field
            self.line_num += 1
        else:
            print('LexerGUI.process_line: reached end of input.')
            self.input_text.tag_delete(self.line_tag)  # remove highlighted line
            messagebox.showinfo(self.window_title, 'Processing Complete.')

    def end_program(self):
        # Terminates the program following the selection of the "Quit" button.
        self.master.destroy()


# end of class LexerGUI ================================================================================================


if __name__ == '__main__':
    tk_root = tk.Tk()
    lexerGUI = LexerGUI(tk_root)
    tk_root.mainloop()
