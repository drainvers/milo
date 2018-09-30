#ifndef _SYNTAX_H
#define _SYNTAX_H

#define HL_HIGHLIGHT_NUMBERS (1 << 0)
#define HL_HIGHLIGHT_STRINGS (1 << 1)

enum editorHighlight {
	HL_NORMAL = 0,
	HL_COMMENT,
	HL_MLCOMMENT,
	HL_STRING,
	HL_NUMBER,
	HL_MATCH, // a search match
	HL_KEYWORD_TYPE = 10,
	HL_KEYWORD_PP,
	HL_KEYWORD_COND,
	HL_KEYWORD_RETURN,
	HL_KEYWORD_ADAPTER,
	HL_KEYWORD_LOOP,
	HL_BACKGROUND_DEFAULT,
};

struct editorSyntax {
	char *filetype;
	char **filematch;
	char **keywords;
	char *singleline_comment_start;
	char *multiline_comment_start;
	char *multiline_comment_end;
	int flags;
};

typedef struct hlColorMap {
	int commentColor;
	int mlCommentColor;
	int keywordCondColor;
	int keywordTypeColor;
	int keywordPPColor;
	int keywordReturnColor;
	int keywordAdapterColor;
	int keywordLoopColor;
	int stringColor;
	int numberColor;
	int matchColor;
	int backgroundColor;
	int defaultColor;
} hlColorMap;

/*** filetypes ***/

// C and C++
char *CCPP_extensions[] = {".c", ".cpp", ".h" , ".hpp", NULL};
char *CCPP_keywords[] = {
	// types and misc
	"char", "bool", "short", "int", "__int8", "__int16", "__int32", "__int64",
	"long", "wchar_t", "__wchar_t", "float", "double", "true", "false",
	"continue", "break", "enum", "struct", "class", "namespace", "using", "auto",
	"unsigned", "signed",
	// preprocessor
	"#define|", "#elif|", "#else|", "#ifndef|", "#error|", "#if|", "#ifdef|",
	"#pragma|", "#import|", "#include|", "#line|", "#undef|", "#using|", "#endif|",
	// conditionals
	"if~", "else~", "switch~", "case~", "default~", "try~", "throw~", "catch~",
	// return
	"return#", "goto#",
	// adapters
	"const^", "static^", "public^", "protected^", "void^", "typedef^", "union^",
	"virtual^", "volatile^", "private^", "register^", "friend^", "inline^",
	// loops
	"for@", "while@", "do@",
	NULL
};

#define CCPP_syntax { \
	"C/C++", \
	CCPP_extensions, \
	CCPP_keywords, \
	"//", "/*", "*/", \
	HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS \
}

// C#
char *CSHARP_extensions[] = {".cs", NULL};
char *CSHARP_keywords[] = {
	// types and misc
	"char", "bool", "short", "int", "byte", "null",
	"long", "float", "double", "decimal", "string", "sbyte", "uint", "ulong",
	"ushort", "true", "false", "continue", "break", "enum", "struct", "class",
	"namespace", "base", "new", "as", "is", "sizeof", "typeof", "stackalloc",
	"params", "ref", "out", "object", "using",
	// preprocessor
	"#define|", "#elif|", "#else|", "#error|", "#if|", "#warning|", "#undef|",
	"#line|", "#region|", "#endregion|", "#endif|",
	// conditionals
	"if~", "else~", "switch~", "case~", "try~", "throw~", "catch~", "default~",
	"finally~",
	// return
	"return#", "goto#", "in#",
	// adapters
	"const^", "static^", "public^", "protected^", "void^", "typedef^",
	"explicit^", "implicit^", "operator^", "fixed^", "lock^", "checked^",
	"unchecked^", "union^", "virtual^", "volatile^", "private^", "abstract^",
	"this^", "interface^", "override^", "readonly^", "sealed^", "unsafe^",
	"event^", "extern^", "internal^", "delegate^",
	// loops
	"for@", "while@", "do@", "foreach@",
	NULL
};

#define CSHARP_syntax { \
	"C#", \
	CSHARP_extensions, \
	CSHARP_keywords, \
	"//", "/*", "*/", \
	HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS \
}

