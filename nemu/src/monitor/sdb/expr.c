/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256, TK_NUM, TK_EQ,

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */
  {"[0-9]+", TK_NUM},   // dec
  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"-", '-'},		// minus
  {"\\*", '*'}, 	// multiple
  {"/", '/'}, 		// divide
  {"\\(", '('},		// par1
  {"\\)", ')'},		// par2
  {"==", TK_EQ},        // equal
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
        	case '+':
        	case '-':
        	case '*':
        	case '/':
        	case '(':
        	case ')':
        	case TK_NUM:
        		tokens[nr_token].type=rules[i].token_type;
        		tokens[nr_token].str[substr_len] = '\0';
        		strncpy(tokens[nr_token++].str, substr_start, substr_len);
        		break;
        	case TK_NOTYPE:
        		break;
          default: TODO();
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}


int check_parentheses(){
  
}


int searchmo(int p, int q){
  int j = 0;
  int judge = 0;
  int sign = 0;
  for(j = p; j <= q; j++)
  {
  	if(tokens[j].type == '('){
  		judge++;
  	}else if(tokens[j].type == ')'){
  		judge--;
  	}else if(tokens[j].type == TK_NUM){
  		continue;
  	}else if(judge != 0){
  		continue;
  	}else if(tokens[j].type == '+'){
  		sign = 1;
  		*optype = "+";
  		return p;
  	}else if(tokens[j].type == '-'){
  		sign = 1;
  		*optype = "-";
  		return p;
  	}else if(sign == 0 && tokens[j].type == '*'){
  		sign = 0;
  		*optype = "*";
  		return p;
  	}else if(sign == 0 && tokens[j].type == '/'){
  		sign = 0;
  		*optype = "/";
  		return p;
  	}
  }	
}
int eval(int p, int q){
  int value_1 = 0;
  int value_2 = 0;
  
  if(p > q) {
  	/*bad expression*/
  	return 0;
  }
  else if(p == q) {
  	/*single number*/
  	
  }
  else if(check_parentheses(p, q) == true) {
  	/*a pair of parentheses surround the expression*/
  	return eval(p+1, q-1);
  }else{
  	char op;
  	char *optype;
  	op = searchmo(p, q);
	value_1 = eval(p, op-1);
	value_2 = eval(op+1, q);
	switch (*optype){
	
	}
  }
}
word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  char aaa = tokens[0].str[0];
  return aaa;
  /* TODO: Insert codes to evaluate the expression. */
  TODO();
  
  return 0;
}
