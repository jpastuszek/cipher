/* C code produced by gperf version 3.0.1 */
/* Command-line: gperf -C -p -j1 -i 1 -g -o -t -N rb_reserved_word -k'1,3,$' keywords  */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 1 "keywords"
struct kwtable {char *name; int id[2]; enum lex_state_e state;};
const struct kwtable *rb_reserved_word _((const char *, unsigned int));
#ifndef RIPPER

#define TOTAL_KEYWORDS 40
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 8
#define MIN_HASH_VALUE 6
#define MAX_HASH_VALUE 50
/* maximum key range = 45, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash (str, len)
     register const char *str;
     register unsigned int len;
{
  static const unsigned char asso_values[] =
    {
      51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 23, 51, 51, 13, 51,  1,  1,
      11, 12, 51, 51, 51, 51, 10, 51, 12, 51,
      51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 51, 51, 11, 51, 13,  1, 26,
       4,  1,  8, 28, 51, 23, 51,  1,  1, 27,
       5, 19, 21, 51,  8,  3,  3, 11, 51, 21,
      24, 16, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
      51, 51, 51, 51, 51, 51
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[2]];
      /*FALLTHROUGH*/
      case 2:
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval + asso_values[(unsigned char)str[len - 1]];
}

#ifdef __GNUC__
__inline
#endif
const struct kwtable *
rb_reserved_word (str, len)
     register const char *str;
     register unsigned int len;
{
  static const struct kwtable wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""},
#line 9 "keywords"
      {"END", {keyword_END, keyword_END}, EXPR_END},
      {""},
#line 13 "keywords"
      {"break", {keyword_break, keyword_break}, EXPR_MID},
#line 19 "keywords"
      {"else", {keyword_else, keyword_else}, EXPR_BEG},
#line 29 "keywords"
      {"nil", {keyword_nil, keyword_nil}, EXPR_END},
#line 22 "keywords"
      {"ensure", {keyword_ensure, keyword_ensure}, EXPR_BEG},
#line 21 "keywords"
      {"end", {keyword_end, keyword_end}, EXPR_END},
#line 38 "keywords"
      {"then", {keyword_then, keyword_then}, EXPR_BEG},
#line 30 "keywords"
      {"not", {keyword_not, keyword_not}, EXPR_VALUE},
#line 23 "keywords"
      {"false", {keyword_false, keyword_false}, EXPR_END},
#line 36 "keywords"
      {"self", {keyword_self, keyword_self}, EXPR_END},
#line 20 "keywords"
      {"elsif", {keyword_elsif, keyword_elsif}, EXPR_VALUE},
#line 33 "keywords"
      {"rescue", {keyword_rescue, modifier_rescue}, EXPR_MID},
#line 39 "keywords"
      {"true", {keyword_true, keyword_true}, EXPR_END},
#line 42 "keywords"
      {"until", {keyword_until, modifier_until}, EXPR_VALUE},
#line 41 "keywords"
      {"unless", {keyword_unless, modifier_unless}, EXPR_VALUE},
#line 35 "keywords"
      {"return", {keyword_return, keyword_return}, EXPR_MID},
#line 16 "keywords"
      {"def", {keyword_def, keyword_def}, EXPR_FNAME},
#line 11 "keywords"
      {"and", {keyword_and, keyword_and}, EXPR_VALUE},
#line 18 "keywords"
      {"do", {keyword_do, keyword_do}, EXPR_BEG},
#line 45 "keywords"
      {"yield", {keyword_yield, keyword_yield}, EXPR_ARG},
#line 24 "keywords"
      {"for", {keyword_for, keyword_for}, EXPR_VALUE},
#line 40 "keywords"
      {"undef", {keyword_undef, keyword_undef}, EXPR_FNAME},
#line 31 "keywords"
      {"or", {keyword_or, keyword_or}, EXPR_VALUE},
#line 26 "keywords"
      {"in", {keyword_in, keyword_in}, EXPR_VALUE},
#line 43 "keywords"
      {"when", {keyword_when, keyword_when}, EXPR_VALUE},
#line 34 "keywords"
      {"retry", {keyword_retry, keyword_retry}, EXPR_END},
#line 25 "keywords"
      {"if", {keyword_if, modifier_if}, EXPR_VALUE},
#line 14 "keywords"
      {"case", {keyword_case, keyword_case}, EXPR_VALUE},
#line 32 "keywords"
      {"redo", {keyword_redo, keyword_redo}, EXPR_END},
#line 28 "keywords"
      {"next", {keyword_next, keyword_next}, EXPR_MID},
#line 37 "keywords"
      {"super", {keyword_super, keyword_super}, EXPR_ARG},
#line 27 "keywords"
      {"module", {keyword_module, keyword_module}, EXPR_VALUE},
#line 12 "keywords"
      {"begin", {keyword_begin, keyword_begin}, EXPR_BEG},
#line 6 "keywords"
      {"__LINE__", {keyword__LINE__, keyword__LINE__}, EXPR_END},
#line 7 "keywords"
      {"__FILE__", {keyword__FILE__, keyword__FILE__}, EXPR_END},
#line 8 "keywords"
      {"BEGIN", {keyword_BEGIN, keyword_BEGIN}, EXPR_END},
#line 17 "keywords"
      {"defined?", {keyword_defined, keyword_defined}, EXPR_ARG},
#line 10 "keywords"
      {"alias", {keyword_alias, keyword_alias}, EXPR_FNAME},
      {""}, {""},
#line 15 "keywords"
      {"class", {keyword_class, keyword_class}, EXPR_CLASS},
      {""}, {""},
#line 44 "keywords"
      {"while", {keyword_while, modifier_while}, EXPR_VALUE}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
#line 46 "keywords"

#endif