// Python
char *PYTHON_extensions[] = {".py", NULL};
char *PYTHON_keywords[] = {
	// data types
	"str", "list", "tuple", "dict", "True", "False", "int", "None", "float",
	// imports etc.
	"import|", "from|",
	// conditionals
	"if~", "elif~", "continue~", "break~", "pass~", "try~",
	// return
	"return#", "raise#", "is#", "in#",
	// loops
	"for@", "while@", "try@", "except@", "finally@",
	// misc
	"and^", "or^", "global^", "print^", "with^", "yield^", "not^", "class^",
	"as^",
	NULL
};

#define PYTHON_syntax { \
	"Python", \
	PYTHON_extensions, \
	PYTHON_keywords, \
	"#", "'''", "'''", \
	HL_HIGHLIGHT_STRINGS | HL_HIGHLIGHT_NUMBERS \
}

// PHP
char *PHP_extensions[] = {".php", NULL};
char *PHP_keywords[] = {
	// misc
	"<?php", "?>", "break", "class", "continue", "enddeclare", "endfor",
	"endforeach", "endif", "endswitch", "endwhile", "function", "interface",
	"trait", "use",
	// adapters
	"abstract^", "callable^", "const^", "extends^", "final^", "global^",
	"implements^", "namespace^", "new^", "private^", "protected^", "static^",
	// conditionals
	"if~", "else~", "switch~", "case~", "try~", "catch~", "finally~", "and",
	"elseif~", "default#", "or", "throw~",
	// conditionals
	"if~", "else~", "switch~", "case~", "try~", "catch~", "finally~",
	// return
	"return#", "goto#",
	// loops
	"for@", "do@", "while@", "foreach@",
	// special
	"__halt_compiler~", "array~", "as", "__clone~", "declare~", "die~",
	"echo~", "empty~", "eval~", "exit~", "include~", "list~", "include_once~",
	"instanceof", "isset~", "print~", "require~", "require_once~", "unset~",
	NULL
};

#define PHP_syntax { \
	"PHP", \
	PHP_extensions, \
	PHP_keywords, \
	"//", "/*", "*/", \
	HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS \
}

// Pascal
char *PAS_extensions[] = {".pas", NULL};
char *PAS_keywords[] = {
	// types and misc
	"array", "begin", "asm", "constructor", "destructor", "div", "end",
	"false", "file", "function", "implementation", "interface", "label", "mod",
	"nil", "not", "object", "operator", "procedure", "program", "record",
	"set", "shl", "shr", "string", "true", "type", "unit", "uses", "var",
	"xor",
	// conditionals
	"and~", "break~", "case~", "continue~", "else~", "if~", "or~", "then~",
	// goto
	"goto#",
	// adapters
	"const^", "in^", "inline^", "of^", "on^", "packed^", "with^",
	// loops
	"for@", "while@", "do@", "downto@", "repeat@", "to@", "until@",
	NULL
};

#define PAS_syntax { \
	"Pascal", \
	PAS_extensions, \
	PAS_keywords, \
	"#", "{", "}", \
	HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS \
}

// MySQL, just the beginning
char *SQL_extensions[] = {".sql", NULL};
char *SQL_keywords[] = {
	"create", "insert", "from", "values", "select", "alter", "orderby",
	"table~", "database~", "column~",
	"asc@", "desc@",
	NULL
};

#define SQL_syntax { \
	"SQL", \
	SQL_extensions, \
	SQL_keywords, \
	"--", "/*", "*/", \
	HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS \
}

// Java
char *JAVA_extensions[] = {".java", NULL};
char *JAVA_keywords[] = {
	// types and misc
	"boolean", "double", "byte", "int", "short", "char", "long", "float",
	"continue", "break", "class", "enum", "import", "package", "super",
	// conditionals
	"switch~", "if~", "throw~", "else~", "throws~", "case~", "try~", "catch~",
	"finally~", "default~", "assert~", "instanceof~",
	// return
	"return#", "goto#",
	// adapters
	"const^", "abstract^", "new^", "public^", "protected^", "private^", "final^",
	"this^", "static^", "void^", "volatile^", "interface^", "implements^",
	"extends^", "synchronized^", "native^", "strictfp^", "transient^",
	// loops
	"for@", "while@", "do@",
	NULL
};

