//20212861 이재민 

class Time
{
    public:
        void readTime(bool &errorFlag);
        int subtractTimes(Time t);
        void addTimes(Time t, int avgTime);

    private:
        int minutes;
};