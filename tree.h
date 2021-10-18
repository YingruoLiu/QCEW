#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include "scanType.h"
//#include "parser.tab.h"
//#include "semantic.h"                                                                                                                                                                                  

typedef enum {USNMS, USMSA, USCMS, CS, C, county} subKind; 

#define MAXCHILDREN 3
static int indent = 0;

typedef struct ASTNode{

  // connectivity in the tree                                                                                                                                                                            
  struct ASTNode *child[MAXCHILDREN];   // children of the node                                                                                                                                          
  struct ASTNode *sibling;              // siblings for the node                                                                                                                                         
  // what kind of node                                                                                                                                                                                   
  int lineno;                            // linenum relevant to this node                                                                                                                                
  int nvalue; //for number value                                                                                                                                                                         
  int value;
  subKind nodeKind;
  // extra properties about the node depending on type of the node                                                                                                                                       
  union                                  // relevant data to type -> attr                                                                                                                                
  {
    int countryCode;     //stores the country code
  } attr;

  bool isMetro;                          // is this place metro                                             
  char *CSACode;
  char *CSATitle;
  char *MSACode;
  char *MSATitle;

}astNode;

astNode * addCS(char * info);
astNode * addC(char * info);
astNode * addCounty(char * info);
astNode * addUSCMS(char * info);
astNode * addUSNMA(char * info);
void printTree(astNode * tree);
void printCS(astNode *tree);
void printC(astNode *tree);
void printUSNMA(astNode *tree);
void printUSNMS(astNode * tree);



