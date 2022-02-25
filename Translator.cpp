#include "Translator.h"
#include "Model.h"
#include <iostream>
#include <cctype>
using namespace std;

Translator::Translator(){

}
Translator::~Translator(){

}
string Translator::translateEnglishWord(string eng){
  Model *m = new Model;
  string translation = "";
  for(int i = 0; i < eng.length();++i){
    if(eng[i] == eng[i+1]){
      translation += m -> translateDoubleCharacter(eng[i]);
      translation += eng[i];
      i++;
    }
    else{
      translation += m -> translateSingleCharacter(eng[i]);
    }
  }
  delete m;
  return translation;
}
string Translator::translateEnglishSentence(string sentence){
  string translation = "";
  string word = "";
  //Translator *t = new Translator;
  for(int i = 0; i < sentence.length(); ++i){
    while(sentence[i] != ' ' && sentence[i] != ',' && sentence[i] != '.' && sentence[i] != '!' && sentence[i] != '?' && sentence[i] != ';'){
      word += sentence[i];
      i++;
    }
    translation += translateEnglishWord(word);
    translation += sentence[i];
    word = "";
  }
  //delete m;
  return translation;
}

//Translation from tutnese to english
string Translator::translateTutWord(string tut){
  Model *m = new Model;
  string translation = "";
  for(int i = 0; i < tut.length();++i){
    translation += tut[i];
    i += m -> skipChars(tolower(tut[i]));
  }
  delete m;
  return translation;
}
//string translateTutSentence(string tutSentence){

//}
