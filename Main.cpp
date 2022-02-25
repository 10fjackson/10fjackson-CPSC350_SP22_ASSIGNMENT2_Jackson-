#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"
#include <iostream>
using namespace std;

int main(){
  //FileProcessor *sb = new FileProcessor();
  //sb->processFile("output.txt");
  //Translator *t = new Translator();
  //cout<< t -> translateTutWord("wacklulkuck")<< endl;
  Model *m = new Model();
  cout<< m -> skipChars(tolower('t'))<< endl;
  delete m;
  return 0;
}
