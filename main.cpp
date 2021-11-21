#include<stdio.h>
#include<string.h>
#include<sys/file.h>

int main() {

        FILE *fp;  //file pointer
        fp = fopen("postfixExp.dat", "r"); //file containing a postfix expression

        char letterA;
		letterA = 'A';
		
        char letterZ;
		letterZ = 'Z';
		
        char lowerA;
		lowerA = 'a';
		
        char lowerZ;
		lowerZ = 'z';
		
		char digit0 = '0';
		char digit9 = '9';
		
		
        char str[] = "I like to program c++"; //what?????????
        char *parsed_str;
        char *strtok (char *str, const char *delimiters);

        while (fscanf(fp, "%s", &str) != EOF) {
                printf("\n\tParsing string: \"%s\"  into tokens: \n", str);
                parsed_str = strtok(str, "_"); /* delimiter characters, may vary */  //seperates each word after each _
                
				bool invalidGrammar = false;
				
                while (parsed_str != '\0') /*Use '\0' as the NULL string terminating char*/
            	{
            		char *iter;
        			bool isVariable = true;
        			bool isConst = true;
        			bool isOperator = true;
        			
        			
                    printf("%s --------- ", parsed_str);
                    
					for (iter = parsed_str; *iter != '\0'; iter++) {
						if ((letterA > *iter || *iter > letterZ) && (lowerA > *iter || *iter > lowerZ)) { //is iter not in range of Cap A-Z
	                    	isVariable = false;                //AND is it not in lower a - z
						}	
					}//for
					
					
					//
					for (iter = parsed_str; *iter != '\0'; iter++) {						
						if (digit0 > *iter || *iter > digit9) { // Checking if iter is not a digit 
	                    	
	                    	if (*iter == '.') { //Once we get to period (.), we're going to check all the
	                    						//characters after the period
		                    	for (iter = iter + 1; *iter != '\0'; iter++) {	//Check to make sure these are only digits					
									if (digit0 > *iter || *iter > digit9) { // Checking if iter is not a digit	
										isConst = false;                
									}// inner if	
								}//inner for
								break;
							} //outer if
	                    	
							isConst = false;                
						}//outer if	
					}//outer for
					
					if ((*parsed_str != '+' && *parsed_str != '*' && *parsed_str != '-' && *parsed_str != '/') || (sizeof(*parsed_str) > 1 )) {
						isOperator = false;
					}
					
					if (isVariable) {
						printf("variable\n");
					}
					
					else if (isConst) {
						printf("const\n");
					}
					
					else if (isOperator) {
						printf("operator\n");
					}
					
					else {
						printf("Invalid lexeme!\n");
						invalidGrammar = true;
					}
	
					parsed_str = strtok('\0', "_"); /* print parsed tokens*/

                }
                
                if (invalidGrammar) {
                	printf("Expression is invalid!\n");
				}
                
        }

        fclose(fp);
return 0;
}


/* prototype char *strtok (char *str, const char *delimiters);
splits (parses) str into tokens (sequences of contiguous characters separated by
characters that are denoted as delimiters).     */