#define JAVA_syntax { \
	"Java", \
	JAVA_extensions, \
	JAVA_keywords, \
	"//", "/*", "*/", \
	HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS \
}

// Javascript
char *JAVASCRIPT_extensions[] = {".js",NULL};
char *JAVASCRIPT_keywords[] = {
	// types and misc
	"boolean", "double", "byte", "int", "short", "char", "long", "float", "var", "null", "true",
	"continue", "break", "class", "enum", "import", "export", "package", "super", "false", "let",
	"function", "with", "default", "yield", "delete",
	// conditionals
	"switch~", "if~", "throw~", "else~", "throws~", "case~", "try~", "catch~",
	"finally~", "default~", "instanceof~", "typeof~",
	// return
	"return#", "goto#", "in#",
	// adapters
	"const^", "abstract^", "new^", "public^", "protected^", "private^", "final^",
	"this^", "static^", "void^", "volatile^", "interface^", "implements^",
	"extends^", "synchronized^", "native^", "transient^", "const^", "debugger^",
	// loops
	"for@", "while@", "do@", "each@",
	NULL
};

#define JAVASCRIPT_syntax { \
	"Javascript", \
	JAVASCRIPT_extensions, \
	JAVASCRIPT_keywords, \
	"//", "/*", "*/", \
	HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS \
}

// Go
char *GO_extensions[] = {".go", NULL};
char *GO_keywords[] = {
	// types and misc
	"bool", "byte", "int", "int8", "float32", "float64", "uint16", "uint32", "uint64",
	"complex128", "complex64", "var", "null", "true", "false", "break", "import",
	"package", "const", "float32", "float64", "rune", "string", "uintptr", "func",
	// conditionals
	"switch~", "if~", "else~", "case~", "default~",
	// return
	"return#", "goto#",
	// loops
	"for@",
	NULL
};

#define GO_syntax { \
	"Go", \
	GO_extensions, \
	GO_keywords, \
	"//", "/*", "*/", \
	HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS \
}

// Ruby
char *RUBY_extensions[] = {".rb", NULL};
char *RUBY_keywords[] = {
	// data types
	"true", "false", "nil",
	// properties of the current source file.
	"__ENCODING__|", "__LINE__|",  "__FILE__|",
	// conditionals
	"if~", "else~", "elsif~", "case~", "break~", "ensure~", "begin~", "rescue~",
	"then~", "when~",
	// return
	"return#", "in#", "self#",
	// loops
	"for@", "do@", "while@", "until@",
	// misc
	"and^", "or^", "yield^", "not^", "class^", "BEGIN^", "END^", "alias^",
	"redo^", "module^", "super^", "def^", "end^", "retry^", "undef^",
	"unless^", "next^", "defined?^",
	NULL
};

#define RUBY_syntax { \
	"Ruby", \
	RUBY_extensions, \
	RUBY_keywords, \
	"#", "=begin", "=end", \
	HL_HIGHLIGHT_STRINGS | HL_HIGHLIGHT_NUMBERS \
}

// Rust
char *RUST_extensions[] = {".rs", ".rlib", NULL};
char *RUST_keywords[] = {
	// types and misc
	"str", "bool", "char", "i8", "i16", "i32", "i64", "u8", "u16", "u32", "u64",
	"isize", "usize", "f32", "f64", "struct", "enum", "true", "false",
	// cargo stuff
	"extern|", "crate|", "use|", "mod|", "super|",
	// conditionals
	"if~", "else~", "match~", "Ok~", "Some~", "Result~",
	// loops
	"loop#", "while#", "for#", "break#", "continue#", "do#",
	// modifiers and adapters
	"mut^", "const^", "pub^", "self^", "virtual^", "Self^",
	// other misc
	"type", "typeof", "sizeof", "move", "box", "become", "macro", "final", "as", "abstract",
	"alignof", "macro", "offsetof", "override", "priv", "proc", "pure", "ref",
	"where", "unsafe", "unsized", "let", "in",
	// function stuff
	"fn@", "yield@", "trait@", "impl@",
	NULL
};

