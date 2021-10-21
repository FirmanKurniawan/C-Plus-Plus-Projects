#include<time.h>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
class Generator{
	public :
	   void key(int lengthKey,bool numberOnlyOption){
	   		std::string result="";
	   	    	std::string numberCharacters="1234567890";
		    	std::string lowerCharacters="abcdefghijklmnopqrstuvwxyz";
		    	std::string upperCharacters="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		    	std::string allCharacters=lowerCharacters+numberCharacters+upperCharacters;
			srand(time(0));
			if(numberOnlyOption){
				for(int i=0;i<lengthKey;i++){
					result+=numberCharacters[rand()%(numberCharacters.length())];
				}
			}else{
				for(int i=0;i<lengthKey;i++){
					result+=allCharacters[rand()%(allCharacters.length())];
				}
			}std::cout<<result<<std::endl;
		}
};
int main(int argc,char** argv){
	Generator gen;
	if( (std::strcmp(argv[1],"-L")==0)||(std::strcmp(argv[1],"--length")==0) ){
		if((std::strcmp(argv[3],"-ON")==0)||(std::strcmp(argv[3],"--only-number")==0) ){
			gen.key(std::atoi(argv[2]), true);
		}else if((std::strcmp(argv[3],"-A")==0)||(std::strcmp(argv[3],"--all")==0) ){
			gen.key(std::atoi(argv[2]), false);
		}
	}else{
		std::cout<<"psswdgen [ -L | --length ] [NUMBER] [ -ON | --only-number ]";
	}return 0;
}
