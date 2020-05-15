#include <iostream>

//declaration
class MonthAndDay {
private:
    int month;
    int day;
    void checkDate(); //check if the date is valid.
public:
    MonthAndDay(); // overload constructor with no argument condition  //note: no return value not even void
    MonthAndDay(int monthValue); //overload 1 int condition
    MonthAndDay(int monthValue, int dayValue); //overload 2 int condition
    void output();  //note: require return value such as void
};

//implementation
MonthAndDay::MonthAndDay() { //if no arg. set to Jan 1.
    month = 1;
    day = 1;
    //checkDate(); don't need, we know it is valid.
}
MonthAndDay::MonthAndDay(int monthValue){
    month = monthValue;
    day = 1;
    checkDate();
}
MonthAndDay::MonthAndDay(int monthValue, int dayValue) : month(monthValue), day(dayValue){
    //can directly set the values after the : symbol
    checkDate();
}
void MonthAndDay::checkDate(){
    if((month < 1) || (month > 12)){
        std::cout<<"Illegal month value!\n";
    }
    if((day < 1) || (day > 31)){
        std::cout<<"Illegal day value!\n";
    }
    //of course, a better way is
    //to check day depending on month, e.g., no Feb.30.
}
void MonthAndDay::output(){
    std::cout<<"Month: "<<month<<", Day: "<<day<<std::endl;
}


//main function
int main() {
    MonthAndDay date1; // call default constructor, don't use ()
    MonthAndDay date2(5);
    MonthAndDay date3(2,21);
    date1.output();
    date2.output();
    date3.output();

    //date1.MonthAndDay();  //ILLEGAL!

    MonthAndDay date4(12,33);
    MonthAndDay date5(-1,99);

    return 0;
}