#define RUST_syntax { \
	"Rust", \
	RUST_extensions, \
	RUST_keywords, \
	"//", "/*", "*/", \
	HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS \
}

//html
char *HTML_extensions[] = {".html", ".htm", NULL};
char *HTML_keywords[] = {
	// scrapped from www.fillster.com/htmlcodes/ using python lxml and requests
	// then c processing
	// start tokens:
	"<a>", "<abbr>", "<acronym>", "<address>", "<applet>", "<area>", "<b>",
	"<base>", "<basefont>", "<bdo>", "<bgsound>", "<big>", "<blockquote>",
	"<blink>", "<body>", "<br>", "<button>", "<caption>", "<center>", "<cite>",
	"<code>", "<col>", "<colgroup>", "<dd>", "<dfn>", "<del>", "<dir>", "<dl>",
	"<div>", "<dt>", "<embed>", "<em>", "<fieldset>", "<font>", "<form>",
	"<frame>", "<frameset>", "<h1> - <h6>", "<head>", "<hr>", "<html>",
	"<iframe>", "<img>", "<input>", "<ins>" , "<isindex>", "<i>", "<kbd>",
	"<label>", "<legend>", "<li>", "<link>", "<marquee>", "<menu>", "<meta>",
	"<noframe>", "<noscript>", "<optgroup>", "<option>", "<ol>", "<p>", "<pre>",
	"<q>", "<s>", "<samp>", "<script>", "<select>", "<small>", "<span>",
	"<strike>", "<strong>", "<style>", "<sub>", "<sup>", "<table>", "<td>",
	"<th>", "<tr>", "<tbody>", "<textarea>", "<tfoot>", "<thead>", "<title>",
	"<tt>", "<u>", "<ul>", "<var>",
	// end tokens:
	"</a>", "</abbr>", "</acronym>", "</address>", "</applet>", "</area>",
	"</b>", "</base>", "</basefont>", "</bdo>", "</bgsound>", "</big>",
	"</blockquote>", "</blink>", "</body>", "</br>", "</button>",
	"</caption>", "</center>", "</cite>", "</code>", "</col>", "</colgroup>",
	"</dd>", "</dfn>", "</del>", "</dir>", "</dl>", "</div>", "</dt>",
	"</embed>", "</em>", "</fieldset>", "</font>", "</form>", "</frame>",
	"</frameset>", "</h1> - <h6>", "</head>", "</hr>", "</html>", "</iframe>",
	"</img>", "</input>", "</ins>", "</isindex>", "</i>", "</kbd>",
	"</label>", "</legend>", "</li>", "</link>", "</marquee>", "</menu>",
	"</meta>", "</noframe>", "</noscript>", "</optgroup>", "</option>",
	"</ol>", "</p>", "</pre>", "</q>", "</s>", "</samp>", "</script>",
	"</select>", "</small>", "</span>", "</strike>", "</strong>", "</style>",
	"</sub>", "</sup>", "</table>", "</td>", "</th>", "</tr>", "</tbody>",
	"</textarea>", "</tfoot>", "</thead>", "</title>", "</tt>", "</u>",
	"</ul>", "</var>",
	// start tokens (HTML5 only):
	"<article>", "<aside>", "<bdi>", "<details>", "<dialog>", "<figcaption>",
	"<figure>", "<footer>", "<header>", "<main>", "<mark>", "<menuitem>",
	"<meter>", "<nav>", "<progress>", "<rp>", "<rt>", "<ruby>", "<section>",
	"<summary>", "<time>", "<wbr>",
	// end tokens (HTML5 only):
	"</article>", "</aside>", "</bdi>", "</details>", "</dialog>",
	"</figcaption>", "</figure>", "</footer>", "</header>", "</main>", "</mark>",
	"</menuitem>", "</meter>", "</nav>", "</progress>", "</rp>", "</rt>",
	"</ruby>", "</section>", "</summary>", "</time>", "</wbr>"
};

