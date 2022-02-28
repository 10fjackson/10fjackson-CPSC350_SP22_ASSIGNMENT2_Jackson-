#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"
#include <iostream>
using namespace std;

int main(){
  FileProcessor *sb = new FileProcessor();
  string input;
  cout<<"Would you like to translate an English or Tutnese file?"<<endl;
  cin>>input;
  if(input == "Tutnese" || input == "tutnese"){
    sb->processTutFile("output.txt");
  }
  else if(input == "English" || input == "english"){
    sb->processFile("output.txt");
  }
  else{
    cout<<"Please enter 'tutnese' or 'english'"<<endl;
  }
  //cout<< t -> translateTutSentence("Afuftuterug asquatenundudinungug tuthashe gugalula, I wackenuntut hashomume anundud wackenuntut tuto suslulsquatepub.") << endl;
  //cout<< t -> translateTutSentence("Lularugguge pubosquale Lularugguge.") << endl;
  //Model *m = new Model();
  //cout<< m -> skipChars(tolower('t'))<< endl;
  delete sb;
  return 0;
}
