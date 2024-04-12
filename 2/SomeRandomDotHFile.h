#include "Score.h"
void Score::setID_generator(int _id) {
    ID_generator = _id;
}
void Score::set_score(int _score) {
    score = _score;
}
void Score::set_label(Label _label) {
    label = _label;
}
void Score::set_detail(string _detail) {
    detail = _detail;
}
int Score::get_score() {
    return score;
}
// Label Score:: get_label(){
//     return label;
// }
string Score::get_detail() {
    return detail;
}