#define HTML_syntax { \
	"HTML", \
	HTML_extensions, \
	HTML_keywords, \
	"//", "<!--", "-->", \
	HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS \
}

// D
char *D_extensions[] = {".d", NULL};
char *D_keywords[] = {
    // types and misc
    "inout", "shared", "bool", "byte", "ubyte", "short", "ushort", "int",
    "uint", "long", "ulong", "char", "wchar", "dchar", "float", "double",
    "real", "ifloat", "idouble", "ireal", "cfloat", "cdouble", "creal",
    "typeof", "true", "false", "this", "super", "null", "is", "struct",
    "union", "class", "enum", "ref", "delegate", "function", "string",
    "__vector", "new", "delete", "cast", "mixin", "import", "__traits",
    "default", "with", "finally", "asm", "scope", "auto", "extern",
    "shared", "__gshared", "nothrow", "pure", "lazy", "in", "invariant",
    "out", "body", "unittest", "template", "alias", "pragma",
    // property identifiers
    "@property", "@safe", "@trusted", "@system", "@disable", "@nogc",
    // conditionals
    "if~", "else~", "switch~", "case~", "try~", "throw~", "catch~", "version~",
    "debug~",
    // return
    "return#", "goto#",
    // adapters
    "const^", "immutable^", "inout^", "shared^", "static^", "public^",
    "protected^", "private^", "void^", "typedef^", "union^", "virtual^",
    "volatile^", "final^", "deprecated^", "synchronized^", "override^",
    "interface^", "export^", "package^", "abstract^",
    // loops
    "for@", "foreach@", "foreach_reserve@", "while@", "do@",
    NULL
};

#define D_syntax { \
	"D", \
	D_extensions, \
	D_keywords, \
	"//", "/*", "*/", \
	HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS \
}

// Brainfuck
char *BRAIN_extensions[] = {".brain", ".b", NULL};
char *BRAIN_keywords[] = {
    "+", "-", "#", ".", ",", ">", "<", "*", "[", "]", "{", "}",
    "$", "/", "%", "!", "?", ":", ";", "^", NULL
};

// Anything else than those keywords are considered comments in BRAIN.

#define BRAIN_syntax { \
	"Brainfuck", \
	BRAIN_extensions, \
	BRAIN_keywords, \
	"", "", "", \
	HL_HIGHLIGHT_STRINGS \
}

// Bash
char *BASH_extensions[] = {".sh", NULL};
char *BASH_keywords[] = {
	// misc	
	"function", "select", "read", "echo", "break",
	"export", "let", "clear", "exit",
	"!", ";;", "|", ">", ">>", "<<", "<", "&",
	// conditionals
	"if~", "elif~", "else~", "fi~",  "case~", "esac~", "then~",
	// return
	"return#",
	// loops
	"for@", "while@", "until@", "in@", "do@", "done@",
	NULL
};

#define BASH_syntax { \
	"Bash", \
	BASH_extensions, \
	BASH_keywords, \
	"#", "#", "#", \
	HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS \
}

// Makefile
char *MAKEFILE_extensions[] = {"Makefile", NULL};
char *MAKEFILE_keywords[] = {
	// misc
	"$(CC)@", "CC@", "$(CFLAGS)@", "CFLAGS@", "$(MAKE)@",
	// stuff
	".PHONY:", "export",
	// basic rules
	"all:~", "clean:~", "install:~",
	NULL
};

#define MAKEFILE_syntax { \
	"Makefile", \
	MAKEFILE_extensions, \
	MAKEFILE_keywords, \
	"#", "#", "#", \
	HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS \
}

struct editorSyntax HLDB[] = {
	CCPP_syntax,
	CSHARP_syntax,
	PYTHON_syntax,
	PHP_syntax,
	PAS_syntax,
	SQL_syntax,
	JAVA_syntax,
	JAVASCRIPT_syntax,
	GO_syntax,
	RUBY_syntax,
	RUST_syntax,
	HTML_syntax,
	D_syntax,
	BRAIN_syntax,
	BASH_syntax,
	MAKEFILE_syntax
};

#define HLDB_ENTRIES (sizeof(HLDB) / sizeof(HLDB[0]))

#endif
