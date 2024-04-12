#include "Score.h"

Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}

// Score:: Score(Score* _score): score(_score->score) , detail(_score->detail) , label(_score->label){
// 	// this->score = _score->score;
// 	// this->detail = _score->detail;
// 	// this->label = _score->label;

// 	ID_generator++;
// }

Score& Score::operator = (const Score& _score){
	if(this != &score){
		this->score = _score.score;
		this->label = _score.label;
		this->detail = _score.detail;
	}
	return *this;
}
