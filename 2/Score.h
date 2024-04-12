#include <iostream>
#include <string>
using namespace std;
class Score {
public:
	friend void print(const Score& score);

	typedef enum {
		GREAT,
		GOOD,
		NOTBAD,
		BAD,
	}Label;

	Score() : ID(Score::ID_generator), score(0), detail(""), label(GOOD) {}
	Score(int score, char* detail, Label label);
	Score(Score* _score);
	~Score() {}
	static void setID_generator(int _id);
	void set_score(int _score);
	void set_label(Label _label);
	void set_detail(string _detail);
	int get_score();
	//Label get_label();
	string get_detail();
	friend int main();
	Score& operator = (const Score& _score);
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};

static int ID_generator = 0;



